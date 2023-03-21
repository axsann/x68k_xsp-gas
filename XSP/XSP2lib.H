#ifndef XSP2LIB_H
#define XSP2LIB_H


/* gcc 10 以降では、C の関数呼出し規約を無視して inline asm で関数を実行 */
#if defined(__GNUC__)
#	if (__GNUC__ >= 10)
#		define XSP_USE_INLINE_ASM (1)
#		define XSP_FORCE_INLINE	__attribute__((__always_inline__)) inline
#	endif
#endif

/* xsp_set_st , xobj_set_st の引数構造体 */
typedef	struct {
	short	x;				/* X 座標 */
	short	y;				/* Y 座標 */
	short	pt;				/* スプライトパターン No. */
	short	info;			/* 反転コード・色・優先度を表わすデータ */
} XSP_SET_ARG;


/* 複合スプライトのフレームデータ構造体 */
typedef	struct	{
	short	vx;				/* 相対座標データ */
	short	vy;				/* 相対座標データ */
	short	pt;				/* スプライトパターン No. */
	short	rv;				/* 反転コード */
} XOBJ_FRM_DAT;


/* 複合スプライトのリファレンスデータ構造体 */
typedef	struct	{
	short	num;			/* 合成スプライト数 */
	void	*ptr;			/* 開始位置のポインタ */
	short	unused;			/*（未使用）*/
} XOBJ_REF_DAT;


/* ラスター割り込み処理のタイムチャート */
typedef	struct	{
	short	ras_no;			/* 割り込みラスタナンバー */
	void	(* proc)();		/* 割り込み処理関数のポインタ */
} XSP_TIME_CHART;



void	_xsp_on(void);
void	_xsp_off(void);
void	_xsp_pcgdat_set(const void *pcg_dat, char *pcg_alt, short alt_size);
void	_xsp_pcgmask_on(short start_no, short end_no);
void	_xsp_pcgmask_off(short start_no, short end_no);
void	_xsp_mode(short mode_no);
void	_xsp_objdat_set(const void *sp_ref);
short	_xsp_vsync(short n);			/* obsoleted */
short	_xsp_vsync2(short max_delay);
#if !defined(XSP_USE_INLINE_ASM)
short	_xsp_set(short x, short y, short pt, short info);
void	_xobj_set(short x, short y, short pt, short info);
short	_xsp_set_st(const void *arg);
void	_xobj_set_st(const void *arg);
#else
	static XSP_FORCE_INLINE short _xsp_set(short x, short y, short pt, short info) {
		register short reg_d0 asm ("d0") = x;
		register short reg_d1 asm ("d1") = y;
		register short reg_d2 asm ("d2") = pt;
		register short reg_d3 asm ("d3") = info;
		asm volatile (
				"	jbsr	_xsp_set_asm\n"
		:	/* 出力 */	"+r"	(reg_d0)	/* in out %0 (入力＆戻り値) */
		:	/* 入力 */	"r"		(reg_d1),	/* in     %1 (入力＆維持) */
						"r"		(reg_d2),	/* in     %2 (入力＆維持) */
						"r"		(reg_d3)	/* in     %3 (入力＆維持) */
		:	/* 破壊 */	"a0"
		);
		return reg_d0;
	}
	static XSP_FORCE_INLINE short _xsp_set_st(const void *arg) {
		register short       reg_d0 asm ("d0");
		register const void *reg_a0 asm ("a0") = arg;
		asm volatile (
				"	jbsr	_xsp_set_st_asm\n"
		:	/* 出力 */	"=r"	(reg_d0),	/*    out %0 (戻り値) */
						"+r"	(reg_a0)	/* in out %1 (入力＆破壊) */
		:	/* 入力 */
		:	/* 破壊 */	"memory",			/* メモリバリアを要求 */
						"a1"
		);
		return reg_d0;
	}
	static XSP_FORCE_INLINE void _xobj_set(short x, short y, short pt, short info) {
		register short reg_d0 asm ("d0") = x;
		register short reg_d1 asm ("d1") = y;
		register short reg_d2 asm ("d2") = pt;
		register short reg_d3 asm ("d3") = info;
		asm volatile (
				"	jbsr	_xobj_set_asm\n"
		:	/* 出力 */	"+r"	(reg_d0),	/* in out %0 (入力＆破壊) */
						"+r"	(reg_d1),	/* in out %1 (入力＆破壊) */
						"+r"	(reg_d2),	/* in out %2 (入力＆破壊) */
						"+r"	(reg_d3)	/* in out %3 (入力＆破壊) */
		:	/* 入力 */
		:	/* 破壊 */	"d4",
						"a0","a1","a2"
		);
	}
	static XSP_FORCE_INLINE void _xobj_set_st(const void *arg) {
		register short       reg_d0 asm ("d0");
		register const void *reg_a0 asm ("a0") = arg;
		asm volatile (
				"	jbsr	_xobj_set_st_asm\n"
		:	/* 出力 */	"=r"	(reg_d0),	/* out %0 (破壊) */
						"+r"	(reg_a0)	/* out %1 (入力＆破壊) */
		:	/* 入力 */
		:	/* 破壊 */	"memory",			/* メモリバリアを要求 */
						"d1","d2","d3","d4",
						"a1","a2"
		);
	}
#endif
short	_xsp_out(void);
short	_xsp_out2(void *vsyncint_arg);
void	_xsp_vertical(short flag);

void	_xsp_vsyncint_on(void *proc);
void	_xsp_vsyncint_off(void);
void	_xsp_hsyncint_on(const void *time_chart);
void	_xsp_hsyncint_off(void);

void	_xsp_auto_adjust_divy(short flag);
void	_xsp_min_divh_set(short h);
short	_xsp_divy_get(short i);
void	_xsp_raster_ofs_for31khz_set(short ofs);
short	_xsp_raster_ofs_for31khz_get(void);
void	_xsp_raster_ofs_for15khz_set(short ofs);
short	_xsp_raster_ofs_for15khz_get(void);

void	_xsp_vsync_interval_set(short interval);
short	_xsp_vsync_interval_get(void);

#endif
