// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <stdint.h>
#include "keyboard.h"

#include "keyboards/keebio/bfo9000/keymaps/mrcc/config.h"

// Function declarations
uint16_t keymap_key_to_keycode(uint8_t layer, keypos_t key);
uint16_t keycode_at_keymap_location(uint8_t layer, uint8_t row, uint8_t col);
