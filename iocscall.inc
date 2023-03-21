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

.equ	__B_KEYINP,		0x00	
.equ	__B_KEYSNS,		0x01	
.equ	__B_SFTSNS,		0x02	
.equ	__KEY_INIT,		0x03	
.equ	__BITSNS,		0x04	
.equ	__SKEYSET,		0x05	
.equ	__LEDCTRL,		0x06	
.equ	__LEDSET,		0x07	
.equ	__KEYDLY,		0x08	
.equ	__KEYREP,		0x09	
.equ	__OPT2TVCTRL,	0x0a	
.equ	__OPT2NORMAL,	0x0b	
.equ	__TVCTRL,		0x0c	
.equ	__LEDMOD,		0x0d	
.equ	__TGUSEMD,		0x0e	
.equ	__DEFCHR,		0x0f	
.equ	__CRTMOD,		0x10	
.equ	__CONTRAST,		0x11	
.equ	__HSVTORGB,		0x12	
.equ	__TPALET,		0x13	
.equ	__TPALET2,		0x14	
.equ	__TCOLOR,		0x15	
.equ	__FNTADR,		0x16	
.equ	__VRAMGET,		0x17	
.equ	__VRAMPUT,		0x18	
.equ	__FNTGET,		0x19	
.equ	__TEXTGET,		0x1a	
.equ	__TEXTPUT,		0x1b	
.equ	__CLIPPUT,		0x1c	
.equ	__SCROLL,		0x1d	
.equ	__B_CURON,		0x1e	
.equ	__B_CUROFF,		0x1f	
.equ	__B_PUTC,		0x20	
.equ	__B_PRINT,		0x21	
.equ	__B_COLOR,		0x22	
.equ	__B_LOCATE,		0x23	
.equ	__B_DOWN_S,		0x24	
.equ	__B_UP_S,		0x25	
.equ	__B_UP,		    0x26	
.equ	__B_DOWN,		0x27	
.equ	__B_RIGHT,		0x28	
.equ	__B_LEFT,		0x29	
.equ	__B_CLR_ST,		0x2a	
.equ	__B_ERA_ST,		0x2b	
.equ	__B_INS,		0x2c	
.equ	__B_DEL,		0x2d	
.equ	__B_CONSOL,		0x2e	
.equ	__B_PUTMES,		0x2f	
.equ	__SET232C,		0x30	
.equ	__LOF232C,		0x31	
.equ	__INP232C,		0x32	
.equ	__ISNS232C,		0x33	
.equ	__OSNS232C,		0x34	
.equ	__OUT232C,		0x35	
.equ	__SETMSADR,		0x36	
.equ	__SETESCADR,	0x37	
.equ	__SETFNTADR,	0x38	
.equ	__SET_BEEP,		0x39	
.equ	__SET_PRN,		0x3a	
.equ	__JOYGET,		0x3b	
.equ	__INIT_PRN,		0x3c	
.equ	__SNSPRN,		0x3d	
.equ	__OUTLPT,		0x3e	
.equ	__OUTPRN,		0x3f	
.equ	__B_SEEK,		0x40	
.equ	__B_VERIFY,		0x41	
.equ	__B_READDI,		0x42	
.equ	__B_DSKINI,		0x43	
.equ	__B_DRVSNS,		0x44	
.equ	__B_WRITE,		0x45	
.equ	__B_READ,		0x46	
.equ	__B_RECALI,		0x47	
.equ	__B_ASSIGN,		0x48	
.equ	__B_WRITED,		0x49	
.equ	__B_READID,		0x4a	
.equ	__B_BADFMT,		0x4b	
.equ	__B_READDL,		0x4c	
.equ	__B_FORMAT,		0x4d	
.equ	__B_DRVCHK,		0x4e	
.equ	__B_EJECT,		0x4f	
.equ	__DATEBCD,		0x50	
.equ	__DATESET,		0x51	
.equ	__TIMEBCD,		0x52	
.equ	__TIMESET,		0x53	
.equ	__DATEGET,		0x54	
.equ	__DATEBIN,		0x55	
.equ	__TIMEGET,		0x56	
.equ	__TIMEBIN,		0x57	
.equ	__DATECNV,		0x58	
.equ	__TIMECNV,		0x59	
.equ	__DATEASC,		0x5a	
.equ	__TIMEASC,		0x5b	
.equ	__DAYASC,		0x5c	
.equ	__ALARMMOD,		0x5d	
.equ	__ALARMSET,		0x5e	
.equ	__ALARMGET,		0x5f	
.equ	__ADPCMOUT,		0x60	
.equ	__ADPCMINP,		0x61	
.equ	__ADPCMAOT,		0x62	
.equ	__ADPCMAIN,		0x63	
.equ	__ADPCMLOT,		0x64	
.equ	__ADPCMLIN,		0x65	
.equ	__ADPCMSNS,		0x66	
.equ	__ADPCMMOD,		0x67	
.equ	__OPMSET,		0x68	
.equ	__OPMSNS,		0x69	
.equ	__OPMINTST,		0x6a	
.equ	__TIMERDST,		0x6b	
.equ	__VDISPST,		0x6c	
.equ	__CRTCRAS,		0x6d	
.equ	__HSYNCST,		0x6e	
.equ	__PRNINTST,		0x6f	
.equ	__MS_INIT,		0x70	
.equ	__MS_CURON,		0x71	
.equ	__MS_CUROF,		0x72	
.equ	__MS_STAT,		0x73	
.equ	__MS_GETDT,		0x74	
.equ	__MS_CURGT,		0x75	
.equ	__MS_CURST,		0x76	
.equ	__MS_LIMIT,		0x77	
.equ	__MS_OFFTM,		0x78	
.equ	__MS_ONTM,		0x79	
.equ	__MS_PATST,		0x7a	
.equ	__MS_SEL,		0x7b	
.equ	__MS_SEL2,		0x7c	
.equ	__SKEY_MOD,		0x7d	
.equ	__DENSNS,		0x7e	
.equ	__ONTIME,		0x7f	
.equ	__B_INTVCS,		0xffffff80	
.equ	__B_SUPER,		0xffffff81	
.equ	__B_BPEEK,		0xffffff82	
.equ	__B_WPEEK,		0xffffff83	
.equ	__B_LPEEK,		0xffffff84
.equ	__B_MEMSTR,		0xffffff85
.equ	__B_BPOKE,		0xffffff86
.equ	__B_WPOKE,		0xffffff87	
.equ	__B_LPOKE,		0xffffff88	
.equ	__B_MEMSET,		0xffffff89	
.equ	__DMAMOVE,		0xffffff8a	
.equ	__DMAMOV_A,		0xffffff8b	
.equ	__DMAMOV_L,		0xffffff8c	
.equ	__DMAMODE,		0xffffff8d	
.equ	__BOOTINF,		0xffffff8e	
.equ	__ROMVER,		0xffffff8f	
.equ	__G_CLR_ON,		0xffffff90	
.equ	__VC_R0,		0xffffff91	
.equ	__VC_R1,		0xffffff92	
.equ	__VC_R2,		0xffffff93	
.equ	__GPALET,		0xffffff94	
.equ	__GCOLOR,		0xffffff95	
.equ	__APAGE2,		0xffffff96	
.equ	__GV_GET,		0xffffff97	
.equ	__GV_PUT2,		0xffffff98	
.equ	__GV_PUT,		0xffffff99	
.equ	__GBITPUT,		0xffffff9a	
.equ	__GBITPUT2,		0xffffff9b	
.equ	__GBITPUT3,		0xffffff9c	
.equ	__SFTJIS,		0xffffffa0	
.equ	__JISSFT,		0xffffffa1	
.equ	__AKCONV,		0xffffffa2	
.equ	__RMACNV,		0xffffffa3	
.equ	__DAKJOB,		0xffffffa4	
.equ	__HANJOB,		0xffffffa5	
.equ	__SYS_STAT,		0xffffffac     |# enhanced by ROM IOCS ver 1.3
.equ	__B_CONMOD,		0xffffffad     |# enhanced by iocs.x
.equ	__OS_CURON,		0xffffffae	
.equ	__OS_CUROF,		0xffffffaf	
.equ	__DRAWMODE,		0xffffffb0     |# enhanced by iocs.x
.equ	__APAGE,		0xffffffb1	
.equ	__VPAGE,		0xffffffb2	
.equ	__HOME,		    0xffffffb3	
.equ	__WINDOW,		0xffffffb4	
.equ	__WIPE,		    0xffffffb5	
.equ	__PSET,		    0xffffffb6	
.equ	__POINT,		0xffffffb7	
.equ	__LINE,		    0xffffffb8	
.equ	__BOX,		    0xffffffb9	
.equ	__FILL,		    0xffffffba	
.equ	__CIRCLE,		0xffffffbb	
.equ	__PAINT,		0xffffffbc	
.equ	__SYMBOL,		0xffffffbd	
.equ	__GETGRM,		0xffffffbe	
.equ	__PUTGRM,		0xffffffbf	
.equ	__SP_INIT,		0xffffffc0	
.equ	__SP_ON,		0xffffffc1	
.equ	__SP_OFF,		0xffffffc2	
.equ	__SP_CGCLR,		0xffffffc3	
.equ	__SP_DEFCG,		0xffffffc4	
.equ	__SP_GTPCG,		0xffffffc5	
.equ	__SP_REGST,		0xffffffc6	
.equ	__SP_REGGT,		0xffffffc7	
.equ	__BGSCRLST,		0xffffffc8	
.equ	__BGSCRLGT,		0xffffffc9	
.equ	__BGCTRLST,		0xffffffca	
.equ	__BGCTRLGT,		0xffffffcb	
.equ	__BGTEXTCL,		0xffffffcc	
.equ	__BGTEXTST,		0xffffffcd	
.equ	__BGTEXTGT,		0xffffffce	
.equ	__SPALET,		0xffffffcf	
.equ	__TXXLINE,		0xffffffd3	
.equ	__TXYLINE,		0xffffffd4	
.equ	__TXLINE,		0xffffffd5     |# enhanced by iocs.x
.equ	__TXBOX,		0xffffffd6	
.equ	__TXFILL,		0xffffffd7	
.equ	__TXREV,		0xffffffd8	
.equ	__TXRASCPY,		0xffffffdf
.equ	__OPMDRV,		0xfffffff0     |# enhanced by opmdrv.sys
.equ	__RSDRV,		0xfffffff1     |# enhanced by rsdrv.sys
.equ	__A_JOY,		0xfffffff2     |# enhanced by ajoy.x
.equ	__SCSIDRV,		0xfffffff5	
.equ	__ABORTRST,		0xfffffffd	
.equ	__IPLERR,		0xfffffffe	
.equ	__ABORTJOB,		0xffffffff	

