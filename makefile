# この makefile はUnix 互換環境上で利用することを想定している。

# 依存関係をダウンロード
.PHONY: download
download:
	./scripts/get-elf2x68k.sh \
	&& ./scripts/get-run68.sh

clean:
	rm -rf ./download && rm -f run68/run68
