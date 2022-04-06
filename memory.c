#include "memory.h"
#include <stdlib.h>
#include <stdio.h>

chain_t* make_chain(int m, int n) {
	chain_t* chain = (chain_t*)malloc(sizeof(chain_t));
	if (chain != NULL) {
		chain->size = m + n + 1;
		chain->pos = 0;
		chain->state = Q0;
		chain->tape = make_tape(m, n);

		return chain;
	}
	else {
		fprintf(stderr, "FAILED TO ALLOCATE CHAIN.\n");
		exit(EXIT_FAILURE);
	}
}

int* make_tape(int m, int n) {
	int i = 0;
	int* tape = (int*)calloc(4 * (m + n + 1), sizeof(*tape));

	if (tape != NULL) {
		for (i = 0; m > 0; i++, m--)
			tape[i] = 0;
		tape[i] = 1;

		for (++i; n > 0; i++, n--)
			tape[i] = 0;
		return tape;
	}
	else {
		fprintf(stderr, "FAILED TO CREATE TAPE\n");
		exit(EXIT_FAILURE);
	}
}

void free_chain(chain_t* chain) {
	free(chain->tape);
	free(chain);
}

int* allocate_memory(chain_t* chain) {
	chain->size*=2;
	int* reallocated_tape = (int*)realloc(chain->tape, chain->size * sizeof(*(chain->tape)));

	if (reallocated_tape == NULL){
		fprintf(stderr,"FAILED TO REALLOCATE MEMORY\n");
		free_chain(chain);
		exit(EXIT_FAILURE);
	}
	else
		return reallocated_tape;
}

void fill_memory(chain_t* chain) {
	for (int i = chain->pos; i < chain->size; i++)
		chain->tape[i] = B;
}

void check_memory(chain_t* chain) {
	if (chain->pos >= chain->size) {
		chain->tape = allocate_memory(chain);
		fill_memory(chain);
	}
}