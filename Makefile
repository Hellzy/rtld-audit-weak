LDFLAGS=-Lprint/
LDLIBS=-lprint
CXXFLAGS=-std=c++17

all: opti printer

printer: CXXFLAGS+=-Iprint

printer-debug: CXXFLAGS+=-O0 -g
printer-debug: printer

opti:
	make -C bypass $@
	make -C print $@

debug:
	make -C bypass $@
	make -C print $@

clean:
	make -C bypass $@
	make -C print $@
	$(RM) printer

.PHONY: all opti debug clean
