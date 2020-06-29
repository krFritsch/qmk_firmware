#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"

#define BASE 0 // default layer
#define LeftM3 1 // Modifier 3 pressed LEFT
#define RightM3 2 // Modifier 3 pressed RIGHT
#define LeftM4 3 // Modifier 4 pressed LEFT
#define RightM4 4 // Modifier 4 pressed RIGHT
#define MOUSE 5 // mouse keys
#define FKeys 6 // function keys
#define GREEK 7 // greek letters
#define SUBSC 8 // subscript letters
#define SUPER 9 // superscript letters
#define EMPTY 10 // media keys
#define NPPNAV 11 // navigate in notepad++

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD,
  NPP_LINEUP,
  NPP_LINEDN
};


enum unicode_names {
    GK_alp,
    GK_ALP,
    GK_bet,
    GK_BET,
    GK_gam,
    GK_GAM,
    GK_del,
    GK_DEL,
    GK_eps,
    GK_EPS,
    GK_zet,
    GK_ZET,
    GK_eta,
    GK_ETA,
    GK_vth,
    GK_VTH,
    GK_the,
    GK_THE,
    GK_iot,
    GK_IOT,
    GK_kap,
    GK_KAP,
    GK_lam,
    GK_LAM,
    GK_mu,
    GK_MU,
    GK_nu,
    GK_NU,
    GK_xi,
    GK_XI,
    GK_omi,
    GK_OMI,
    GK_pi,
    GK_PI,
    GK_vrh,
    GK_rho,
    GK_RHO,
    GK_fsi,
    GK_sig,
    GK_SIG,
    GK_tau,
    GK_TAU,
    GK_ups,
    GK_UPS,
    GK_vph,
    GK_phi,
    GK_PHI,
    GK_chi,
    GK_CHI,
    GK_psi,
    GK_PSI,
    GK_ome,
    GK_OME,
	SUB_0,
	SUB_1,
	SUB_2,
	SUB_3,
	SUB_4,
	SUB_5,
	SUB_6,
	SUB_7,
	SUB_8,
	SUB_9,
	SUP_0,
	SUP_1,
	SUP_2,
	SUP_3,
	SUP_4,
	SUP_5,
	SUP_6,
	SUP_7,
	SUP_8,
	SUP_9,
};

