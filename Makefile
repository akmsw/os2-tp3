# author: Bonino, Francisco Ignacio.
# version: 0.3
# since: 2022-04-13

# Flags

CC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11 -O0 -pg
DIRS = ./bin ./obj ./prof

# Main targets

all: build_folders lab3 lab3_opt

build_folders:
	mkdir -p $(DIRS)

gprof:
	gprof bin/lab3 gmon.out > prof/analysis.txt

gprof_opt:
	gprof bin/lab3_opt gmon.out > prof/analysis_opt.txt

# Binaries

lab3: lab3.o
	$(CC) -O0 -pg -o bin/$@ obj/$<

lab3.o: src/lab3.c
	$(CC) -O0 -pg -c $< -o obj/$@

lab3_opt: lab3_opt.o
	$(CC) $(CFLAGS) -o bin/$@ obj/$<

lab3_opt.o: src/lab3_opt.c
	$(CC) $(CFLAGS) -c $< -o obj/$@

# Others

clean:
	rm -r $(DIRS)