/*
	XSP 利用サンプルプログラム

	[動作]
		コマンドライン引数として指定された複合スプライトファイルを読み込み、
		画面に表示します。ジョイスティックで複合スプライトを移動、トリガで
		パレットとパターンを変更できます。トリガ長押しで早送り可能です。簡
		易的な複合スプライトビューワとしても利用できます。

	[解説]
		複合スプライト形状データ（拡張子 .xsp .frm .ref）をファイルから読み
		込み表示する手順を示すサンプルプログラムです。

		ZAKO.xsp/frm/ref が、本プログラム対応のサンプルデータです。ZAKO.SP
		が PCG データ、ZAKO.src は複合スプライト形状データのソースファイル
		です。ZAKO.xsp/frm/ref は、CVOBJ.X を使用して ZAKO.src と ZAKO.SP
		から生成されたファイルです。

		本プログラムは、スプライトパレットの初期化は行いません。スプライト
		RAM上に現在設定されているパレットがそのまま表示結果に反映されます。
		必要な場合は事前に他のツールを用いるなどしてパレット初期化を行って
		下さい。
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <x68k/dos.h>
#include <x68k/iocs.h>
#include "../../XSP/XSP2lib.H"

/* TODO: スプライトの表示が確認できないので要修正 */

/* スプライト PCG パターン最大使用数 */
#define		PCG_MAX		2048

/* 複合スプライトリファレンスデータ最大使用数 */
#define		REF_MAX		4096

/* 複合スプライトフレームデータ最大使用数 */
#define		FRM_MAX		16384


/*
	XSP 用 PCG 配置管理テーブル
	スプライト PCG パターン最大使用数 + 1 バイトのサイズが必要。
*/
char	pcg_alt[PCG_MAX + 1];

/* PCG データファイル読み込みバッファ */
char	pcg_dat[PCG_MAX * 128];

/* XSP 複合スプライトフレームデータ */
XOBJ_FRM_DAT	frm_dat[FRM_MAX];

/* XSP 複合スプライトリファレンスデータ */
XOBJ_REF_DAT	ref_dat[REF_MAX];


void set_extension(char *buffer, const char *filename, const char *extension) {
    // 拡張子なしのファイル名をバッファにコピー
    strcpy(buffer, filename);

    // ファイル名のドットを見つける
    char *dot = strrchr(buffer, '.');
    if (dot != NULL) {
        *dot = '\0';
    }

    // 新しい拡張子を追加
    strcat(buffer, ".");
    strcat(buffer, extension);
}


