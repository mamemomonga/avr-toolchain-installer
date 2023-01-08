# AVR toolchain installer

* macOS Ventura で AVRのビルドと書込をするための環境を整えるツール
* microchip(atmel)提供のToolchainとDFPを使用する
* avrdudeはソースからビルドされる。

# インストール

## macOSの場合

macOSの場合は、事前に以下のライブラリを入れておく

	$ brew install cmake libelf libusb libftdi

## 実行

1. [AVR® and Arm® Toolchains (C Compilers)](https://www.microchip.com/en-us/development-tools-tools-and-software/gcc-compilers-avr-and-arm) から **AVR 8-bit Toolchain 3.7.0 - Mac OS X 64-bit**(avr8-gnu-toolchain-osx-3.7.0.518-darwin.any.x86_64.tar.gz) をダウンロードし、download フォルダに置く。ない場合は自動的にダウンロードされる。

2. [Microchip Packs Repository](http://packs.download.atmel.com) から **Atmel ATmega Series Device Support (2.0.401)** (Atmel.ATmega_DFP.2.0.401) と **Atmel ATtiny Series Device Support (2.0.368)** (Atmel.ATtiny_DFP.2.0.368) をダウンロードし、downloadフォルダに置く。ない場合は自動的にダウンロードされる。

3. [AVRDUDE](https://github.com/avrdudes/avrdude) を download に clone してください。ない場合は自動的にcloneされる。

4. config.mk を開き、ダウンロードしたファイル名やバージョンが(AVR_TOOLCHAINSのみ拡張子あり) があっているか確認。

5. make を実行

# 利用方法

以下のコマンドを実行することで、avr-gccが有効になる。

	$ . ~/avr/enable.sh

# Lチカサンプル

[blink](./blink)フォルダ参照。

# 参考リンク

## SerialUPDI

* [SerialUPDI](https://github.com/SpenceKonde/AVR-Guidance/blob/master/UPDI/jtag2updi.md)
* [avrdude 5.3 SerialUPDI programmer](https://avrdudes.github.io/avrdude/7.0/avrdude_19.html#SerialUPDI-programmer)

