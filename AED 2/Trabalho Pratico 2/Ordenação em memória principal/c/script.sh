# script to generete bin file based on c programs
gcc -o bolha.o bolha.c -c -W -Wall -pedantic
gcc -o countingsort.o countingsort.c -c -W -Wall -pedantic
gcc -o geracao.o geracao.c -c -W -Wall -pedantic
gcc -o heapsort.o heapsort.c -c -W -Wall -pedantic
gcc -o insercao.o insercao.c -c -W -Wall -pedantic
gcc -o mergesort.o mergesort.c -c -W -Wall -pedantic
gcc -o quicksort.o quicksort.c -c -W -Wall -pedantic
gcc -o selecao.o selecao.c -c -W -Wall -pedantic
gcc -o shellsort.o shellsort.c -c -W -Wall -pedantic
gcc -o principal.o principal.c -c -W -Wall -pedantic
gcc -o exec principal.o geracao.o bolha.o countingsort.o heapsort.o insercao.o mergesort.o quicksort.o selecao.o shellsort.o
