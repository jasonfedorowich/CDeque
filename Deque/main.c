#include "deque.h"
#include <stdio.h>

int main() {

	deque* d = create_deque(10);
	push(d, 2);
	int first = (int) pop(d);
	printf("first number: %d", first);
	inject(d, 10);
	inject(d, 5);
	int last_item = (int) eject(d);
	printf("last number: %d", last_item);
	free_deque(d);

}