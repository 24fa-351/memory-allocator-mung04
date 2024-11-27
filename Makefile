all: mem_sys mem_dev

mem_sys: memtest.c
	gcc -o mem_sys -DSYSTEM_MALLOC memtest.c

mem_dev: memtest.c malloc.c malloc.h
	gcc -o mem_dev memtest.c malloc.c