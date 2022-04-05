#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#define MAX_ID 100

struct Node *front;
struct Node *block;
struct Node *tmp;

struct Node {
	int availableSpace;
	struct Node *nextNode;
	char pid[MAX_ID];
	int startAdd;
	int endAdd;

};

char req[3];
char proccess[3];
int lastAddSpace;
int requestedSpace;
char algo[2];

void releaseMem(char pid[5]) {
	printf("Releasing memory for process %s\n", pid);
	tmp = front;
	struct Node *pre;
	int memSlot;

	if (tmp != NULL && tmp->pid == pid) {
		memSlot = tmp->endAdd - tmp->startAdd;
		front = tmp->nextNode;
		front->availableSpace += memSlot;

	}

	while (tmp->nextNode != NULL && tmp->pid != pid) {
		pre = tmp;
		tmp = tmp->nextNode;
	}
	if (tmp == NULL) {
		return;
	}

	memSlot = tmp->endAdd - tmp->startAdd;
	pre->nextNode = tmp->nextNode;
	front->availableSpace += memSlot;

	return;

}

void bestFit(char pid[5], int requestedSpace) {
//	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	int smallestSpace = 999999;
//	int leftOverSpace = 0;
	struct Node *smallestBlock = NULL;
	tmp = block;

	if (requestedSpace <= 0) {
		printf("Enter a positive value of memory");
	}

	while (tmp != NULL) {
		if (strcmp(tmp->pid, "") == 0
				&& tmp->availableSpace >= requestedSpace) {
			if (tmp->availableSpace <= smallestSpace) {
				smallestSpace = tmp->availableSpace;
				smallestBlock = tmp;
			}
		} else {
			tmp = tmp->nextNode;
		}
	}
	if (smallestBlock != NULL) {
		int empty = smallestBlock->availableSpace - requestedSpace;
		smallestBlock->availableSpace = requestedSpace;
		strcpy(smallestBlock->pid, pid);
		if (empty > 0) {
			struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
			newNode->endAdd = smallestBlock->endAdd;
			smallestBlock->endAdd = smallestBlock->startAdd + requestedSpace
					- 1;
			newNode->startAdd = smallestBlock->endAdd + 1;
			newNode->availableSpace = empty;
			newNode->nextNode = smallestBlock->nextNode;
			smallestBlock->nextNode = newNode;
		}

		printf("Successfully allocated %d to process %s\n", requestedSpace,
				pid);
	} else {
		printf("Not enough space");
	}
}

void requestMem(char pid[3], int requestedSpace, char algo[2]) {
	if (strcmp("B", algo) == 0) {
		bestFit(pid, requestedSpace);
	}
}

void status() {
	return;
}

int main(int argc, char *argv[]) {
	int startMem = atoi(argv[1]);
	printf("Allocated %d size of memory\n", startMem);
	char input[128];
	front = (struct Node*) malloc(sizeof(struct Node));

	block = (struct Node*) malloc(sizeof(struct Node));

	strcpy(front->pid, "");
	front->startAdd = -1;
	front->endAdd = -1;
	front->availableSpace = startMem;
	front->nextNode = block;

	strcpy(block->pid, "");
	block->startAdd = 0;
	block->endAdd = startMem;
	block->availableSpace = block->endAdd - block->startAdd;
	block->nextNode = NULL;

	lastAddSpace = startMem;

	int running = 1;
	while (running == 1) {
		printf("\ncommand>");
		fgets(input, 128, stdin);
		input[strcspn(input, "\r\n")] = 0;
		char *otk = strtok(input, " ");
		char *args[4];
//		otk = strtok(NULL, " ");
		int j = 0;
		while (otk != NULL) {
			args[j] = otk;
			otk = strtok(NULL, " ");
			printf("%d %s\n", j, args[j]);
			j += 1;
		}

		if (strcmp(args[0], "RQ") == 0) {
			requestMem(args[1], *args[2], args[3]);
		}

	}
	return 0;

}

