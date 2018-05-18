CC = g++
OPTS = -std=c++11 -lsqlite3 -O

all: db.o main.o gee-mail.bin

db.o: src/db.cpp
	$(CC) -c src/db.cpp -o src/db.o

main.o: src/main.cpp
	$(CC) -c src/main.cpp -o src/main.o

gee-mail.bin: src/main.o
	$(CC) src/main.o src/db.o $(OPTS) -o gee-mail.bin

clean: 
	rm src/*.o gee-mail.bin