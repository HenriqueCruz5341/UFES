clean:
	rm ./exec

compile:
	gcc -o exec main.c merge6.c

run:
	time ./exec 1000000 < input/unif_rand/1000000.txt

valgrind:
	valgrind ./exec 1000000 < input/unif_rand/1000000.txt