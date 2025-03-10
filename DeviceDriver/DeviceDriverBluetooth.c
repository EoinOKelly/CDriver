#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/hid.h>
#include <linux/usb.h>
#include <linux/device.h> 

#define BATTLE_BEEVER_VENDOR_ID  0x045E  // Example: Replace with actual vendor ID
#define BATTLE_BEEVER_PRODUCT_ID 0x02FD  // Example: Replace with actual product ID

static int battlebeaver_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
    int ret;

    dev_info(&hdev->dev, "Battle Beaver Xbox Controller connected\n");

    ret = hid_parse(hdev);
    if (ret) {
        dev_err(&hdev->dev, "HID parse failed\n");
        return ret;
    }

    ret = hid_hw_start(hdev, HID_CONNECT_HIDRAW);
    if (ret) {
        dev_err(&hdev->dev, "HID hardware start failed\n");
        return ret;
    }

    return 0;
}

static void battlebeaver_remove(struct hid_device *hdev)
{
    hid_hw_stop(hdev);
    dev_info(&hdev->dev, "Battle Beaver Xbox Controller disconnected\n");
}

static const struct hid_device_id battlebeaver_devices[] = {
    { HID_DEVICE(BUS_BLUETOOTH, HID_GROUP_GENERIC, BATTLE_BEEVER_VENDOR_ID, BATTLE_BEEVER_PRODUCT_ID) },
    { }
};
MODULE_DEVICE_TABLE(hid, battlebeaver_devices);

static struct hid_driver battlebeaver_driver = {
    .name = "battlebeaver",
    .id_table = battlebeaver_devices,
    .probe = battlebeaver_probe,
    .remove = battlebeaver_remove,
};

static int __init battlebeaver_init(void)
{
    return hid_register_driver(&battlebeaver_driver);
}

static void __exit battlebeaver_exit(void)
{
    hid_unregister_driver(&battlebeaver_driver);
}

module_init(battlebeaver_init);
module_exit(battlebeaver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Simple Bluetooth HID Driver for Battle Beaver Xbox Controller");
