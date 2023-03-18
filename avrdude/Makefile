# macOS Ventura + HomeBrew用
# debian だと apt-get install cmake bison flex

INSTALL_PREFIX ?= "$(HOME)/avr"
REQUIMENT_FILES=/opt/homebrew/bin/cmake \
	/opt/homebrew/include/libelf \
	/opt/homebrew/include/libusb-1.0 \
	/opt/homebrew/include/ftdi.h

build: avrdude/build_darwin/src/avrdude

install:
	cd avrdude && cmake --build build_darwin --target install

clean:
	rm -rf avrdude

avrdude/build_darwin/src/avrdude: avrdude/build_darwin
	cd avrdude && cmake --build build_darwin

avrdude/build_darwin: avrdude
	cd avrdude && cmake \
		-D CMAKE_C_FLAGS="-I/opt/homebrew/include -I/opt/homebrew/include/libusb-1.0" \
		-D CMAKE_EXE_LINKER_FLAGS=-L/opt/homebrew/lib \
		-D CMAKE_INSTALL_PREFIX=${INSTALL_PREFIX} \
		-D CMAKE_BUILD_TYPE=RelWithDebInfo \
		-B build_darwin

avrdude: check_requirements ../download/avrdude
	cp -rf ../download/avrdude $@
	cd avrdude && git checkout v7.0

../download/avrdude:
	git clone https://github.com/avrdudes/avrdude.git

check_requirements:
	@echo "-----------------------------------"
	@echo "エラーになった場合、homebrewを使って以下を導入してください"
	@echo "libftdi0ではなくlibftdiの場合はエラーになることがあります"
	@echo "  brew install cmake libelf libusb libftdi0"
	@echo "-----------------------------------"
	@for i in $(REQUIMENT_FILES); do if [ ! -e "$$i" ]; then echo "$$i がありません"; exit 1; fi done

.PHONY: build clean install check_requirements
