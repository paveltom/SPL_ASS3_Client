CFLAGS:=-c -Wall -Weffc++ -g -std=c++11 -Iinclude 
LDFLAGS:=-lboost_system -pthread -lboost_thread


all: Client

@echo 'Building target: Client'
@echo 'Invoking: C++ Linker'
Client: bin/main.o bin/connectionHandler.o bin/EncoderDecoder.o
	 g++ -Wall -Weffc++ -o bin/Client bin/main.o bin/connectionHandler.o bin/EncoderDecoder.o $(LDFLAGS)
@echo 'Finished building target: Client'

bin/connectionHandler.o: src/connectionHandler.cpp
	g++ $(CFLAGS) -o bin/connectionHandler.o src/connectionHandler.cpp $(LDFLAGS)

bin/EncoderDecoder.o: src/EncoderDecoder.cpp
	g++ $(CFLAGS) -o bin/EncoderDecoder.o src/EncoderDecoder.cpp

bin/main.o: src/main.cpp
	g++ $(CFLAGS) -o bin/main src/main.cpp

.PHONY: clean
clean:
	@echo 'Cleaning'
	rm -f bin/*

