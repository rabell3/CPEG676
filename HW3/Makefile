CC = g++
OPTS = -lsqlite3 -O

all: gee-mail

gee-mail: src/main.o
	$(CC) src/main.o $(OPTS) -o gee-mail

main.o: src/main.cpp
	$(CC) -c src/main.cpp

clean: rm *.o gee-mail
