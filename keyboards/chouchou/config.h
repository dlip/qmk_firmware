// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define DEBOUNCE 20
// #define COMBO_NO_TIMER
#define COMBO_TERM 80
 
 // 1000hz Polling Rate
#define USB_POLLING_INTERVAL_MS 1

// Joystick Button Count
#define JOYSTICK_BUTTON_COUNT 32

// Joystick Axes Count
#define JOYSTICK_AXIS_COUNT 6

// Joystick Axes Resolution
#define JOYSTICK_AXIS_RESOLUTION 8