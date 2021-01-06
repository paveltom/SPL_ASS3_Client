CFLAGS:=-c -Wall -Weffc++ -g -std=c++11 -Iinclude
LDFLAGS:=-lboost_system -pthread

all: Client

Client: bin/connectionHandler.o bin/twoThreadClient.o

g++ -o bin/echoExample bin/connectionHandler.o bin/twoThreadClient.o $(LDFLAGS)

bin/connectionHandler.o: src/connectionHandler.cpp
	g++ $(CFLAGS) -o bin/connectionHandler.o src/connectionHandler.cpp

bin/twoThreadClient.o: src/twoThreadClient.cpp
	g++ $(CFLAGS) -o bin/twoThreadClient.o src/twoThreadClient.cpp
	
.PHONY: clean
clean:
	rm -f bin/*
