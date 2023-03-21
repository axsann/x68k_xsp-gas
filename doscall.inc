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

.equ	__EXIT,			0xff00
.equ	__GETCHAR,		0xff01
.equ	__PUTCHAR,		0xff02
.equ	__COMINP,		0xff03
.equ	__COMOUT,		0xff04
.equ	__PRNOUT,		0xff05
.equ	__INPOUT,		0xff06
.equ	__INKEY,		0xff07
.equ	__GETC,			0xff08
.equ	__PRINT,		0xff09
.equ	__GETS,			0xff0a
.equ	__KEYSNS,		0xff0b
.equ	__KFLUSH,		0xff0c
.equ	__FFLUSH,		0xff0d
.equ	__CHGDRV,		0xff0e
.equ	__CHDRV,		0xff0e
.equ	__DRVCTRL,		0xff0f
.equ	__CONSNS,		0xff10
.equ	__PRNSNS,		0xff11
.equ	__CINSNS,		0xff12
.equ	__COUTSNS,		0xff13
.equ	__FATCHK,		0xff17
.equ	__HENDSP,		0xff18
.equ	__CURDRV,		0xff19
.equ	__GETSS,		0xff1a
.equ	__FGETC,		0xff1b
.equ	__FGETS,		0xff1c
.equ	__FPUTC,		0xff1d
.equ	__FPUTS,		0xff1e
.equ	__ALLCLOSE,		0xff1f
.equ	__SUPER,		0xff20
.equ	__FNCKEY,		0xff21
.equ	__KNJCTRL,		0xff22
.equ	__CONCTRL,		0xff23
.equ	__KEYCTRL,		0xff24
.equ	__INTVCS,		0xff25
.equ	__PSPSET,		0xff26
.equ	__GETTIM2,		0xff27
.equ	__SETTIM2,		0xff28
.equ	__NAMESTS,		0xff29
.equ	__GETDATE,		0xff2a
.equ	__SETDATE,		0xff2b
.equ	__GETTIME,		0xff2c
.equ	__SETTIME,		0xff2d
.equ	__VERIFY,		0xff2e
.equ	__DUP0,			0xff2f
.equ	__VERNUM,		0xff30
.equ	__KEEPPR,		0xff31
.equ	__GETDPB,		0xff32
.equ	__BREAKCK,		0xff33
.equ	__DRVXCHG,		0xff34
.equ	__INTVCG,		0xff35
.equ	__DSKFRE,		0xff36
.equ	__NAMECK,		0xff37
.equ	__MKDIR,		0xff39
.equ	__RMDIR,		0xff3a
.equ	__CHDIR,		0xff3b
.equ	__CREATE,		0xff3c
.equ	__OPEN,			0xff3d
.equ	__CLOSE,		0xff3e
.equ	__READ,			0xff3f
.equ	__WRITE,		0xff40
.equ	__DELETE,		0xff41
.equ	__SEEK,			0xff42
.equ	__CHMOD,		0xff43
.equ	__IOCTRL,		0xff44
.equ	__DUP,			0xff45
.equ	__DUP2,			0xff46
.equ	__CURDIR,		0xff47
.equ	__MALLOC,		0xff48
.equ	__MFREE,		0xff49
.equ	__SETBLOCK,		0xff4a
.equ	__EXEC,			0xff4b
.equ	__EXIT2,		0xff4c
.equ	__WAIT,			0xff4d
.equ	__FILES,		0xff4e
.equ	__NFILES,		0xff4f

.equ	__V2_SETPDB,	0xff50
.equ	__V2_GETPDB,	0xff51
.equ	__V2_SETENV,	0xff52
.equ	__V2_GETENV,	0xff53
.equ	__V2_VERIFYG,	0xff54
.equ	__V2_COMMON,	0xff55
.equ	__V2_RENAME,	0xff56
.equ	__V2_FILEDATE,	0xff57
.equ	__V2_MALLOC2,	0xff58
.equ	__V2_MAKETMP,	0xff5a
.equ	__V2_NEWFILE,	0xff5b
.equ	__V2_LOCK,		0xff5c
.equ	__V2_ASSIGN,	0xff5f
.equ	__V2_FFLUSH_SET,0xff7a
.equ	__V2_OS_PATCH,	0xff7b
.equ	__V2_GETFCB,	0xff7c
.equ	__V2_S_MALLOC,	0xff7d
.equ	__V2_S_MFREE,	0xff7e
.equ	__V2_S_PROCESS,	0xff7f

.equ	__SETPDB,		0xff80
.equ	__GETPDB,		0xff81
.equ	__SETENV,		0xff82
.equ	__GETENV,		0xff83
.equ	__VERIFYG,		0xff84
.equ	__COMMON,		0xff85
.equ	__RENAME,		0xff86
.equ	__FILEDATE,		0xff87
.equ	__MALLOC2,		0xff88
.equ	__MAKETMP,		0xff8a
.equ	__NEWFILE,		0xff8b
.equ	__LOCK,			0xff8c
.equ	__ASSIGN,		0xff8f
.equ	__FFLUSH_SET,	0xffaa
.equ	__OS_PATCH,		0xffab
.equ	__GETFCB,		0xffac
.equ	__S_MALLOC,		0xffad
.equ	__S_MFREE,		0xffae
.equ	__S_PROCESS,	0xffaf

.equ	__RETSHELL,		0xfff0
.equ	__CTLABORT,		0xfff1
.equ	__ERRABORT,		0xfff2
.equ	__DISKRED,		0xfff3
.equ	__DISKWRT,		0xfff4
.equ	__INDOSFLG,		0xfff5
.equ	__SUPER_JSR,	0xfff6
.equ	__BUS_ERR,		0xfff7
.equ	__OPEN_PR,		0xfff8
.equ	__KILL_PR,		0xfff9
.equ	__GET_PR,		0xfffa
.equ	__SUSPEND_PR,	0xfffb
.equ	__SLEEP_PR,		0xfffc
.equ	__SEND_PR,		0xfffd
.equ	__TIME_PR,		0xfffe
.equ	__CHANGE_PR,	0xffff

.macro	DOS		callname
		.dc		\callname
.endm


.list
