#include QMK_KEYBOARD_H
#include "config.h"

#define NUM_KEYMAP_LAYERS_RAW ((uint8_t)(sizeof(mode1_keymaps) / ((MATRIX_ROWS) * (MATRIX_COLS) * sizeof(uint16_t))))


#ifndef TAPPING_TERM
#    define TAPPING_TERM 200
#endif

uint16_t user_key_timer;


keymap_mode_t current_mode = MODE_1;

enum custom_keycodes {
    KC_MODE1 = SAFE_RANGE,
    KC_MODE2,
    // Add more custom keycodes if needed
};


/* OSX */

const uint16_t PROGMEM mode1_keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[1] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[2] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[3] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[4] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[5] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[6] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[7] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[8] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[9] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[10] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[11] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[12] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[13] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[14] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[15] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[16] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[17] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[18] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[19] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),


		[20] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_7, 	  		KC_8, 			KC_9,   	  	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_4, 	  		KC_5, 			KC_6,   	   	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_1, 	  		KC_2, 			KC_3, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	KC_TRNS, 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[21] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[22] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),



};


const uint16_t PROGMEM mode2_keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),				KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_1, 			KC_2, 				KC_3, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_4, 			KC_5, 				KC_6, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

			[1] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[2] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[3] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[4] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[5] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[6] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[7] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[8] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[9] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[10] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[11] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[12] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[13] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[14] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[15] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[16] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[17] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[18] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[19] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),


		[20] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	KC_TRNS, 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[21] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),

		[22] = LAYOUT(
		KC_ESC, 			KC_MODE1,			KC_MODE2,		KC_F3, 				KC_F4, 					KC_F5,   		KC_F6, 			KC_F7,    		KC_F8, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 		 		KC_1, 				KC_2, 			KC_3, 				KC_4, 					KC_5, 	  		KC_5, 			KC_7, 	     	LCAG(KC_F12),					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		TO(0), 	 			MO(31), 			KC_Q, 			KC_W, 				KC_E, 					KC_R, 	  		KC_R, 			KC_BSPC,     	MO(22), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		KC_NO, 			    KC_TAB, 			KC_A, 			KC_S, 				KC_D, 		 			KC_F, 	  		KC_F, 			KC_ENT,      	MO(23), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(22),				KC_LSFT,	 		KC_Z, 			KC_X, 				KC_C, 					KC_V, 	  		KC_V, 			KC_N, 	     	KC_NO, 							KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO, 
		MO(20), 	 		KC_LCTL,			MO(24),			KC_LALT, 			KC_LGUI, 				KC_SPC,  		KC_SPC,			MO(21),     	MO(20), 						KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 		KC_NO, 				KC_NO, 			KC_NO, 					KC_NO, 		KC_NO
		),


};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_MODE1:
                current_mode = MODE_1;
                return false;
            case KC_MODE2:
                current_mode = MODE_2;
                return false;
        }
    }
    return true; 
}	

	

