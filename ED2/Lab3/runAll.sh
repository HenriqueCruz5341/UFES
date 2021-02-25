#!/bin/bash

(time ./bubbleSort 1000 < in/nearly_sorted/1Knearly_sorted.txt) 2>> out/bubbleSort/1Knearly_sorted.txt
(time ./insertionSort 1000 < in/nearly_sorted/1Knearly_sorted.txt) 2>> out/insertionSort/1Knearly_sorted.txt
(time ./selectionSort 1000 < in/nearly_sorted/1Knearly_sorted.txt) 2>> out/selectionSort/1Knearly_sorted.txt
(time ./shakerSort 1000 < in/nearly_sorted/1Knearly_sorted.txt) 2>> out/shakerSort/1Knearly_sorted.txt
(time ./mySort 1000 < in/nearly_sorted/1Knearly_sorted.txt) 2>> out/mySort/1Knearly_sorted.txt

(time ./bubbleSort 10000 < in/nearly_sorted/10Knearly_sorted.txt) 2>> out/bubbleSort/10Knearly_sorted.txt
(time ./insertionSort 10000 < in/nearly_sorted/10Knearly_sorted.txt) 2>> out/insertionSort/10Knearly_sorted.txt
(time ./selectionSort 10000 < in/nearly_sorted/10Knearly_sorted.txt) 2>> out/selectionSort/10Knearly_sorted.txt
(time ./shakerSort 10000 < in/nearly_sorted/10Knearly_sorted.txt) 2>> out/shakerSort/10Knearly_sorted.txt
(time ./mySort 10000 < in/nearly_sorted/10Knearly_sorted.txt) 2>> out/mySort/10Knearly_sorted.txt

(time ./bubbleSort 100000 < in/nearly_sorted/100Knearly_sorted.txt) 2>> out/bubbleSort/100Knearly_sorted.txt
(time ./insertionSort 100000 < in/nearly_sorted/100Knearly_sorted.txt) 2>> out/insertionSort/100Knearly_sorted.txt
(time ./selectionSort 100000 < in/nearly_sorted/100Knearly_sorted.txt) 2>> out/selectionSort/100Knearly_sorted.txt
(time ./shakerSort 100000 < in/nearly_sorted/100Knearly_sorted.txt) 2>> out/shakerSort/100Knearly_sorted.txt
(time ./mySort 100000 < in/nearly_sorted/100Knearly_sorted.txt) 2>> out/mySort/100Knearly_sorted.txt

(time ./bubbleSort 1000 < in/reverse_sorted/1Kreverse_sorted.txt) 2>> out/bubbleSort/1Kreverse_sorted.txt
(time ./insertionSort 1000 < in/reverse_sorted/1Kreverse_sorted.txt) 2>> out/insertionSort/1Kreverse_sorted.txt
(time ./selectionSort 1000 < in/reverse_sorted/1Kreverse_sorted.txt) 2>> out/selectionSort/1Kreverse_sorted.txt
(time ./shakerSort 1000 < in/reverse_sorted/1Kreverse_sorted.txt) 2>> out/shakerSort/1Kreverse_sorted.txt
(time ./mySort 1000 < in/reverse_sorted/1Kreverse_sorted.txt) 2>> out/mySort/1Kreverse_sorted.txt

(time ./bubbleSort 10000 < in/reverse_sorted/10Kreverse_sorted.txt) 2>> out/bubbleSort/10Kreverse_sorted.txt
(time ./insertionSort 10000 < in/reverse_sorted/10Kreverse_sorted.txt) 2>> out/insertionSort/10Kreverse_sorted.txt
(time ./selectionSort 10000 < in/reverse_sorted/10Kreverse_sorted.txt) 2>> out/selectionSort/10Kreverse_sorted.txt
(time ./shakerSort 10000 < in/reverse_sorted/10Kreverse_sorted.txt) 2>> out/shakerSort/10Kreverse_sorted.txt
(time ./mySort 10000 < in/reverse_sorted/10Kreverse_sorted.txt) 2>> out/mySort/10Kreverse_sorted.txt

(time ./bubbleSort 100000 < in/reverse_sorted/100Kreverse_sorted.txt) 2>> out/bubbleSort/100Kreverse_sorted.txt
(time ./insertionSort 100000 < in/reverse_sorted/100Kreverse_sorted.txt) 2>> out/insertionSort/100Kreverse_sorted.txt
(time ./selectionSort 100000 < in/reverse_sorted/100Kreverse_sorted.txt) 2>> out/selectionSort/100Kreverse_sorted.txt
(time ./shakerSort 100000 < in/reverse_sorted/100Kreverse_sorted.txt) 2>> out/shakerSort/100Kreverse_sorted.txt
(time ./mySort 100000 < in/reverse_sorted/100Kreverse_sorted.txt) 2>> out/mySort/100Kreverse_sorted.txt

