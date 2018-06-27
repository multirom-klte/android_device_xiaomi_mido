##==================================
##  RECOVERY_VARIANT := multirom
TARGET_RECOVERY_IS_MULTIROM := true

# Still needed by MultiROM Boot Menu
MR_PIXEL_FORMAT := "RGBX_8888"
MR_USE_QCOM_OVERLAY := true
MR_QCOM_OVERLAY_HEADER := device/xiaomi/mido/multirom/overlay/mr_qcom_overlay.h
MR_QCOM_OVERLAY_CUSTOM_PIXEL_FORMAT := MDP_RGBX_8888
RECOVERY_GRAPHICS_USE_LINELENGTH := true
NEW_ION_HEAP := true
MR_QCOM_OVERLAY_HEAP_ID_MASK := 1

# Custom Flags
MR_NO_KEXEC := true
MR_DEVICE_SPECIFIC_VERSION := x
TW_THEME := portrait_hdpi

include device/xiaomi/mido/multirom/version-info/MR_REC_VERSION.mk

ifeq ($(MR_REC_VERSION),)
MR_REC_VERSION := $(shell date -u +%Y%m%d)-01
endif

BOARD_MKBOOTIMG_ARGS += --board mrom$(MR_REC_VERSION)

# MultiROM config
MR_INPUT_TYPE := type_b
MR_INIT_DEVICES := device/xiaomi/mido/multirom/mr_init_devices.c
MR_DPI := xhdpi
MR_DPI_FONT := 340
MR_CONTINUOUS_FB_UPDATE := true

MR_DEVICE_HOOKS := device/xiaomi/mido/multirom/mr_hooks.c
MR_DEVICE_HOOKS_VER := 3 

#MR_ENCRYPTION := true

MR_FSTAB := device/xiaomi/mido/multirom/mrom.fstab
MR_USE_MROM_FSTAB := true
MR_DEV_BLOCK_BOOTDEVICE := true

MR_DEVICE_VARIANTS := mido

# not just yet :(
MR_KEXEC_MEM_MIN := 0x84A00000
MR_KEXEC_DTB := true

#Force populating /dev/block/platform/soc/7824900.sdhci/by-name/
#from the emmc
#MR_POPULATE_BY_NAME_PATH := "/dev/block/platform/soc/7824900.sdhci/by-name/"