const uint32_t PROGMEM unicode_map[] = {
/*
 * greek letters
 */
    [GK_alp]	= 0x03B1,  	// alpha 		(α)
    [GK_ALP] 	= 0x0391,  	// Alpha 		(Α)
    [GK_bet]  	= 0x03B2, 	// beta 		(β)
    [GK_BET]  	= 0x0392, 	// Beta 		(Β)
    [GK_gam]	= 0x03B3,  	// gamma 		(γ)
    [GK_GAM] 	= 0x0393,  	// Gamma 		(Γ)
    [GK_del]  	= 0x03B4, 	// delta 		(δ)
    [GK_DEL]  	= 0x0394, 	// Delta 		(Δ)
    [GK_eps]	= 0x03B5,  	// epsilon 		(ε)
    [GK_EPS] 	= 0x0395,  	// Epsilon 		(Ε)
    [GK_zet]  	= 0x03B6, 	// zeta 		(ζ)
    [GK_ZET]  	= 0x0396, 	// Zeta 		(Ζ)
    [GK_eta]	= 0x03B7,  	// eta 			(η)
    [GK_ETA]	= 0x0397,  	// Eta 			(Η)
    [GK_vth] 	= 0x03D1, 	// vartheta		(ϑ)
    [GK_VTH] 	= 0x03F4, 	// VarTheta		(ϴ)
    [GK_the]  	= 0x03B8, 	// theta 		(θ)
    [GK_THE]  	= 0x0398, 	// Theta 		(Θ)
    [GK_iot]	= 0x03B9,  	// iota 		(ι)
    [GK_IOT] 	= 0x0399,  	// Iota 		(Ι)
    [GK_kap]  	= 0x03BA, 	// kappa 		(κ)
    [GK_KAP]  	= 0x039A, 	// Kappa 		(Κ)
    [GK_lam]	= 0x03BB,  	// lambda 		(λ)
    [GK_LAM] 	= 0x039B,  	// Lambda 		(Λ)
    [GK_mu]	  	= 0x03BC, 	// mu 			(μ)
    [GK_MU]  	= 0x039C, 	// Mu 			(Μ)
    [GK_nu]	  	= 0x03BD, 	// nu 			(ν)
    [GK_NU]  	= 0x039D, 	// Nu 			(Ν)
    [GK_xi]	  	= 0x03BE, 	// xi 			(ξ)
    [GK_XI]  	= 0x039E, 	// Xi 			(Ξ)
    [GK_omi]  	= 0x03BF, 	// omicron 		(ο)
    [GK_OMI]	= 0x039F, 	// Omicron 		(Ο)
    [GK_pi]	  	= 0x03C0, 	// pi 			(π)
    [GK_PI]  	= 0x03A0, 	// Pi 			(Π)
    [GK_vrh]  	= 0x03F1, 	// varrho 		(ϱ)
    [GK_rho]	= 0x03C1, 	// rho 			(ρ)
    [GK_RHO]  	= 0x03A1, 	// Rho 			(Ρ)
    [GK_fsi] 	= 0x03C2, 	// final sigma 	(ς) no capital version
    [GK_sig]	= 0x03C3, 	// sigma 		(σ)
    [GK_SIG]	= 0x03A3, 	// Sigma 		(Σ)
    [GK_tau]	= 0x03C4, 	// tau 			(τ)
    [GK_TAU]  	= 0x03A4, 	// Tau 			(Τ)
    [GK_ups]  	= 0x03C5, 	// upsilon 		(υ)
    [GK_UPS]	= 0x03A5, 	// Upsilon 		(Υ)
    [GK_vph]	= 0x03D5, 	// varphi 		(ϕ) no capital version
    [GK_phi]	= 0x03C6, 	// phi 			(φ)
    [GK_PHI]  	= 0x03A6, 	// Phi 			(Φ)
    [GK_chi]	= 0x03C7, 	// chi 			(χ)
    [GK_CHI]  	= 0x03A7, 	// Chi 			(Χ)
    [GK_psi]	= 0x03C8, 	// psi 			(ψ)
    [GK_PSI]  	= 0x03A8, 	// Psi 			(Ψ)
    [GK_ome]	= 0x03C9, 	// omega 		(ω)
    [GK_OME]	= 0x03A9, 	// Omega 		(Ω)
/*
 *	Subscript and superscript
 */
	[SUB_0]  = 0x2080 ,	  // subscript 0
	[SUB_1]  = 0x2081 ,	  // subscript 1
	[SUB_2]  = 0x2082 ,	  // subscript 2
	[SUB_3]  = 0x2083 ,	  // subscript 3
	[SUB_4]  = 0x2084 ,	  // subscript 4
	[SUB_5]  = 0x2085 ,	  // subscript 5
	[SUB_6]  = 0x2086 ,	  // subscript 6
	[SUB_7]  = 0x2087 ,	  // subscript 7
	[SUB_8]  = 0x2088 ,	  // subscript 8
	[SUB_9]  = 0x2089 ,	  // subscript 9

	[SUP_0]  = 0x2070 ,	  // superscript 0
	[SUP_1]  = 0x00B9 ,	  // superscript 1
	[SUP_2]  = 0x00B2 ,	  // superscript 2
	[SUP_3]  = 0x00B3 ,	  // superscript 3
	[SUP_4]  = 0x2074 ,	  // superscript 4
	[SUP_5]  = 0x2075 ,	  // superscript 5
	[SUP_6]  = 0x2076 ,	  // superscript 6
	[SUP_7]  = 0x2077 ,	  // superscript 7
	[SUP_8]  = 0x2078 ,	  // superscript 8
	[SUP_9]  = 0x2079 ,	  // superscript 9
};


