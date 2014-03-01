all: main 

main: main.o
	g++ main.o -o app 

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o app*