/*-------------------------------------[ MAIN ]---------------------------------------*/
void main(int argc, unsigned char* argv[])
{
	int		i;
	int		sizeof_ref;		/* 複合スプライトリファレンスデータ読み込み数 */
	FILE	*fp;

	/* キャラクタ管理構造体 */
	struct {
		short	x, y;		/* 座標 */
		short	pt;			/* スプライトパターン No. */
		short	info;		/* 反転コード・色・優先度を表すデータ */
	} player;


	/*----------[ コマンドライン解析〜ファイル読み込み ]----------*/

	if (argc <= 1) {
		/* ヘルプを表示して終了 */
		printf("使用法：main.x [形状データファイル名（拡張子省略）]\n");
		exit(0);
	} else {
		char	str_tmp[256];

		/* ファイル読み込み */
		set_extension(str_tmp, argv[1], "xsp");		/* 拡張子置換 */
		fp = fopen(str_tmp, "rb");
		if (fp == NULL) {
			_iocs_crtmod(0x10);
			printf("%s が open できません。\n", str_tmp);
			exit(1);
		}
		fread(pcg_dat, sizeof(char), 128 * PCG_MAX, fp);

		set_extension(str_tmp, argv[1], "frm");		/* 拡張子置換 */
		fp = fopen(str_tmp, "rb");
		if (fp == NULL) {
			_iocs_crtmod(0x10);
			printf("%s が open できません。\n", str_tmp);
			exit(1);
		}
		fread(frm_dat, sizeof(XOBJ_FRM_DAT), FRM_MAX, fp);

		set_extension(str_tmp, argv[1], "ref");		/* 拡張子置換 */
		fp = fopen(str_tmp, "rb");
		if (fp == NULL) {
			_iocs_crtmod(0x10);
			printf("%s が open できません。\n", str_tmp);
			exit(1);
		}
		sizeof_ref = fread(ref_dat, sizeof(XOBJ_REF_DAT), REF_MAX, fp);
		fclose(fp);

		/* REF_DAT[].ptr 補正 */
		for (i = 0; i < sizeof_ref; i++) {
			ref_dat[i].ptr = (void *)((intptr_t)ref_dat[i].ptr + (intptr_t)(&frm_dat[0]));
		}
	}


	/*---------------------[ 画面を初期化 ]---------------------*/

	/* 256x256 dot 16 色グラフィックプレーン 4 枚 31KHz */
	_iocs_crtmod(6);

	/* スプライト表示を ON */
	_iocs_sp_on();

	/* BG0 表示 OFF */
	_iocs_bgctrlst(0, 0, 0);

	/* BG1 表示 OFF */
	_iocs_bgctrlst(1, 1, 0);

	/* 簡易説明 */
	printf(
		"ジョイスティックで複合スプライトを移動できます。\n"
		"トリガでパターンとパレットを変更できます。\n"
		"何かキーを押すと終了します。\n"
	);

	/* カーソル表示 OFF */
	_iocs_b_curoff();


	/*---------------------[ XSP を初期化 ]---------------------*/

	/* XSP の初期化 */
	_xsp_on();

	/* PCG データと PCG 配置管理をテーブルを指定 */
	_xsp_pcgdat_set(pcg_dat, pcg_alt, sizeof(pcg_alt));

	/* 複合スプライト形状データを指定 */
	_xsp_objdat_set(ref_dat);


	/*==========================[ スティックで操作するデモ ]============================*/

	/* 初期化 */
	player.x	= 0x88;		/* X 座標初期値 */
	player.y	= 0x88;		/* Y 座標初期値 */
	player.pt	= 0;		/* スプライトパターン No. */
	player.info	= 0x013F;	/* 反転コード・色・優先度を表すデータ */


	/* 何かキーを押すまでループ */
	while (_dos_inpout(0xFF) == 0) {
		static int	pre_stk = 0;
		static int	stk = 0;
		static int	timer = 0;

		/* 垂直同期 */
		_xsp_vsync2(1);

		/* スティックの入力に合せて移動 */
		pre_stk = stk;		/* 前回のスティックの内容 */
		stk = _iocs_joyget(0);	/* 今回のスティックの内容 */
		if ((stk & 1) == 0) player.y -= 1;		/* 上に移動 */
		if ((stk & 2) == 0) player.y += 1;		/* 下に移動 */
		if ((stk & 4) == 0) player.x -= 1;		/* 左に移動 */
		if ((stk & 8) == 0) player.x += 1;		/* 右に移動 */

		/* トリガ長押し期間測定 */
		if ((stk & 0x60) == (pre_stk & 0x60)) {
			timer++;		/* タイマ加算 */
		} else {
			timer = 0;		/* タイマクリア */
		}

		/* トリガー 2 が押されたらパターン変更 */
		if ((stk & 0x20) == 0  &&  ((pre_stk & 0x20) != 0  ||  timer > 32)) {
			player.pt++;
			if (player.pt >= sizeof_ref) player.pt = 0;
		}

		/* トリガー 1 が押されたら色変更 */
		if ((stk & 0x40) == 0  &&  ((pre_stk & 0x40) != 0  ||  timer > 32)) {
			if ((player.info & 0x0F00) == 0x0F00) {
				player.info &= 0xF0FF;		/* カラーコードを 0 に戻す */
			} else {
				player.info += 0x100;		/* カラーコードを 1 加算 */
			}
		}

		/* pt info を画面に表示 */
		_iocs_b_locate(0, 5);
		printf("  pt = %3X \n", player.pt);
		printf("info = %3X \n", player.info);

		/* スプライトの表示登録 */
		_xobj_set(player.x, player.y, player.pt, player.info);
		/*
			↑ここは、
			xobj_set_st(&player);
			と記述すれば、より高速に実行できる。
		*/

		/* スプライトを一括表示する */
		_xsp_out();
	}


	/*-----------------------[ 終了処理 ]-----------------------*/

	/* XSP の終了処理 */
	_xsp_off();

	/* 画面モードを戻す */
	_iocs_crtmod(0x10);
}


