all: debug

main: main.o
	g++ main.o -o app 

main.o: main.cpp
	g++ -c main.cpp

debug: main1

main1: main1.o
	g++ main.o -o app

main1.o: main.cpp
	g++ -c main.cpp -D DEBUG=1

clean:
	rm -rf *.o app*