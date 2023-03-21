#-----------------------------------------------------------------------------
# このファイルは、Project C Library の LIBC 1.1.32A ぱっち DON 版 (libcd4.tgz)
# に含まれていた iocscall.mac を複製し、拡張子を inc にリネームし、
# モトローラ形式からMIT形式（GASフォーマット）に変換したものです。
#
# SHARP の XC コンパイラに含まれる iocscall.mac の定義は、IOCSLIB.L に含まれる
# シンボルと衝突するため、様々な問題を引き起こします。
# Project C Library 版 LIBC に含まれる iocscall.mac は、この問題を回避するため
# iocscall 番号の定義に __ で開始するシンボルを利用しています。
# 
# xdev68k では安全のため Project C Library 版の iocscall.mac を利用します。
# また、ファイル名の混同を避けるため、拡張子を inc にリネームしています。
#
#
# オリジナルファイルは以下の URL から入手可能です。
# http://retropc.net/x68000/software/develop/lib/libcdon/
# このファイルのライセンスはオリジナルと同様 public domain とします。
#-----------------------------------------------------------------------------
# -*-Fundamental-*-
#
# PROJECT C Library,		X68000 PROGRAMMING INTERFACE DEFINITION	
# --------------------------------------------------------------------
# This file is written by the Project C Library Group,		 and completely	
# in public domain. You can freely use,		copy, modify, and redistribute	
# the whole contents,		without this notice.	
# --------------------------------------------------------------------
# $Id: iocscall.mac,v 1.5 1993/10/06 16:44:09 mura Exp $
#

.nolist

