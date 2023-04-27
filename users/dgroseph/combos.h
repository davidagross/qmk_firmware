#include QMK_KEYBOARD_H

enum combos {

	// Horizontal 2-Chords (3 * 8 = 24)

	QW,WE,ER,RT,YU,UI,IO,OP,
	AS,SD,DF,FG,HJ,JK,KL,LQ,
	ZX,XC,CV,VB,NM,MC,CD,DS,

	// Vertical 2-Chords ( + 2 * 10 = 44)

	QA,WS,ED,RF,TG,YH,UJ,IK,OL,PQ,
	AZ,SX,DC,FV,GB,HN,JM,KC,LD,QS,

	// Horizontal 3-Chords (+ 3 * 6 = 62)

	QWE,WER,ERT,YUI,UIO,IOP,
	ASD,SDF,DFG,HJK,JKL,KLQ,
	ZXC,XCV,CVB,NMC,MCD,CDS,

	// Horizontal 4-Chords (+ 3 * 4 = 74)

	QWER,WERT,YUIO,UIOP,
	ASDF,SDFG,HJKL,JKLQ,
	ZXCV,XCVB,NMCD,MCDS,

	// Split Chords (+ 1 = 75)

	SDJK,
};

// Horizontal 2-Chords

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};

const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};

const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};

const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lq_combo[] = {KC_L, KC_QUOT, COMBO_END};

const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM mc_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_DOT, KC_SLSH, COMBO_END};

// Vertical 2-Chords

const uint16_t PROGMEM qa_combo[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM ws_combo[] = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM ed_combo[] = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM rf_combo[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM tg_combo[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM yh_combo[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM uj_combo[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM ik_combo[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM ol_combo[] = {KC_O, KC_L, COMBO_END};
const uint16_t PROGMEM pq_combo[] = {KC_P, KC_QUOT, COMBO_END};

const uint16_t PROGMEM az_combo[] = {KC_A, KC_Z, COMBO_END};
const uint16_t PROGMEM sx_combo[] = {KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM dc_combo[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM fv_combo[] = {KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM gb_combo[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM hn_combo[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM jm_combo[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM kc_combo[] = {KC_K, KC_COMM, COMBO_END};
const uint16_t PROGMEM ld_combo[] = {KC_L, KC_DOT, COMBO_END};
const uint16_t PROGMEM qs_combo[] = {KC_QUOT, KC_SLSH, COMBO_END};

// Horizontal 3-Chords

const uint16_t PROGMEM qwe_combo[] = {KC_Q, KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM wer_combo[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM ert_combo[] = {KC_E, KC_R, KC_T, COMBO_END};

const uint16_t PROGMEM yui_combo[] = {KC_Y, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM uio_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM iop_combo[] = {KC_I, KC_O, KC_P, COMBO_END};

const uint16_t PROGMEM asd_combo[] = {KC_A, KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM sdf_combo[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM dfg_combo[] = {KC_D, KC_F, KC_G, COMBO_END};

const uint16_t PROGMEM hjk_combo[] = {KC_H, KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM klq_combo[] = {KC_K, KC_L, KC_QUOT, COMBO_END};

const uint16_t PROGMEM zxc_combo[] = {KC_Z, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM xcv_combo[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cvb_combo[] = {KC_C, KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM nmc_combo[] = {KC_N, KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM mcd_combo[] = {KC_M, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cds_combo[] = {KC_COMM, KC_DOT, KC_SLSH, COMBO_END};

// Horizontal 4-Chords

const uint16_t PROGMEM qwer_combo[] = {KC_Q, KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM wert_combo[] = {KC_W, KC_E, KC_R, KC_T, COMBO_END};

const uint16_t PROGMEM yuio_combo[] = {KC_Y, KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM uiop_combo[] = {KC_U, KC_I, KC_O, KC_P, COMBO_END};

const uint16_t PROGMEM asdf_combo[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM sdfg_combo[] = {KC_S, KC_D, KC_F, KC_G, COMBO_END};

const uint16_t PROGMEM hjkl_combo[] = {KC_H, KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM jklq_combo[] = {KC_J, KC_K, KC_L, KC_QUOT, COMBO_END};

const uint16_t PROGMEM zxcv_combo[] = {KC_Z, KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM xcvb_combo[] = {KC_X, KC_C, KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM nmcd_combo[] = {KC_N, KC_M, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM mcds_combo[] = {KC_M, KC_COMM, KC_DOT, KC_SLSH, COMBO_END};

// Split Chords

const uint16_t PROGMEM sdjk_combo[] = {KC_S, KC_D, KC_J, KC_K, COMBO_END};
