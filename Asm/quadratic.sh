./assmb quadratic.asm assembled_q.o
./disassmb assembled_q.o disassm_q.asm
./assmb disassm_q.asm q.o
./emul q.o
