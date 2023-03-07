/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// place overrides here
// #undef DEBOUNCE
// #define DEBOUNCE 50

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY
#define LONG_TAPPING_TERM 1000
// #define PERMISSIVE_HOLD
// #define IGNORE_MOD_TAP_INTERRUPT
// #define TAPPING_FORCE_HOLD

#define MOUSEKEY_DELAY             0
#define MOUSEKEY_INTERVAL          20
#define MOUSEKEY_MAX_SPEED         10

#define MASTER_LEFT

// #define UNICODE_SELECTED_MODES UC_MAC
