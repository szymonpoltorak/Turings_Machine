#ifndef _MEMORY_H_
#define _MEMORY_H_

#define Q0 2
#define Q1 3
#define Q2 4
#define Q3 5
#define Q4 6
#define Q5 7
#define Q6 8
#define B 9

typedef struct {
	int pos;
	int state;
	int size;
	int* tape;
} chain_t;

chain_t* make_chain(int m, int n);

int* allocate_memory(chain_t* chain);

void fill_memory(chain_t* chain);

void free_chain(chain_t* chain);

void check_memory(chain_t* chain);

int* make_tape(int m, int n);

#endif
