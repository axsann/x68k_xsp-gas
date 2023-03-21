# この makefile はUnix 互換環境上で利用することを想定している。

CROSS = m68k-xelf-
AS = $(CROSS)as

# デフォルトサフィックスを削除
.SUFFIXES:

# 各種コマンド短縮名
#RUN68 = ${XDEV68K_DIR}/run68/run68
#HAS = $(RUN68) ${XDEV68K_DIR}/x68k_bin/HAS060.X

# 最終生成物
TARGET_FILE = XSP2lib.o

# ヘッダ検索パス
#INCLUDE_FLAGS = -I${XDEV68K_DIR}/include/xc -I${XDEV68K_DIR}/include/xdev68k
INCLUDE_FLAGS = -I./download/m68k-xelf/m68k-elf/include

# デフォルトのターゲット
all : $(TARGET_FILE)

# 中間生成物の削除
clean : 
	rm -f $(TARGET_FILE)

.PHONY: download
download:
	../scripts/download.sh

# *.s ソースのアセンブル
XSP2lib.o: XSPsys.s XSPfnc.s XSPmem.s XSPout.s XSPset.s XSPsetas.s XSP128.s XSP512.s XSP512b.s
	$(AS) -mcpu=68000 $(INCLUDE_FLAGS) -o $@ $<
