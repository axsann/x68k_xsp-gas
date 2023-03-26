# この makefile はUnix 互換環境上で利用することを想定している。

CROSS = m68k-xelf-
CC = $(CROSS)gcc
AS = $(CROSS)as
LD = $(CROSS)gcc
RUN68 = ../../run68/run68

# 最終生成物
EXECUTABLE = main.x
TARGET = $(EXECUTABLE) ZAKO.ref ZAKO.frm ZAKO.xsp

# ヘッダ検索パス
INCLUDE_FLAGS = -I../../download/m68k-xelf/m68k-elf/include

# コンパイルフラグ
COMMON_FLAGS = -m68000 -O2 $(INCLUDE_FLAGS)
CFLAGS = $(COMMON_FLAGS)

# *.c ソースファイル
C_SRCS = main.c

# リンク対象のライブラリファイル
LIBS = ../../XSP/XSP2lib.o

# *.c ソースファイル
C_SRCS = main.c

LDFLAGS =

LIBS =  ../../XSP/XSP2lib.o

# デフォルトのターゲット
all : $(TARGET)

$(TARGET): main.o
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	-rm -f *.o *.elf* $(TARGET)


# スプライトデータの変換
#	コンバータの終了コードが正しくなく、make がエラーとみなしてしまう。
#	修正を試みたいが残念ながらコンバータのソースコードが失われている。
#	ここでは終了コードを無視することで問題を回避する。
IGNORE_EXIT_STATUS = || :
ZAKO.ref ZAKO.frm ZAKO.xsp: ZAKO.src ZAKO.SP
	$(RUN68) ../../CVOBJ/CVOBJ.X -A ZAKO.src $(IGNORE_EXIT_STATUS)