.equ	__B_KEYINP,		$00	
.equ	__B_KEYSNS,		$01	
.equ	__B_SFTSNS,		$02	
.equ	__KEY_INIT,		$03	
.equ	__BITSNS,		$04	
.equ	__SKEYSET,		$05	
.equ	__LEDCTRL,		$06	
.equ	__LEDSET,		$07	
.equ	__KEYDLY,		$08	
.equ	__KEYREP,		$09	
.equ	__OPT2TVCTRL,	$0a	
.equ	__OPT2NORMAL,	$0b	
.equ	__TVCTRL,		$0c	
.equ	__LEDMOD,		$0d	
.equ	__TGUSEMD,		$0e	
.equ	__DEFCHR,		$0f	
.equ	__CRTMOD,		$10	
.equ	__CONTRAST,		$11	
.equ	__HSVTORGB,		$12	
.equ	__TPALET,		$13	
.equ	__TPALET2,		$14	
.equ	__TCOLOR,		$15	
.equ	__FNTADR,		$16	
.equ	__VRAMGET,		$17	
.equ	__VRAMPUT,		$18	
.equ	__FNTGET,		$19	
.equ	__TEXTGET,		$1a	
.equ	__TEXTPUT,		$1b	
.equ	__CLIPPUT,		$1c	
.equ	__SCROLL,		$1d	
.equ	__B_CURON,		$1e	
.equ	__B_CUROFF,		$1f	
.equ	__B_PUTC,		$20	
.equ	__B_PRINT,		$21	
.equ	__B_COLOR,		$22	
.equ	__B_LOCATE,		$23	
.equ	__B_DOWN_S,		$24	
.equ	__B_UP_S,		$25	
.equ	__B_UP,		    $26	
.equ	__B_DOWN,		$27	
.equ	__B_RIGHT,		$28	
.equ	__B_LEFT,		$29	
.equ	__B_CLR_ST,		$2a	
.equ	__B_ERA_ST,		$2b	
.equ	__B_INS,		$2c	
.equ	__B_DEL,		$2d	
.equ	__B_CONSOL,		$2e	
.equ	__B_PUTMES,		$2f	
.equ	__SET232C,		$30	
.equ	__LOF232C,		$31	
.equ	__INP232C,		$32	
.equ	__ISNS232C,		$33	
.equ	__OSNS232C,		$34	
.equ	__OUT232C,		$35	
.equ	__SETMSADR,		$36	
.equ	__SETESCADR,	$37	
.equ	__SETFNTADR,	$38	
.equ	__SET_BEEP,		$39	
.equ	__SET_PRN,		$3a	
.equ	__JOYGET,		$3b	
.equ	__INIT_PRN,		$3c	
.equ	__SNSPRN,		$3d	
.equ	__OUTLPT,		$3e	
.equ	__OUTPRN,		$3f	
.equ	__B_SEEK,		$40	
.equ	__B_VERIFY,		$41	
.equ	__B_READDI,		$42	
.equ	__B_DSKINI,		$43	
.equ	__B_DRVSNS,		$44	
.equ	__B_WRITE,		$45	
.equ	__B_READ,		$46	
.equ	__B_RECALI,		$47	
.equ	__B_ASSIGN,		$48	
.equ	__B_WRITED,		$49	
.equ	__B_READID,		$4a	
.equ	__B_BADFMT,		$4b	
.equ	__B_READDL,		$4c	
.equ	__B_FORMAT,		$4d	
.equ	__B_DRVCHK,		$4e	
.equ	__B_EJECT,		$4f	
.equ	__DATEBCD,		$50	
.equ	__DATESET,		$51	
.equ	__TIMEBCD,		$52	
.equ	__TIMESET,		$53	
.equ	__DATEGET,		$54	
.equ	__DATEBIN,		$55	
.equ	__TIMEGET,		$56	
.equ	__TIMEBIN,		$57	
.equ	__DATECNV,		$58	
.equ	__TIMECNV,		$59	
.equ	__DATEASC,		$5a	
.equ	__TIMEASC,		$5b	
.equ	__DAYASC,		$5c	
.equ	__ALARMMOD,		$5d	
.equ	__ALARMSET,		$5e	
.equ	__ALARMGET,		$5f	
.equ	__ADPCMOUT,		$60	
.equ	__ADPCMINP,		$61	
.equ	__ADPCMAOT,		$62	
.equ	__ADPCMAIN,		$63	
.equ	__ADPCMLOT,		$64	
.equ	__ADPCMLIN,		$65	
.equ	__ADPCMSNS,		$66	
.equ	__ADPCMMOD,		$67	
.equ	__OPMSET,		$68	
.equ	__OPMSNS,		$69	
.equ	__OPMINTST,		$6a	
.equ	__TIMERDST,		$6b	
.equ	__VDISPST,		$6c	
.equ	__CRTCRAS,		$6d	
.equ	__HSYNCST,		$6e	
.equ	__PRNINTST,		$6f	
.equ	__MS_INIT,		$70	
.equ	__MS_CURON,		$71	
.equ	__MS_CUROF,		$72	
.equ	__MS_STAT,		$73	
.equ	__MS_GETDT,		$74	
.equ	__MS_CURGT,		$75	
.equ	__MS_CURST,		$76	
.equ	__MS_LIMIT,		$77	
.equ	__MS_OFFTM,		$78	
.equ	__MS_ONTM,		$79	
.equ	__MS_PATST,		$7a	
.equ	__MS_SEL,		$7b	
.equ	__MS_SEL2,		$7c	
.equ	__SKEY_MOD,		$7d	
.equ	__DENSNS,		$7e	
.equ	__ONTIME,		$7f	
.equ	__B_INTVCS,		$80	
.equ	__B_SUPER,		$81	
.equ	__B_BPEEK,		$82	
.equ	__B_WPEEK,		$83	
.equ	__B_LPEEK,		$84	
.equ	__B_MEMSTR,		$85	
.equ	__B_BPOKE,		$86	
.equ	__B_WPOKE,		$87	
.equ	__B_LPOKE,		$88	
.equ	__B_MEMSET,		$89	
.equ	__DMAMOVE,		$8a	
.equ	__DMAMOV_A,		$8b	
.equ	__DMAMOV_L,		$8c	
.equ	__DMAMODE,		$8d	
.equ	__BOOTINF,		$8e	
.equ	__ROMVER,		$8f	
.equ	__G_CLR_ON,		$90	
.equ	__VC_R0,		$91	
.equ	__VC_R1,		$92	
.equ	__VC_R2,		$93	
.equ	__GPALET,		$94	
.equ	__GCOLOR,		$95	
.equ	__APAGE2,		$96	
.equ	__GV_GET,		$97	
.equ	__GV_PUT2,		$98	
.equ	__GV_PUT,		$99	
.equ	__GBITPUT,		$9a	
.equ	__GBITPUT2,		$9b	
.equ	__GBITPUT3,		$9c	
.equ	__SFTJIS,		$a0	
.equ	__JISSFT,		$a1	
.equ	__AKCONV,		$a2	
.equ	__RMACNV,		$a3	
.equ	__DAKJOB,		$a4	
.equ	__HANJOB,		$a5	
.equ	__SYS_STAT,		$ac     |# enhanced by ROM IOCS ver 1.3
.equ	__B_CONMOD,		$ad     |# enhanced by iocs.x
.equ	__OS_CURON,		$ae	
.equ	__OS_CUROF,		$af	
.equ	__DRAWMODE,		$b0     |# enhanced by iocs.x
.equ	__APAGE,		$b1	
.equ	__VPAGE,		$b2	
.equ	__HOME,		    $b3	
.equ	__WINDOW,		$b4	
.equ	__WIPE,		    $b5	
.equ	__PSET,		    $b6	
.equ	__POINT,		$b7	
.equ	__LINE,		    $b8	
.equ	__BOX,		    $b9	
.equ	__FILL,		    $ba	
.equ	__CIRCLE,		$bb	
.equ	__PAINT,		$bc	
.equ	__SYMBOL,		$bd	
.equ	__GETGRM,		$be	
.equ	__PUTGRM,		$bf	
.equ	__SP_INIT,		$c0	
.equ	__SP_ON,		$c1	
.equ	__SP_OFF,		$c2	
.equ	__SP_CGCLR,		$c3	
.equ	__SP_DEFCG,		$c4	
.equ	__SP_GTPCG,		$c5	
.equ	__SP_REGST,		$c6	
.equ	__SP_REGGT,		$c7	
.equ	__BGSCRLST,		$c8	
.equ	__BGSCRLGT,		$c9	
.equ	__BGCTRLST,		$ca	
.equ	__BGCTRLGT,		$cb	
.equ	__BGTEXTCL,		$cc	
.equ	__BGTEXTST,		$cd	
.equ	__BGTEXTGT,		$ce	
.equ	__SPALET,		$cf	
.equ	__TXXLINE,		$d3	
.equ	__TXYLINE,		$d4	
.equ	__TXLINE,		$d5     |# enhanced by iocs.x
.equ	__TXBOX,		$d6	
.equ	__TXFILL,		$d7	
.equ	__TXREV,		$d8	
.equ	__TXRASCPY,		$df
.equ	__OPMDRV,		$f0     |# enhanced by opmdrv.sys
.equ	__RSDRV,		$f1     |# enhanced by rsdrv.sys
.equ	__A_JOY,		$f2     |# enhanced by ajoy.x
.equ	__SCSIDRV,		$f5	
.equ	__ABORTRST,		$fd	
.equ	__IPLERR,		$fe	
.equ	__ABORTJOB,		$ff	

