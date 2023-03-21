# この makefile はUnix 互換環境上で利用することを想定している。

CROSS = m68k-xelf-
AS = $(CROSS)as

# デフォルトサフィックスを削除
.SUFFIXES:

# 最終生成物
TARGET_FILE = XSP2lib.o

# ヘッダ検索パス
INCLUDE_FLAGS = -I../download/m68k-xelf/m68k-elf/include

# デフォルトのターゲット
all : $(TARGET_FILE)

# 中間生成物の削除
clean : 
	rm -f $(TARGET_FILE)

# *.s ソースのアセンブル
XSP2lib.o: XSPsys.s XSPfnc.s XSPmem.s XSPout.s XSPset.s XSPsetas.s XSP128.s XSP512.s XSP512b.s
	$(AS) -mcpu=68000 $(INCLUDE_FLAGS) -o $@ $<
