all: makecal
FILES = ./include/pid.h ./include/ic.h ./include/ppac.h ./include/plastics.h ./include/parameters.h
ROOTCFLAGS  = $(shell $(CFG_ROOT_BIN)root-config --cflags)
ROOTLIBS    = $(shell $(CFG_ROOT_BIN)root-config --libs)

CFLAGS = -I./include
GXX = g++ -Wall -m64 -pthread

.SUFFIXES: .cpp .o

.cpp.o:
	$(GXX) $(CFLAGS) $(ROOTCFLAGS) -c $<

makecal: makecal.cpp makecal.h $(FILES)
	$(GXX) $(CFLAGS) $(ROOTCFLAGS) $(ROOTLIBS) -o $@ makecal.cpp

clean:
	rm -f *.cpp~ *.o makecal
