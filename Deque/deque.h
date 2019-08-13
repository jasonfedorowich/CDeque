#pragma once
typedef struct deque {
	int q_max_size;
	int q_size;
	int q_front;
	int q_rear;
	void** q_array;
} deque;

deque* create_deque(int size);
void* pop(deque* d);
void push(deque* d, void* x);
void inject(deque* d, void* x);
void* eject(deque* d);
int is_empty(deque* d);
int is_full(deque* d);

void free_deque(deque* d);
