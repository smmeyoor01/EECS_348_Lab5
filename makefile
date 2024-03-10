all: problem1 problem2

p1: p1.c
	gcc -o p1 p1.c
p2: p2.c 
	gcc -o p2 p2.c
clean:
	rm -f p1 
	rm -f p2