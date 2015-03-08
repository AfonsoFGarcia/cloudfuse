#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct fifo_elem {
	int index;
	char* data;
	struct fifo_elem* next;
} t_fifo_elem;

int init_fifo();
void destroy_fifo();
t_fifo_elem * pop_fifo();
void push_fifo(int index, char* data);