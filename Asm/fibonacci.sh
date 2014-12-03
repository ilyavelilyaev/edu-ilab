./assmb fib.asm assembled_fib.o
./disassmb assembled_fib.o disassm_fib.asm
./assmb disassm_fib.asm fib.o
./emul fib.o
