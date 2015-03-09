#include "fifo_ts.h"

t_fifo_elem *fifo = NULL;
t_fifo_elem *last = NULL;
pthread_mutex_t lock;

int init_fifo() {
  return (pthread_mutex_init(&lock, NULL) == 0);
}

t_fifo_elem * pop_fifo() {
  t_fifo_elem *ret;
  pthread_mutex_lock(&lock);
  if(fifo == NULL) {
    ret = NULL;
  } else {
    t_fifo_elem *elem = fifo;
    fifo = elem->next;

    if(elem == last)
      last = NULL;

    ret = elem;
  }
  pthread_mutex_unlock(&lock);
  return ret;
}

void push_fifo(int index, FILE* data) {
  t_fifo_elem *elem = (t_fifo_elem*) malloc(sizeof(t_fifo_elem));
  elem->index = index;
  elem->data = data;
  elem->next = NULL;

  pthread_mutex_lock(&lock);
  if(fifo == NULL) {
    fifo = elem;
    last = elem;
  } else {
    last->next = elem;
    last = elem;
  }
  pthread_mutex_unlock(&lock);
}

int fifo_size() {
  int ret = 0;
  pthread_mutex_lock(&lock);
  t_fifo_elem * elem = fifo;
  while(elem != NULL) {
    ret++;
    elem = elem->next;
  }
  pthread_mutex_unlock(&lock);
  return ret;
}