/*
*  Modifier keys noted like Autohotkey, i.e.:
*  # WIN
*  ! Alt
*  ^ Control
*  + Shift
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 00: default layer
 * Ascii-art generator: http://patorjk.com/software/taag/#p=display&f=Big&t=Mouse
 *      _           __                   _   _       _                               
 *     | |         / _|                 | | | |     | |                              
 *   __| |   ___  | |_    __ _   _   _  | | | |_    | |   __ _   _   _    ___   _ __ 
 *  / _` |  / _ \ |  _|  / _` | | | | | | | | __|   | |  / _` | | | | |  / _ \ | '__|
 * | (_| | |  __/ | |   | (_| | | |_| | | | | |_    | | | (_| | | |_| | |  __/ | |   
 *  \__,_|  \___| |_|    \__,_|  \__,_| |_|  \__|   |_|  \__,_|  \__, |  \___| |_|   
 *                                                                __/ |              
 *                                                               |___/                
 * 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  | #L   |           | !^A  |   6  |   7  |   8  |   9  |   0  |   BSPC |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |CTL/Tab |   X  |   V  |   L  |   C  |   W  |FKeys |           |  ^Z  |   K  |   H  |   G  |   F  |   Q  | CTL/ß  |
 * |--------+------+------+------+------+------|      |           |(undo)|------+------+------+------+------+--------|
 * |   L3   |   U  |   I  |   A  |   E  |   O  |------|           |------|   S  |   N  |   R  |   T  |   D  |   L3   |
 * |--------+------+------+------+------+------| None |           |  ^Y  |------+------+------+------+------+--------|
 * | LShift |   Ü  |   Ö  |   Ä  |   P  |   Z  |      |           |(redo)|   B  |   M  |   ,  |   .  |   J  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | L4 |  +#S  | None | GUI | LALT |                                       |  L4  | GUI |  APP  |  None  | Enter |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | None | None |       | None |  None  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | None |       | None |        |      |
 *                                 | CTRL | MOUSE|------|       |------|  LEAD  | SPC  |
 *                                 | BSPC | Layer|GREEK |       | GREEK|        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_ESC              , DE_1      , DE_2   , DE_3   , DE_4   , DE_5, LCMD(DE_L),
  MT(MOD_LCTL, KC_TAB), DE_X      , DE_V   , DE_L   , DE_C   , DE_W, MO(FKeys) ,
  MO(LeftM3)          , DE_U      , DE_I   , DE_A   , DE_E   , DE_O            ,
  KC_LSFT             , DE_UDIA   , DE_ODIA, DE_ADIA, DE_P   , DE_Z, KC_TRNS   ,
  MO(LeftM4)          , G(S(DE_S)), KC_TRNS, KC_LGUI, KC_LALT,
                                                               KC_TRNS, KC_TRNS,
                                                                        KC_TRNS,
                                     LCTL(KC_BSPC), LT(MOUSE, KC_TRNS), MO(GREEK),
  // right hand
  C(A(DE_A)) , DE_6,    DE_7,   DE_8    , DE_9  , DE_0, KC_BSPC            ,
  C(DE_Z)    , DE_K,    DE_H,   DE_G    , DE_F  , DE_Q, MT(MOD_RCTL, DE_SS),
               DE_S,    DE_N,   DE_R    , DE_T  , DE_D, LT(RightM3, DE_Y)  ,
  C(DE_Y)    , DE_B,    DE_M,   KC_COMMA, KC_DOT, DE_J, KC_RSFT            ,
  MO(RightM4), KC_RGUI, KC_APP, KC_TRNS , KC_ENT,
  KC_TRNS    , KC_TRNS,
  KC_TRNS    ,
  MO(GREEK)  , KC_LEAD, KC_SPACE
),
/* Keymap 01: Modifier 3 pressed LEFT
 *
 *  __  __               _   _    __   _                   ____      _        ______   ______   _______ 
 * |  \/  |             | | (_)  / _| (_)                 |___ \    | |      |  ____| |  ____| |__   __|
 * | \  / |   ___     __| |  _  | |_   _    ___   _ __      __) |   | |      | |__    | |__       | |   
 * | |\/| |  / _ \   / _` | | | |  _| | |  / _ \ | '__|    |__ <    | |      |  __|   |  __|      | |   
 * | |  | | | (_) | | (_| | | | | |   | | |  __/ | |       ___) |   | |____  | |____  | |         | |   
 * |_|  |_|  \___/   \__,_| |_| |_|   |_|  \___| |_|      |____/    |______| |______| |_|         |_|                     
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   !  |   <  |   >  |  =   |   &  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   ?  |  (   |   )  |   -  |   :  |   @    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  +   |   %  |   "  |  '   |   ;  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LeftM3] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, DE_EXLM, DE_LABK, DE_RABK, DE_EQL , DE_AMPR, KC_TRNS,
           DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT,
  KC_TRNS, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 01: Modifier 3 pressed RIGHT
 *  __  __               _   _    __   _                   ____      _____    _____    _____   _    _   _______ 
 * |  \/  |             | | (_)  / _| (_)                 |___ \    |  __ \  |_   _|  / ____| | |  | | |__   __|
 * | \  / |   ___     __| |  _  | |_   _    ___   _ __      __) |   | |__) |   | |   | |  __  | |__| |    | |   
 * | |\/| |  / _ \   / _` | | | |  _| | |  / _ \ | '__|    |__ <    |  _  /    | |   | | |_ | |  __  |    | |   
 * | |  | | | (_) | | (_| | | | | |   | | |  __/ | |       ___) |   | | \ \   _| |_  | |__| | | |  | |    | |   
 * |_|  |_|  \___/   \__,_| |_| |_|   |_|  \___| |_|      |____/    |_|  \_\ |_____|  \_____| |_|  |_|    |_|   
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   _  |   [  |   ]  |  ^   |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  \   |   /  |  {   |   }  |  *   |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   |  |   ~  |  `   |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[RightM3] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, KC_TRNS,
  KC_TRNS, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,
  KC_TRNS, DE_HASH, DE_DLR , DE_PIPE, DE_TILD, DE_GRV , KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 02: Modifier 4 pressed LEFT
 *  __  __               _   _    __   _                   _  _       _        ______   ______   _______ 
 * |  \/  |             | | (_)  / _| (_)                 | || |     | |      |  ____| |  ____| |__   __|
 * | \  / |   ___     __| |  _  | |_   _    ___   _ __    | || |_    | |      | |__    | |__       | |   
 * | |\/| |  / _ \   / _` | | | |  _| | |  / _ \ | '__|   |__   _|   | |      |  __|   |  __|      | |   
 * | |  | | | (_) | | (_| | | | | |   | | |  __/ | |         | |     | |____  | |____  | |         | |   
 * |_|  |_|  \___/   \__,_| |_| |_|   |_|  \___| |_|         |_|     |______| |______| |_|         |_|   
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |  TAB |   /  |  *  |   -  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |  ,   |   .    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  :   |   1  |   2  |   3  |  ;   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |  0   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LeftM4] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TAB , KC_PSLS, KC_PAST, KC_PMNS , KC_TRNS,
  KC_TRNS, KC_TRNS, KC_P7  , KC_P8  , KC_P9  , KC_PPLS , KC_TRNS,
           KC_TRNS, KC_P4  , KC_P5  , KC_P6  , KC_COMMA, KC_PDOT,
  KC_TRNS, DE_COLN, KC_P1  , KC_P2  , KC_P3  , DE_SCLN , KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_P0
),
/* Keymap 03: Modifier 4 pressed RIGHT
 *  __  __               _   _    __   _                   _  _       _____    _____    _____   _    _   _______ 
 * |  \/  |             | | (_)  / _| (_)                 | || |     |  __ \  |_   _|  / ____| | |  | | |__   __|
 * | \  / |   ___     __| |  _  | |_   _    ___   _ __    | || |_    | |__) |   | |   | |  __  | |__| |    | |   
 * | |\/| |  / _ \   / _` | | | |  _| | |  / _ \ | '__|   |__   _|   |  _  /    | |   | | |_ | |  __  |    | |   
 * | |  | | | (_) | | (_| | | | | |   | | |  __/ | |         | |     | | \ \   _| |_  | |__| | | |  | |    | |   
 * |_|  |_|  \___/   \__,_| |_| |_|   |_|  \___| |_|         |_|     |_|  \_\ |_____|  \_____| |_|  |_|    |_|   
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | PgUp |  BSPC|  up  |  del | PgDn |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | home | left | dwn  | right| end  |------|           |------|      |      |      |      |      | nppnav |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | ESC  |  TAB |  INS |ENTER | undo |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[RightM4] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_PGUP, KC_BSPC, KC_UP  , KC_DEL , KC_PGDN, KC_TRNS,
  KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END ,
  KC_TRNS, KC_ESC , KC_TAB , KC_INS , KC_ENT , C(DE_Z), KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(NPPNAV),
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 04: Mouse
 *  __  __                              
 * |  \/  |                             
 * | \  / |   ___    _   _   ___    ___ 
 * | |\/| |  / _ \  | | | | / __|  / _ \
 * | |  | | | (_) | | |_| | \__ \ |  __/
 * |_|  |_|  \___/   \__,_| |___/  \___|
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |VolUp | But4 |WhUp  | But5 |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|VolDwn|WhLft |WhDwn |WhRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |Mute  |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |MClck |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|LClck |RClck |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MOUSE] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_VOLU, KC_BTN4, KC_MS_WH_UP, KC_BTN5, KC_TRNS, KC_TRNS,
           KC_VOLD, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_MS_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_BTN1, KC_BTN2
),
/* Keymap 05: function keys
 *  ______                          _     _                 
 * |  ____|                        | |   (_)                
 * | |__     _   _   _ __     ___  | |_   _    ___    _ __  
 * |  __|   | | | | | '_ \   / __| | __| | |  / _ \  | '_ \ 
 * | |      | |_| | | | | | | (__  | |_  | | | (_) | | | | |
 * |_|       \__,_| |_| |_|  \___|  \__| |_|  \___/  |_| |_|
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |  F5  |  F6  |  F7  |  F8  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  F1  |  F2  |  F3  |  F4  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FKeys] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS,
           KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 06: Greek letters
 *
 *   _____               _    
 *  / ____|             | |   
 * | |  __ _ __ ___  ___| | __
 * | | |_ | '__/ _ \/ _ \ |/ /
 * | |__| | | |  __/  __/   < 
 *  \_____|_|  \___|\___|_|\_\
 * 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  poop  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  xi  |      | lmbd | chi  | omga |      |           |      | kppa |  psi |gamma | phi  | vphi |  fsig  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | iota |alpha |epsln |omcrn |------|           |------| sgma |  nu  | rho  | tau  |delta |upsilon |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | eta  |  pi  | zeta |      |           |      | beta |  mu  | vrho | thta |vthta |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[GREEK] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS			, KC_TRNS			, KC_TRNS			, KC_TRNS			, KC_TRNS			, KC_TRNS,
  KC_TRNS, XP(GK_xi, GK_XI)	, KC_TRNS			, XP(GK_lam, GK_LAM), XP(GK_chi, GK_CHI), XP(GK_ome, GK_OME), KC_TRNS,
  KC_TRNS, KC_TRNS			, XP(GK_iot, GK_IOT), XP(GK_alp, GK_ALP), XP(GK_eps, GK_EPS), XP(GK_omi, GK_OMI),
  KC_TRNS, KC_TRNS			, KC_TRNS			, XP(GK_eta, GK_ETA), XP(GK_pi , GK_PI ), XP(GK_zet, GK_ZET), KC_TRNS,
  KC_TRNS, KC_TRNS			, KC_TRNS			, KC_TRNS			, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS				, KC_TRNS			, KC_TRNS			, KC_TRNS			, KC_TRNS, KC_TRNS,
  KC_TRNS, XP(GK_kap, GK_KAP)	, XP(GK_psi, GK_PSI), XP(GK_gam, GK_GAM), XP(GK_phi, GK_PHI), XP(GK_vph, GK_PHI), XP(GK_fsi, GK_SIG),
           XP(GK_sig, GK_SIG)	, XP(GK_nu , GK_NU ), XP(GK_rho, GK_RHO), XP(GK_tau, GK_TAU), XP(GK_del, GK_DEL), XP(GK_ups, GK_UPS),
  KC_TRNS, XP(GK_bet, GK_BET)	, XP(GK_mu , GK_MU ), XP(GK_vrh, GK_RHO), XP(GK_the, GK_THE), XP(GK_vth, GK_VTH), KC_TRNS,
											KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 07: Subscript
 *   _____       _                   _       _   
 *  / ____|     | |                 (_)     | |  
 * | (___  _   _| |__  ___  ___ _ __ _ _ __ | |_ 
 *  \___ \| | | | '_ \/ __|/ __| '__| | '_ \| __|
 *  ____) | |_| | |_) \__ \ (__| |  | | |_) | |_ 
 * |_____/ \__,_|_.__/|___/\___|_|  |_| .__/ \__|
 *                                    | |        
 *                                    |_|        
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | TO(0)  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   ₇  |  ₈   |  ₉   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   ₄  |  ₅   |  ₆   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   ₁  |  ₂   |  ₃   |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |  ₀   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SUBSC] = LAYOUT_ergodox(
  // left hand
  TO(0)  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, X(SUB_7), X(SUB_8), X(SUB_9), KC_TRNS, KC_TRNS,
           KC_TRNS, X(SUB_4), X(SUB_5), X(SUB_6), KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, X(SUB_1), X(SUB_2), X(SUB_3), KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, X(SUB_0)
),

/* Keymap 08: Superscript
 *   _____                                     _       _   
 *  / ____|                                   (_)     | |  
 * | (___  _   _ _ __   ___ _ __ ___  ___ _ __ _ _ __ | |_ 
 *  \___ \| | | | '_ \ / _ \ '__/ __|/ __| '__| | '_ \| __|
 *  ____) | |_| | |_) |  __/ |  \__ \ (__| |  | | |_) | |_ 
 * |_____/ \__,_| .__/ \___|_|  |___/\___|_|  |_| .__/ \__|
 *              | |                             | |        
 *              |_|                             |_|        
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | TO(0)  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  ⁷   |  ⁸   |  ⁹   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |  ⁴   |  ⁵   |  ⁶   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  ¹   |  ²   |  ³   |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |  ⁰   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------' 
 */
