#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DEVICE_PATH "/dev/input/event16"  // Change if necessary

void execute_command(const char *command) {
    pid_t pid = fork();
    if (pid == 0) { // Child process
        setsid();  // Ensure it runs independently
        execl("/bin/sh", "sh", "-c", command, (char *)NULL);
        perror("execl failed");  // Print error if execl fails
        exit(1);
    } else if (pid > 0) {
        waitpid(pid, NULL, WNOHANG);  // Prevent zombie processes
    } else {
        perror("fork failed");
    }
}

int main() {
    struct input_event ie;
    int fd = open(DEVICE_PATH, O_RDONLY);

    if (fd < 0) {
        perror("Error opening input device");
        return -1;
    }

    printf("Listening for Xbox controller inputs...\n");

    while (1) {
        read(fd, &ie, sizeof(ie));
        if (ie.type == EV_KEY && ie.value == 1) {  // Only trigger on button press
            switch (ie.code) {
                case 304:  // A Button
                    printf("A button pressed! Opening terminal...\n");
                    execute_command("gnome-terminal &");  
                    break;
                case 305:  // B Button
                    printf("B button pressed! Opening Firefox...\n");
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
                    execute_command("espeak 'Y button was pressed' &");  // Text-to-Speech
                    break;
                default:
                    printf("Button %d pressed\n", ie.code);
                    break;
            }
        }
    }

    close(fd);
    return 0;
}
