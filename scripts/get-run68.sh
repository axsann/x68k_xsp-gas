#!/usr/bin/env bash

#------------------------------------------------------------------------------
#
#	get-run68.sh
#
#		run68 をダウンロード
#
#------------------------------------------------------------------------------

ROOT_DIR="${PWD}"
DOWNLOAD_DIR="${ROOT_DIR}/download"

# ディレクトリ作成
mkdir -p ${DOWNLOAD_DIR}
cd ${DOWNLOAD_DIR}

#------------------------------------------------------------------------------
# run68 コマンドをソースからビルドしインストール
#------------------------------------------------------------------------------
#
#	Copyright (C) 2022 Yosshin(@yosshin4004)
#
#	Licensed under the Apache License, Version 2.0 (the "License");
#	you may not use this file except in compliance with the License.
#	You may obtain a copy of the License at
#
#	    http://www.apache.org/licenses/LICENSE-2.0
#
#	Unless required by applicable law or agreed to in writing, software
#	distributed under the License is distributed on an "AS IS" BASIS,
#	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#	See the License for the specific language governing permissions and
#	limitations under the License.
#
#------------------------------------------------------------------------------
ARCHIVE="master.zip"
wget -nc https://github.com/yosshin4004/run68mac/archive/refs/heads/${ARCHIVE}
unzip ${ARCHIVE}
cd run68mac-master/
mkdir build
cd build

# https://github.com/yosshin4004/xdev68k/issues/4
# に従い -G"Unix Makefiles" を付加した。
cmake -G"Unix Makefiles" ..

make
cd ../
cd ..

# インストール
cp -p run68mac-master/build/run68* ../run68/
cp -p ${ARCHIVE} run68mac-${ARCHIVE}

# run68.ini が正しく認識されていることを確認
if [ "$(expr substr $(uname -s) 1 5)" == "MINGW" ]; then
	MEMSIZE=`../run68/run68 ..\\\\x68k_bin\\\\MEMSIZE.X`
else
	MEMSIZE=`../run68/run68 ../run68/x68k_bin/MEMSIZE.X`
fi
echo "available memory size on run68 is ${MEMSIZE} bytes"
if [ ${MEMSIZE} -lt 2097152 ]; then
	echo "run68 memory size test failed!"
	exit 1
fi


#------------------------------------------------------------------------------
# 正常終了
#------------------------------------------------------------------------------

echo ""
echo "-----------------------------------------------------------------------------"
echo "Installation process completed."
echo "-----------------------------------------------------------------------------"
echo ""
exit 0