[SUPER] = LAYOUT_ergodox(
  // left hand
  TO(0)  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, X(SUP_7), X(SUP_8), X(SUP_9), KC_TRNS, KC_TRNS,
           KC_TRNS, X(SUP_4), X(SUP_5), X(SUP_6), KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, X(SUP_1), X(SUP_2), X(SUP_3), KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, X(SUP_0)
),

/* Keymap 09: NPPNAV
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |LN UP |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |prev T|      |LN DN |      |next T|------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | oth  |      |      |       |      |      |      |
 *                                 |  er  |      |------|       |------|      |      |
 *                                 | view |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NPPNAV] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, NPP_LINEUP, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, C(KC_PGUP), KC_TRNS, NPP_LINEDN, KC_TRNS, C(KC_PGDN),
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_F8, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 09: EMPTY
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[EMPTY] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
};

/*
 * Define leader key sequences here
 *
 *  _                      _                   _                         
 * | |                    | |                 | |                        
 * | |   ___    __ _    __| |   ___   _ __    | | __   ___   _   _   ___ 
 * | |  / _ \  / _` |  / _` |  / _ \ | '__|   | |/ /  / _ \ | | | | / __|
 * | | |  __/ | (_| | | (_| | |  __/ | |      |   <  |  __/ | |_| | \__ \
 * |_|  \___|  \__,_|  \__,_|  \___| |_|      |_|\_\  \___|  \__, | |___/
 *                                                            __/ |      
 *                                                           |___/       
 */
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
	
	SEQ_THREE_KEYS(KC_S, KC_U, KC_B) {
      // LEAD + S U B
		layer_on(SUBSC);
	}
	SEQ_THREE_KEYS(KC_S, KC_U, KC_P) {
      // LEAD + S U P
		layer_on(SUPER);
	}
	
    SEQ_ONE_KEY(KC_Q) {
      // Send Alt + F4
       register_code(KC_LALT);
       register_code(KC_F4);
       unregister_code(KC_F4);
       unregister_code(KC_LALT);	
	}
    SEQ_TWO_KEYS(KC_S, KC_T) {
      // Search open tabs in firefox
       register_code(KC_F24);
       register_code(KC_A);
       unregister_code(KC_A);
       unregister_code(KC_F24);	   
    }
    SEQ_TWO_KEYS(KC_N, KC_L) {
      // Toggle windosw night light
       register_code(KC_F24);
       register_code(KC_B);
       unregister_code(KC_B);
       unregister_code(KC_F24);	   
    }
	
    SEQ_FOUR_KEYS(KC_T, KC_E, KC_S, KC_T) {
      // LEAD + T E S T
       register_code(KC_F24);
       register_code(KC_0);
       unregister_code(KC_0);
       unregister_code(KC_F24);
    }
    SEQ_FOUR_KEYS(KC_F, KC_I, KC_L, KC_E) {
      // LEAD + F I L E
       register_code(KC_F24);
       register_code(KC_1);
       unregister_code(KC_1);
       unregister_code(KC_F24);
    }
    SEQ_THREE_KEYS(KC_W, KC_E, KC_B) {
      // LEAD + W E B
       register_code(KC_F24);
       register_code(KC_2);
       unregister_code(KC_2);
       unregister_code(KC_F24);
    }
    SEQ_FOUR_KEYS(KC_M, KC_A, KC_I, KC_L) {
      // LEAD + M A I L
       register_code(KC_F24);
       register_code(KC_3);
       unregister_code(KC_3);
       unregister_code(KC_F24);
    }
    SEQ_FOUR_KEYS(KC_P, KC_A, KC_S, KC_S) {
      // LEAD + P A S S
       register_code(KC_F24);
       register_code(KC_4);
       unregister_code(KC_4);
       unregister_code(KC_F24);
    }
    SEQ_THREE_KEYS(KC_N, KC_P, KC_P) {
      // LEAD + N P P 
       register_code(KC_F24);
       register_code(KC_5);
       unregister_code(KC_5);
       unregister_code(KC_F24);
    }
    SEQ_FOUR_KEYS(KC_N, KC_O, KC_T, KC_E) {
      // LEAD + N O T E
       register_code(KC_F24);
       register_code(KC_6);
       unregister_code(KC_6);
       unregister_code(KC_F24);
    }
    SEQ_FOUR_KEYS(KC_G, KC_W, KC_E, KC_B) {
      // LEAD + G W E B
       register_code(KC_F24);
       register_code(KC_7);
       unregister_code(KC_7);
       unregister_code(KC_F24);
    }	
    SEQ_THREE_KEYS(KC_T, KC_E, KC_X) {
      // LEAD + W E B
       register_code(KC_F24);
       register_code(KC_C);
       unregister_code(KC_C);
       unregister_code(KC_F24);
    }
	SEQ_FIVE_KEYS(KC_E, KC_S, KC_H, KC_I, KC_T) {
      // LEAD + E S H I T
		send_unicode_string("💩");
	}
	SEQ_FIVE_KEYS(KC_E, KC_T, KC_H, KC_U, KC_P) {
      // LEAD + E T H U P
		send_unicode_string("👍");
	}
	SEQ_FIVE_KEYS(KC_E, KC_T, KC_H, KC_D, KC_N) {
      // LEAD + E T H D N
		send_unicode_string("👎");
	}
	SEQ_FIVE_KEYS(KC_E, KC_C, KC_L, KC_A, KC_P) {
      // LEAD + E C L A P
		send_unicode_string("👏");
	}
	SEQ_THREE_KEYS(KC_E, KC_O, KC_K) {
      // LEAD + E O K
		send_unicode_string("👌");
	}
	SEQ_FIVE_KEYS(KC_E, KC_W, KC_N, KC_K, KC_I) {
      // LEAD + E W N K I
		send_unicode_string("😉");
	}
	SEQ_FIVE_KEYS(KC_E, KC_S, KC_M, KC_L, KC_I) {
      // LEAD + E S M L I
		send_unicode_string("😀");
	}
	SEQ_FIVE_KEYS(KC_R, KC_E, KC_S, KC_E, KC_T) {
      // LEAD + R E S E T
      SEND_STRING("RESETTING THE KEYBOARD!");
      reset_keyboard();
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;	
	  case NPP_LINEUP:
		SEND_STRING (SS_LCTL("t"));
		SEND_STRING (SS_TAP(X_UP));
		return false;
	  case NPP_LINEDN:
		SEND_STRING (SS_TAP(X_DOWN));
		SEND_STRING (SS_LCTL("t"));
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif	  
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
set_unicode_input_mode(UC_WINC);
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
