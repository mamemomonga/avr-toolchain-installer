include config.mk

all:  \
   	download/$(AVR_TOOLCHAINS) \
	$(PREFIX)/bin/avr-gcc \
	$(PREFIX)/dfp \
	$(PREFIX)/enable.sh \
	$(PREFIX)/bin/avrdude

$(PREFIX)/enable.sh:
	echo '#!/bin/sh' > $@
	echo 'export PATH="$(PREFIX)/bin:$$PATH"' >> $@
	echo 'export AVR_DFP="$(PREFIX)/dfp"' >> $@
	chmod 755 $@

$(PREFIX)/dfp: tmp/$(DFP_ATTINY) tmp/$(DFP_ATMEGA)
	mkdir -p $@/gcc
	mkdir -p $@/include
	tar cC tmp/$(DFP_ATTINY)/gcc .     | tar xC $@/gcc
	tar cC tmp/$(DFP_ATTINY)/include . | tar xC $@/include
	tar cC tmp/$(DFP_ATMEGA)/gcc .     | tar xC $@/gcc
	tar cC tmp/$(DFP_ATMEGA)/include . | tar xC $@/include

# ------------
tmp/$(DFP_ATMEGA): download/$(DFP_ATMEGA).atpack
	mkdir -p $@
	cd $@ && unzip ../../download/$(DFP_ATMEGA).atpack

download/$(DFP_ATMEGA).atpack:
	curl -Lo $@ http://packs.download.atmel.com/$(DFP_ATMEGA).atpack

# ------------
tmp/$(DFP_ATTINY): download/$(DFP_ATTINY).atpack
	mkdir -p $@
	cd $@ && unzip ../../download/$(DFP_ATTINY).atpack

download/$(DFP_ATTINY).atpack:
	curl -Lo $@ http://packs.download.atmel.com/$(DFP_ATTINY).atpack

# ------------
$(PREFIX)/bin/avr-gcc:
	mkdir -p $(PREFIX)
	tar zx --strip-components=1 -C $(PREFIX) -f download/$(AVR_TOOLCHAINS)

download/$(AVR_TOOLCHAINS):
	mkdir -p download
	curl -Lo $@ https://ww1.microchip.com/downloads/aemDocuments/documents/DEV/ProductDocuments/SoftwareTools/$(AVR_TOOLCHAINS)

# ------------

download/avrdude:
	git clone https://github.com/avrdudes/avrdude.git $@

tmp/avrdude: download/avrdude
	@if [ -z "$(shell whereis -q cmake)" ]; then echo "cmakeがありません"; exit 1; fi
	cp -rf $< $@
	cd tmp/avrdude && git checkout v7.0
	cd tmp/avrdude && perl -nlpi.bak -E 's!extra_enable=""!extra_enable="-DCMAKE_INSTALL_PREFIX=$(PREFIX)"!g' build.sh
	cd tmp/avrdude && ./build.sh

$(PREFIX)/bin/avrdude: tmp/avrdude
	cd tmp/avrdude && cmake --build build_darwin --target install

# darwin: brew install cmake
# debian: apt-get install cmake bison flex

clean:
	rm -rf tmp

uninstall:
	rm -rf $(PREFIX)

