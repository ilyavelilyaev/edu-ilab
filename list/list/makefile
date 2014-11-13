
all: list

main.o: main.cpp
	g++ -c -g -o main.o main.cpp
listExeptions.o: listExeptions.cpp
	g++ -c -g -o listExeptions.o listExeptions.cpp
list.o: list.cpp
	g++ -c -g -o list.o list.cpp
list: list.o main.o listExeptions.o
	g++ -g -o list list.o main.o listExeptions.o
clean: 
	rm -rf list.o
	rm -rf main.o
	rm -rf listExeptions.o
