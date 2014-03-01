all: main 

main: main.o
	g++ main.o -o app 

main.o: main.cpp
	g++ -c main.cpp -D DEBUG=1

clean:
	rm -rf *.o app*
