#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define DEVICE_PATH "/dev/input/event27"  // Ensure this path is correct

// Function to execute system commands
void execute_command(const char *command) {
    pid_t pid = fork();
    if (pid == 0) { // Child process
        setsid();  // Ensure it runs independently
        printf("Executing command: %s\n", command); // Debugging line
        execl("/bin/sh", "sh", "-c", command, (char *)NULL);
        perror("execl failed");  // Print error if execl fails
        exit(1);
    } else if (pid > 0) {
        // No need to waitpid when running commands in the background
    } else {
        perror("fork failed");
    }
}

// Function to listen for Xbox controller inputs
void listen_for_input() {
    struct input_event ie;
    int fd = open(DEVICE_PATH, O_RDONLY);
    if (fd < 0) {
        perror("Error opening input device");
        exit(EXIT_FAILURE);
    }

    // Set the file descriptor to non-blocking mode
    fcntl(fd, F_SETFL, O_NONBLOCK);

    printf("Listening for Xbox controller inputs...\n");
    while (1) {
        ssize_t bytesRead = read(fd, &ie, sizeof(ie));
        if (bytesRead < 0) {
            if (errno != EAGAIN) {
                perror("Error reading input");
                break;
            }
            // No input to process, continue the loop
            usleep(10000);  // Sleep for a bit to prevent excessive CPU usage
            continue;
        }

        printf("Received event: type=%d, code=%d, value=%d\n", ie.type, ie.code, ie.value);

        // Only trigger on button press (EV_KEY)
        if (ie.type == EV_KEY && ie.value == 1) {  // Only trigger on key press (down)
            switch (ie.code) {
                case 304:  // A Button
                    printf("A button pressed! Opening terminal...\n");
                    fflush(stdout);
                    execute_command("gnome-terminal &");  
                    break;
                case 305:  // B Button
                    printf("B button pressed! Opening Firefox...\n");
                    fflush(stdout);
                    execute_command("firefox &");  
                    break;
                case 307:  // X Button
                    printf("\n\n#########################################\n");
                    printf("#   Welcome to my code presentation!   #\n");
                    printf("#########################################\n\n");
                    fflush(stdout);
                    break;
                case 308:  // Y Button
                    printf("Y button pressed! Playing text-to-speech...\n");
                    fflush(stdout);
                    execute_command("espeak 'Y button was pressed' &");  // Text-to-Speech
                    break;
                default:
                    printf("Button %d pressed\n", ie.code);
                    fflush(stdout);
                    break;
            }
        }
    }
    close(fd);
}

int main() {
    listen_for_input();
    return 0;
}