(time ./bubbleSort 1000 < in/sorted/1Ksorted.txt) 2>> out/bubbleSort/1Ksorted.txt
(time ./insertionSort 1000 < in/sorted/1Ksorted.txt) 2>> out/insertionSort/1Ksorted.txt
(time ./selectionSort 1000 < in/sorted/1Ksorted.txt) 2>> out/selectionSort/1Ksorted.txt
(time ./shakerSort 1000 < in/sorted/1Ksorted.txt) 2>> out/shakerSort/1Ksorted.txt
(time ./mySort 1000 < in/sorted/1Ksorted.txt) 2>> out/mySort/1Ksorted.txt

(time ./bubbleSort 10000 < in/sorted/10Ksorted.txt) 2>> out/bubbleSort/10Ksorted.txt
(time ./insertionSort 10000 < in/sorted/10Ksorted.txt) 2>> out/insertionSort/10Ksorted.txt
(time ./selectionSort 10000 < in/sorted/10Ksorted.txt) 2>> out/selectionSort/10Ksorted.txt
(time ./shakerSort 10000 < in/sorted/10Ksorted.txt) 2>> out/shakerSort/10Ksorted.txt
(time ./mySort 10000 < in/sorted/10Ksorted.txt) 2>> out/mySort/10Ksorted.txt

(time ./bubbleSort 100000 < in/sorted/100Ksorted.txt) 2>> out/bubbleSort/100Ksorted.txt
(time ./insertionSort 100000 < in/sorted/100Ksorted.txt) 2>> out/insertionSort/100Ksorted.txt
(time ./selectionSort 100000 < in/sorted/100Ksorted.txt) 2>> out/selectionSort/100Ksorted.txt
(time ./shakerSort 100000 < in/sorted/100Ksorted.txt) 2>> out/shakerSort/100Ksorted.txt
(time ./mySort 100000 < in/sorted/100Ksorted.txt) 2>> out/mySort/100Ksorted.txt

(time ./bubbleSort 1000 < in/unif_rand/1Kunif_rand.txt) 2>> out/bubbleSort/1Kunif_rand.txt
(time ./insertionSort 1000 < in/unif_rand/1Kunif_rand.txt) 2>> out/insertionSort/1Kunif_rand.txt
(time ./selectionSort 1000 < in/unif_rand/1Kunif_rand.txt) 2>> out/selectionSort/1Kunif_rand.txt
(time ./shakerSort 1000 < in/unif_rand/1Kunif_rand.txt) 2>> out/shakerSort/1Kunif_rand.txt
(time ./mySort 1000 < in/unif_rand/1Kunif_rand.txt) 2>> out/mySort/1Kunif_rand.txt

(time ./bubbleSort 10000 < in/unif_rand/10Kunif_rand.txt) 2>> out/bubbleSort/10Kunif_rand.txt
(time ./insertionSort 10000 < in/unif_rand/10Kunif_rand.txt) 2>> out/insertionSort/10Kunif_rand.txt
(time ./selectionSort 10000 < in/unif_rand/10Kunif_rand.txt) 2>> out/selectionSort/10Kunif_rand.txt
(time ./shakerSort 10000 < in/unif_rand/10Kunif_rand.txt) 2>> out/shakerSort/10Kunif_rand.txt
(time ./mySort 10000 < in/unif_rand/10Kunif_rand.txt) 2>> out/mySort/10Kunif_rand.txt

(time ./bubbleSort 100000 < in/unif_rand/100Kunif_rand.txt) 2>> out/bubbleSort/100Kunif_rand.txt
(time ./insertionSort 100000 < in/unif_rand/100Kunif_rand.txt) 2>> out/insertionSort/100Kunif_rand.txt
(time ./selectionSort 100000 < in/unif_rand/100Kunif_rand.txt) 2>> out/selectionSort/100Kunif_rand.txt
(time ./shakerSort 100000 < in/unif_rand/100Kunif_rand.txt) 2>> out/shakerSort/100Kunif_rand.txt
(time ./mySort 100000 < in/unif_rand/100Kunif_rand.txt) 2>> out/mySort/100Kunif_rand.txt

