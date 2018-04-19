all: target clean run

target: main.cpp
	g++ -o main main.cpp #-I./include -L./lib -l:LibTimeDateTools.a

clean:
	rm -rf *.o

run:
	./main
