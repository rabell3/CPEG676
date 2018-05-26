CC = g++
OPTS = -std=c++11 -lsqlite3 -lcrypto++ -O

all: db.o user.o main.o gee-mail.bin

db.o: src/db.cpp
	$(CC) -c src/db.cpp -o src/db.o

user.o: src/user.cpp
	$(CC) -c src/user.cpp -o src/user.o

main.o: src/main.cpp
	$(CC) -c src/main.cpp -o src/main.o

gee-mail.bin: src/main.o
	$(CC) src/main.o src/db.o src/user.o $(OPTS) -o gee-mail.bin

clean: 
	rm src/*.o gee-mail.bin