.equ	__S_RESET,		0x00	
.equ	__S_SELECT,		0x01	
.equ	__S_SELECTA,	0x02	
.equ	__S_CMDOUT,		0x03	
.equ	__S_DATAIN,		0x04	
.equ	__S_DATAOUT,	0x05	
.equ	__S_STSIN,		0x06	
.equ	__S_MSGIN,		0x07	
.equ	__S_MSGOUT,		0x08	
.equ	__S_PHASE,		0x09
.equ	__S_LEVEL,		0x0a     |# undefined
.equ	__S_DATAIN_P,	0x0b     |# undefined
.equ	__S_DATAOUT_P,	0x0c     |# undefined
.equ	__S_MSGOUTEXT,	0x0d     |# undefined
.equ	__S_INQUIRY,	0x20	
.equ	__S_READ,		0x21	
.equ	__S_WRITE,		0x22	
.equ	__S_FORMAT,		0x23	
.equ	__S_TESTUNIT,	0x24	
.equ	__S_READCAP,	0x25	
.equ	__S_READEXT,	0x26	
.equ	__S_WRITEEXT,	0x27	
.equ	__S_VERIFYEXT,	0x28     |# undefined
.equ	__S_MODESENSE,	0x29     |# undefined
.equ	__S_MODESELECT,	0x2a     |# undefined
.equ	__S_REZEROUNIT,	0x2b	
.equ	__S_REQUEST,	0x2c	
.equ	__S_SEEK,		0x2d	
.equ	__S_READI,		0x2e     |# undefined
.equ	__S_STARTSTOP,	0x2f	
.equ	__S_EJECT6MO1,	0x30     |# undefined
.equ	__S_REASSIGN,	0x31	
.equ	__S_PAMEDIUM,	0x32	

# Macros
.macro SCSI func
	moveq.l #\func, 	%d0	
	moveq.l #0xf5,	    %d1	
	trap #15
.endm

.macro IOCS number
	moveq.l #\number,   %d0	
	trap #15
.endm

.list
