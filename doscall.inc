#-----------------------------------------------------------------------------
# このファイルは、Project C Library の LIBC 1.1.32A ぱっち DON 版 (libcd4.tgz)
# に含まれていた doscall.mac を複製し、拡張子を inc にリネームし、
# モトローラ形式からMIT形式（GASフォーマット）に変換したものです。
#
# SHARP の XC コンパイラに含まれる doscall.mac の定義は、DOSLIB.L に含まれる
# シンボルと衝突するため、様々な問題を引き起こします。
# Project C Library 版 LIBC に含まれる doscall.mac は、この問題を回避するため
# doscall 番号の定義に __ で開始するシンボルを利用しています。
# 
# xdev68k では安全のため Project C Library 版の doscall.mac を利用します。
# また、ファイル名の混同を避けるため、拡張子を inc にリネームしています。
#
#
# オリジナルファイルは以下の URL から入手可能です。
# http://retropc.net/x68000/software/develop/lib/libcdon/
# このファイルのライセンスはオリジナルと同様 public domain とします。
# 以下、オリジナルファイルをそのまま収録いたします。
#-----------------------------------------------------------------------------
# -*-Fundamental-*-
#
# PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
# --------------------------------------------------------------------
# This file is written by the Project C Library Group,  and completely
# in public domain. You can freely use, copy, modify, and redistribute
# the whole contents, without this notice.
# --------------------------------------------------------------------
# $Id: doscall.mac,v 1.5 1993/10/06 16:43:41 mura Exp $
#

.nolist

.equ	__EXIT,		$ff00
.equ	__GETCHAR,		$ff01
.equ	__PUTCHAR,		$ff02
.equ	__COMINP,		$ff03
.equ	__COMOUT,		$ff04
.equ	__PRNOUT,		$ff05
.equ	__INPOUT,		$ff06
.equ	__INKEY,		$ff07
.equ	__GETC,		$ff08
.equ	__PRINT,		$ff09
.equ	__GETS,		$ff0a
.equ	__KEYSNS,		$ff0b
.equ	__KFLUSH,		$ff0c
.equ	__FFLUSH,		$ff0d
.equ	__CHGDRV,		$ff0e
.equ	__CHDRV,		$ff0e
.equ	__DRVCTRL,		$ff0f
.equ	__CONSNS,		$ff10
.equ	__PRNSNS,		$ff11
.equ	__CINSNS,		$ff12
.equ	__COUTSNS,		$ff13
.equ	__FATCHK,		$ff17
.equ	__HENDSP,		$ff18
.equ	__CURDRV,		$ff19
.equ	__GETSS,		$ff1a
.equ	__FGETC,		$ff1b
.equ	__FGETS,		$ff1c
.equ	__FPUTC,		$ff1d
.equ	__FPUTS,		$ff1e
.equ	__ALLCLOSE,	$ff1f
.equ	__SUPER,		$ff20
.equ	__FNCKEY,		$ff21
.equ	__KNJCTRL,		$ff22
.equ	__CONCTRL,		$ff23
.equ	__KEYCTRL,		$ff24
.equ	__INTVCS,		$ff25
.equ	__PSPSET,		$ff26
.equ	__GETTIM2,		$ff27
.equ	__SETTIM2,		$ff28
.equ	__NAMESTS,		$ff29
.equ	__GETDATE,		$ff2a
.equ	__SETDATE,		$ff2b
.equ	__GETTIME,		$ff2c
.equ	__SETTIME,		$ff2d
.equ	__VERIFY,		$ff2e
.equ	__DUP0,		$ff2f
.equ	__VERNUM,		$ff30
.equ	__KEEPPR,		$ff31
.equ	__GETDPB,		$ff32
.equ	__BREAKCK,		$ff33
.equ	__DRVXCHG,		$ff34
.equ	__INTVCG,		$ff35
.equ	__DSKFRE,		$ff36
.equ	__NAMECK,		$ff37
.equ	__MKDIR,		$ff39
.equ	__RMDIR,		$ff3a
.equ	__CHDIR,		$ff3b
.equ	__CREATE,		$ff3c
.equ	__OPEN,		$ff3d
.equ	__CLOSE,		$ff3e
.equ	__READ,		$ff3f
.equ	__WRITE,		$ff40
.equ	__DELETE,		$ff41
.equ	__SEEK,		$ff42
.equ	__CHMOD,		$ff43
.equ	__IOCTRL,		$ff44
.equ	__DUP,		$ff45
.equ	__DUP2,		$ff46
.equ	__CURDIR,		$ff47
.equ	__MALLOC,		$ff48
.equ	__MFREE,		$ff49
.equ	__SETBLOCK,	$ff4a
.equ	__EXEC,		$ff4b
.equ	__EXIT2,		$ff4c
.equ	__WAIT,		$ff4d
.equ	__FILES,		$ff4e
.equ	__NFILES,		$ff4f

.equ	__V2_SETPDB,	$ff50
.equ	__V2_GETPDB,	$ff51
.equ	__V2_SETENV,	$ff52
.equ	__V2_GETENV,	$ff53
.equ	__V2_VERIFYG,	$ff54
.equ	__V2_COMMON,	$ff55
.equ	__V2_RENAME,	$ff56
.equ	__V2_FILEDATE,	$ff57
.equ	__V2_MALLOC2,	$ff58
.equ	__V2_MAKETMP,	$ff5a
.equ	__V2_NEWFILE,	$ff5b
.equ	__V2_LOCK,		$ff5c
.equ	__V2_ASSIGN,	$ff5f
.equ	__V2_FFLUSH_SET,$ff7a
.equ	__V2_OS_PATCH,	$ff7b
.equ	__V2_GETFCB,	$ff7c
.equ	__V2_S_MALLOC,	$ff7d
.equ	__V2_S_MFREE,	$ff7e
.equ	__V2_S_PROCESS,$ff7f

.equ	__SETPDB,		$ff80
.equ	__GETPDB,		$ff81
.equ	__SETENV,		$ff82
.equ	__GETENV,		$ff83
.equ	__VERIFYG,		$ff84
.equ	__COMMON,		$ff85
.equ	__RENAME,		$ff86
.equ	__FILEDATE,	$ff87
.equ	__MALLOC2,		$ff88
.equ	__MAKETMP,		$ff8a
.equ	__NEWFILE,		$ff8b
.equ	__LOCK,		$ff8c
.equ	__ASSIGN,		$ff8f
.equ	__FFLUSH_SET,	$ffaa
.equ	__OS_PATCH,	$ffab
.equ	__GETFCB,		$ffac
.equ	__S_MALLOC,	$ffad
.equ	__S_MFREE,		$ffae
.equ	__S_PROCESS,	$ffaf

.equ	__RETSHELL,	$fff0
.equ	__CTLABORT,	$fff1
.equ	__ERRABORT,	$fff2
.equ	__DISKRED,		$fff3
.equ	__DISKWRT,		$fff4
.equ	__INDOSFLG,	$fff5
.equ	__SUPER_JSR,	$fff6
.equ	__BUS_ERR,		$fff7
.equ	__OPEN_PR,		$fff8
.equ	__KILL_PR,		$fff9
.equ	__GET_PR,		$fffa
.equ	__SUSPEND_PR,	$fffb
.equ	__SLEEP_PR,	$fffc
.equ	__SEND_PR,		$fffd
.equ	__TIME_PR,		$fffe
.equ	__CHANGE_PR,	$ffff

.macro	DOS		callname
		.dc		\callname
.endm


.list
