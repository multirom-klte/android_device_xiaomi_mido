#include <stdlib.h>

// These are paths to folders in /sys which contain "uevent" file
// need to init this device.
// MultiROM needs to init framebuffer, mmc blocks, input devices,
// some ADB-related stuff and USB drives, if OTG is supported
// You can use * at the end to init this folder and all its subfolders
const char *mr_init_devices[] =
{
    // Framebuffer
    "/sys/class/graphics/fb0",

    // Storage Devices
    "/sys/block/mmcblk0",
    "/sys/block/sda*",
    "/sys/devices/soc/7824900.sdhci",
    "/sys/devices/soc/7824900.sdhci/mmc_host/mmc0",
    "/sys/devices/soc/7824900.sdhci/mmc_host/mmc0/mmc0:0001",
    "/sys/devices/soc/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0",
    "/sys/devices/soc/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p21", // boot
    "/sys/devices/soc/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p25", // cache
    "/sys/devices/soc/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p1",  // modem
    "/sys/devices/soc/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p26", // persist
    "/sys/devices/soc/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p24", // system
    "/sys/devices/soc/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p49", // userdata
    "/sys/bus/mmc*",
    "/sys/module/mmc_core",
    "/sys/module/mmcblk",

    // for input
    "/sys/devices/soc/soc:gpio_keys/input*", // Volume keys
    "/sys/devices/soc/soc:gpio_keys/input/input*",
    "/sys/devices/virtual/input*",
    "/sys/devices/virtual/input/input*",
    "/sys/devices/virtual/misc/uinput",
    "/sys/devices/soc/78b7000.i2c/i2c-3/3-0038/input*", // Touchscreen
    "/sys/devices/soc/78b7000.i2c/i2c-3/3-0038/input/input*",
    "/sys/module/uinput",
    "/sys/class/input/input*",
    "/sys/class/input/event*",
    "/sys/class/misc/uinput",

    // for adb
    "/sys/devices/virtual/tty/ptmx",
    "/sys/class/android_usb/android0*",\
    "/sys/bus/platform/drivers/android_usb",
    "/sys/bus/usb",

    // USB drive is in here
    "/sys/devices/platform/msm_hsusb*",

    // for qualcomm overlay - /dev/ion
    "/sys/devices/virtual/misc/ion",

    NULL
};
