#
# Copyright (C) 2021 The Android Open Source Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Release name
PRODUCT_RELEASE_NAME := sakura


# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit_only.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/aosp_base.mk)

# Inherit from hardware-specific part of the product configuration
$(call inherit-product, device/xiaomi/sakura/device.mk)

# Inherit from our custom product configuration
$(call inherit-product, vendor/twrp/config/common.mk)

PRODUCT_PROPERTY_OVERRIDES += \
    ro.hardware.keystore=msm8953 \


PRODUCT_SYSTEM_PROPERTY_BLACKLIST += \
    ro.bootimage.build.date.utc \
    ro.build.date.utc

# Device identifier. This must come after all inclusions
PRODUCT_DEVICE := sakura
PRODUCT_NAME := twrp_sakura
PRODUCT_BRAND := Xiaomi
PRODUCT_MODEL := Redmi 6 pro
PRODUCT_MANUFACTURER := Xiaomi

