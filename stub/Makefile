CXX=clang++
CXXFLAGS=--std=c++20 -pedantic -Wall -Wextra -fPIC
OBJS=stub.o
LIB=libstub.so

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