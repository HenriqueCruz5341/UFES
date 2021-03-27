clean:
	rm ./exec

compile_1:
	gcc -o exec main.c qsort1.c

compile_2:
	gcc -o exec main.c qsort2.c

compile_3:
	gcc -o exec main.c qsort3.c

compile_4:
	gcc -o exec main.c qsort4.c

compile_5:
	gcc -o exec main.c qsort5.c

compile_6:
	gcc -o exec main.c qsort6.c

compile_7:
	gcc -o exec main.c qsort7.c

compile_8:
	gcc -o exec main.c qsort8.c

run:
	./exec 14 < entrada.txt > saida.txt

run_few:
	time ./exec 1000000 < input/few_uniq/10M_const_keys_sorted.txt > saida.txt

run_nearly:
	time ./exec 1000000 < input/nearly_sorted/1000000.txt > saida.txt

run_reverse:
	time ./exec 1000000 < input/reverse_sorted/1000000.txt > saida.txt

run_sorted:
	time ./exec 1000000 < input/sorted/1000000.txt > saida.txt

run_unif:
	time ./exec 1000000 < input/unif_rand/1000000.txt > saida.txt

valgrind:
	valgrind ./exec 1000000 < input/sorted/1000000.txt > saida.txt