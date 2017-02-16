all: makecal

ROOTCFLAGS  = $(shell $(CFG_ROOT_BIN)root-config --cflags)
ROOTLIBS    = $(shell $(CFG_ROOT_BIN)root-config --libs) -lTreePlayer

CFLAGS = -I./include
GXX = g++ -m64 -pthread

.SUFFIXES: .cpp .o

.cpp.o:
	$(GXX) $(CFLAGS) $(ROOTCFLAGS) -c $<

makecal: makecal.cpp ./include/pid.h ./include/ic.h ./include/ppac.h ./include/plastics.h ./src/RIBF123ReadAndCalcRAW.cpp ./src/RIBF123PID.cpp
	$(GXX) $(CFLAGS) $(ROOTCFLAGS) $(ROOTLIBS) -o $@ makecal.cpp ./src/RIBF123ReadAndCalcRAW.cpp ./src/RIBF123PID.cpp

clean:
	rm -f *.cpp~ *.o makecal
