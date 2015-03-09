#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct fifo_elem {
	int index;
	FILE* data;
	struct fifo_elem* next;
} t_fifo_elem;

int init_fifo();
t_fifo_elem * pop_fifo();
void push_fifo(int index, FILE* data);
int fifo_size();