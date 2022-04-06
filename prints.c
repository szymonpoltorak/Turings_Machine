#include <stdio.h>
#include <stdlib.h>
#include "prints.h"

void info(void) {
	printf("Program symuluje dzialanie Maszyny Turinga obliczajaca roznice wlasciwa liczb m - n.\n");
	printf("M = ( {q0, q1, q2, q3, q4, q5, q6}, {0, 1, B}, DELTA, q0, B, PUSTY)\n\n");
	printf("DELTA     0            1             B\n");
	printf("------------------------------------------\n");
	printf("q0    (q1,B,P)    (q5, B, P)         -\n");
	printf("------------------------------------------\n");
	printf("q1    (q1,0,P)    (q2, 1, P)         -\n");
	printf("------------------------------------------\n");
	printf("q2    (q3,1,L)    (q2, 1, P)    (q4, B, L)\n");
	printf("------------------------------------------\n");
	printf("q3    (q3,0,L)    (q3, 1, L)    (q0, B, P)\n");
	printf("------------------------------------------\n");
	printf("q4    (q4,0,L)    (q4, B, L)    (q6, 0, P)\n");
	printf("------------------------------------------\n");
	printf("q5    (q5,B,P)    (q5, B, P)    (q6, B, P)\n");
	printf("------------------------------------------\n");
	printf("q6        -            -             -\n");
}

void print_start(chain_t* chain) {
	printf("Q0");
	for (int i = 0; i < chain->size; i++)
		printf("  %d", chain->tape[i]);
}

void print_state(chain_t* chain) {
	if (chain->state == Q0)
		printf("  Q0");
	if (chain->state == Q1)
		printf("  Q1");
	if (chain->state == Q2)
		printf("  Q2");
	if (chain->state == Q3)
		printf("  Q3");
	if (chain->state == Q4)
		printf("  Q4");
	if (chain->state == Q5)
		printf("  Q5");
	if (chain->state == Q6)
		printf("  Q6");
}

void print_schematics(chain_t* chain, int size) {
	printf("  |-");
	for (int i = 0; i < size; i++) {
		if (i == chain->pos)
			print_state(chain);
		if (chain->tape[i] == 9)
			printf("  B");
		else
			printf("  %d", chain->tape[i]);
	}
	if (chain->pos == size)
		print_state(chain);
}

void print_result(chain_t* chain) {
	printf("\nWynikiem odejmowania jest : %d\n", find_result(chain));
}

int find_result(chain_t* chain) {
	int temp = 0;

	for (int i = 0; i < chain->size; i++) {
		if (chain->tape[i] == 0)
			temp++;
	}
	if (temp > 0)
		return temp;
	else
		return 0;
}

int check_b(chain_t* chain) {
	int i = 0;

	for (i = chain->size - 1; chain->tape[i] == B; i--)
		;
	if (i < chain->pos)
		return chain->pos;
	return i+1;
}