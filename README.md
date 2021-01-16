# AVR toolchain installer

* macOS Caralina で AVRのビルドと書込をするための環境を整えるツール
* microchip(atmel)提供のToolchainとDFPを使用する
* avrdudeはソースからビルドされる。

# インストール開始

1. [AVR® and Arm® Toolchains (C Compilers)](https://www.microchip.com/en-us/development-tools-tools-and-software/gcc-compilers-avr-and-arm) から **AVR 8-bit Toolchain 3.6.2 - Mac OS X 64-bit**(avr8-gnu-toolchain-osx-3.6.2.514-darwin.any.x86_64.tar.gz) をダウンロードし、download フォルダに置く(要microchipアカウント)

2. [Microchip Packs Repository](http://packs.download.atmel.com) から **Atmel ATmega Series Device Support (1.6.364)** (Atmel.ATmega_DFP.1.6.364.atpack) と **Atmel ATtiny Series Device Support (1.8.332)** (Atmel.ATtiny_DFP.1.8.332.atpack) をダウンロードし、downloadフォルダに置く。ない場合は自動的にダウンロードされる。

3. [AVRDUDE](https://www.nongnu.org/avrdude/) の [download area](http://download.savannah.gnu.org/releases/avrdude/) から [avrdude-6.3.tar.gz](http://download.savannah.gnu.org/releases/avrdude/avrdude-6.3.tar.gz) をダウンロードし、downloadフォルダに置く。ない場合は自動的にダウンロードされる。

4. config.mk を開き、ダウンロードしたファイル名やバージョンが(AVR_TOOLCHAINSのみ拡張子あり) があっているか確認。

5. make を実行

# 利用方法

以下のコマンドを実行することで、avr-gccが有効になる。

	$ . ~/avr/enable.sh

# Lチカサンプル

[blink](./blink)フォルダ参照。
