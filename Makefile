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

tmp/$(DFP_ATMEGA): download/$(DFP_ATMEGA).atpack
	mkdir -p $@
	cd $@ && unzip ../../download/$(DFP_ATMEGA).atpack

download/$(DFP_ATMEGA).atpack:
	curl -Lo $@ http://packs.download.atmel.com/$(DFP_ATMEGA).atpack

tmp/$(DFP_ATTINY): download/$(DFP_ATTINY).atpack
	mkdir -p $@
	cd $@ && unzip ../../download/$(DFP_ATTINY).atpack

download/$(DFP_ATTINY).atpack:
	curl -Lo $@ http://packs.download.atmel.com/$(DFP_ATTINY).atpack

$(PREFIX)/bin/avr-gcc:
	mkdir -p $(PREFIX)
	tar zx --strip-components=1 -C $(PREFIX) -f download/$(AVR_TOOLCHAINS)

download/$(AVR_TOOLCHAINS):
	mkdir -p download
	@echo "---------------------------------------------------------"
	@echo "$@ NOT FOUND"
	@echo "---------------------------------------------------------"
	@exit 1

download/$(AVRDUDE).tar.gz:
	curl -Lo $@ http://download.savannah.gnu.org/releases/avrdude/$(AVRDUDE).tar.gz

# debian: apt-get install bison flex

tmp/avrdude: download/$(AVRDUDE).tar.gz
	mkdir -p $@
	tar zx --strip-components=1 -C $@ -f $<
	cd tmp/avrdude && ./configure --prefix=$(PREFIX)
	cd tmp/avrdude && make -j 2

$(PREFIX)/bin/avrdude: tmp/avrdude
	cd $< && make install
	patch $(PREFIX)/etc/avrdude.conf < patch/avrdude.conf.patch

clean:
	rm -rf tmp

uninstall:
	rm -rf $(PREFIX)

