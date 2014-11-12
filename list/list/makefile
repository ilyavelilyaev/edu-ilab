main.o: main.cpp
	g++ -c -o main.o main.cpp
listExeptions.o: listExeptions.cpp
	g++ -c -o listExeptions.o listExeptions.cpp
list.o: list.cpp
	g++ -c -o list.o list.cpp
list: list.o main.o listExeptions.o
	g++ -o list list.o main.o listExeptions.o
clean: 
	rm list.o
	rm main.o
	rm listExeptions.o