.equ	__S_RESET,		$00	
.equ	__S_SELECT,		$01	
.equ	__S_SELECTA,	$02	
.equ	__S_CMDOUT,		$03	
.equ	__S_DATAIN,		$04	
.equ	__S_DATAOUT,	$05	
.equ	__S_STSIN,		$06	
.equ	__S_MSGIN,		$07	
.equ	__S_MSGOUT,		$08	
.equ	__S_PHASE,		$09
.equ	__S_LEVEL,		$0a     |# undefined
.equ	__S_DATAIN_P,	$0b     |# undefined
.equ	__S_DATAOUT_P,	$0c     |# undefined
.equ	__S_MSGOUTEXT,	$0d     |# undefined
.equ	__S_INQUIRY,	$20	
.equ	__S_READ,		$21	
.equ	__S_WRITE,		$22	
.equ	__S_FORMAT,		$23	
.equ	__S_TESTUNIT,	$24	
.equ	__S_READCAP,	$25	
.equ	__S_READEXT,	$26	
.equ	__S_WRITEEXT,	$27	
.equ	__S_VERIFYEXT,	$28     |# undefined
.equ	__S_MODESENSE,	$29     |# undefined
.equ	__S_MODESELECT,	$2a     |# undefined
.equ	__S_REZEROUNIT,	$2b	
.equ	__S_REQUEST,	$2c	
.equ	__S_SEEK,		$2d	
.equ	__S_READI,		$2e     |# undefined
.equ	__S_STARTSTOP,	$2f	
.equ	__S_EJECT6MO1,	$30     |# undefined
.equ	__S_REASSIGN,	$31	
.equ	__S_PAMEDIUM,	$32	

# Macros
.macro SCSI func
	moveq.l #\func, 	%d0	
	moveq.l #$f5,	    %d1	
	trap #15
.endm

.macro IOCS number
	moveq.l #\number,   %d0	
	trap #15
.endm

.list
