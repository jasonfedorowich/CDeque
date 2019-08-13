#include "deque.h"
#include <stddef.h>
#include <stdio.h>

deque* create_deque(int size)
{
	deque* deq = (struct deque*) malloc(sizeof(deque));
	deq->q_max_size = size;
	deq->q_size = 0;
	deq->q_rear = deq->q_front = size / 2;
	deq->q_rear = size - 1;
	deq->q_array = malloc(deq->q_max_size * sizeof(void*));
	return deq;
}

void* pop(deque* d)
{
	if(is_empty(d))
		puts("Nothing in deque to pop");
	void* element = d->q_array[++d->q_front];
	d->q_size--;
	return element;
}

void push(deque* d, void* x)
{
	if (is_full(d))
		puts("Deque is full");
	if (d->q_front == 0)
		d->q_front = d->q_max_size / 2;
	d->q_array[d->q_front--] = x;
	d->q_size++;
}

void inject(deque* d, void* x)
{
	if(is_full(d))
		puts("Deque is full");
	if (d->q_rear == d->q_size - 1)
		d->q_front = d->q_max_size / 2;
	d->q_array[d->q_rear++] = x;
	d->q_size++;

}

void* eject(deque* d)
{
	if (is_empty(d))
		puts("Nothing in deque to pop");
	int element = d->q_array[--d->q_rear];
	d->q_size--;
	return element;
}

int is_empty(deque* d)
{
	return d->q_size == 0;
}

int is_full(deque* d)
{
	return d->q_max_size == d->q_size;
}

void free_deque(deque* d) {
	free(d);
}
