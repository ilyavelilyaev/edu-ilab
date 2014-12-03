all: assmb disassmb emul

assembler/assembler.o: assembler/assembler.cpp assembler/assembler.h codes.h
	g++ -c -g -o assembler/assembler.o assembler/assembler.cpp 

assembler/main.o: assembler/main.cpp assembler/assembler.h codes.h
	g++ -c -g -o assembler/main.o assembler/main.cpp

assmb: assembler/assembler.o assembler/main.o
	g++ -g -o assmb assembler/assembler.o assembler/main.o

disassembler/disassembler.o: disassembler/disassembler.cpp disassembler/disassembler.h codes.h
	g++ -c -g -o disassembler/disassembler.o disassembler/disassembler.cpp

disassembler/main.o: disassembler/main.cpp disassembler/disassembler.h codes.h
	g++ -c -g -o disassembler/main.o disassembler/main.cpp

disassmb: disassembler/disassembler.o disassembler/main.o
	g++ -g -o disassmb disassembler/disassembler.o disassembler/main.o

emulator/emulator.o: emulator/emulator.h emulator/emulator.cpp
	g++ -c -g -o emulator/emulator.o emulator/emulator.cpp

emulator/main.o: emulator/main.cpp emulator/emulator.h codes.h
	g++ -c -g -o emulator/main.o emulator/main.cpp

stack/stack.o: stack/stack.h stack/stack.cpp
	g++ -c -g -o stack/stack.o stack/stack.cpp

emul: emulator/emulator.o emulator/main.o stack/stack.o 
	g++ -g -o emul emulator/emulator.o emulator/main.o stack/stack.o 

clean:
	rm -rf assembler/assembler.o
	rm -rf assembler/main.o
	rm -rf disassembler/disassembler.o
	rm -rf disassembler/main.o
	rm -rf emulator/emulator.o
	rm -rf emulator/main.o
	rm -rf stack/stack.o
	rm -rf emul
	rm -rf assmb
	rm -rf disassmb
