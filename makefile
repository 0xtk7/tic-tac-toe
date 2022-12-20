CC = g++
CFLAGS = -std=c++11

all: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main

clean:
	rm -f main