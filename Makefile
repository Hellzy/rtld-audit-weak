all: opti

opti:
	make -C bypass $@
	make -C print $@

debug:
	make -C bypass $@
	make -C print $@

clean:
	make -C bypass $@
	make -C print $@

.PHONY: all opti debug clean
