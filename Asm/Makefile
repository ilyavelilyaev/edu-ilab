all: assmb disassmb

assembler/assembler.o: assembler/assembler.cpp assembler/assembler.h codes.h
	g++ -c -o assembler/assembler.o assembler/assembler.cpp 

assembler/main.o: assembler/main.cpp assembler/assembler.h codes.h
	g++ -c -o assembler/main.o assembler/main.cpp

assmb: assembler/assembler.o assembler/main.o
	g++ -o assmb assembler/assembler.o assembler/main.o

disassembler/disassembler.o: disassembler/disassembler.cpp disassembler/disassembler.h codes.h
	g++ -c -o disassembler/disassembler.o disassembler/disassembler.cpp

disassembler/main.o: disassembler/main.cpp disassembler/disassembler.h codes.h
	g++ -c -o disassembler/main.o disassembler/main.cpp

disassmb: disassembler/disassembler.o disassembler/main.o
	g++ -o disassmb disassembler/disassembler.o disassembler/main.o

clean:
	rm -rf assembler/assembler.o
	rm -rf assembler/main.o
	rm -rf disassembler/disassembler.o
	rm -rf disassembler/main.o
	rm -rf assmb
	rm -rf disassmb
