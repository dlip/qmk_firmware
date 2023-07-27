// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define DEBOUNCE 10
#define NO_ACTION_TAPPING
#define COMBO_VARIABLE_LEN
// #define LEADER_PER_KEY_TIMING
// #define LEADER_TIMEOUT 1000

#define COMBO_TERM 80
#define COMBO_STRICT_TIMER
// #define COMBO_NO_TIMER
#define COMBO_MUST_HOLD_MODS

// #define TAP_CODE_DELAY 25
// #define TAPPING_FORCE_HOLD