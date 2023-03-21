# この makefile はUnix 互換環境上で利用することを想定している。

CROSS = m68k-xelf-
CC = $(CROSS)gcc
AS = $(CROSS)as
LD = $(CROSS)gcc

# 最終生成物
TARGET = main.x

# ヘッダ検索パス
INCLUDE_FLAGS = -I../../download/m68k-xelf/m68k-elf/include

# コンパイルフラグ
COMMON_FLAGS = -m68000 -O2 $(INCLUDE_FLAGS)
CFLAGS = $(COMMON_FLAGS)

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
