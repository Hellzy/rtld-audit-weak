CXX=clang++
CXXFLAGS=-Iinclude -std=c++20 -pedantic -Wall -Wextra -fPIC
OBJS=src/bypass.o src/symbols.o
LIB=libbypass.so

all: opti

opti: CXXFLAGS+=-O3
opti: $(LIB)

debug: CXXFLAGS+=-O0 -g
debug: $(LIB)

$(LIB): $(OBJS)
	$(LINK.cc) -shared -o $(LIB) $^

clean:
	$(RM) $(OBJS) $(LIB)

.PHONY: all clean debug opti
