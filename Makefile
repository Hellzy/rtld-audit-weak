LDFLAGS=-Lprint/
LDLIBS=-lprint
CXXFLAGS=-std=c++17

all: opti printer

printer: CXXFLAGS+=-Iprint

opti:
	make -C bypass $@
	make -C print $@
	make -C stub $@

debug:
	make -C bypass $@
	make -C print $@
	make -C stub $@

clean:
	make -C bypass $@
	make -C print $@
	make -C stub $@
	$(RM) printer

.PHONY: all opti debug clean
