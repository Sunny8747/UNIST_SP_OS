#include <stdio.h>
#include "LRU.h"


int main(int argc, char** argv) {
	int SIZE = atoi(argv[1]);
	Queue* q = createQueue(SIZE);
	//printf("create Queue\n");

	FILE *file_;
	file_ = fopen("input.txt", "r");
	//printf("file oopen\n");

	if (file_ == NULL) {
		printf("FILE OPEN ERROR\n");
	exit(1);
	}
    
	int num;
	while (fscanf(file_, "%i", &num) == 1) {
		printf("Reference %d\n", num);
		Reference(q, num);
		PrintQueue(q);
	}

	ClearQueue(q);
}
