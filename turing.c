#include "turing.h"
#include <stdio.h>
#include <stdlib.h>

void update_tape(chain_t* chain, int state, int value, int movement) {
	chain->state = state;
	chain->tape[chain->pos] = value;
	chain->pos += movement;
}

void delta(chain_t *chain) {
	int temp = 1;
	while(TRUE){
		if (temp != 0) {
			print_start(chain);
			temp--;
		}
		if (chain->state == Q0) {
			if (chain->tape[chain->pos] == 0)
				update_tape(chain, Q1, B, P);
			else if (chain->tape[chain->pos] == 1)
				update_tape(chain, Q5, B, P);
			else if (chain->tape[chain->pos] == B)
				break;
		}
		else if (chain->state == Q1) {
			if (chain->tape[chain->pos] == 0)
				update_tape(chain, Q1, 0, P);
			else if (chain->tape[chain->pos] == 1)
				update_tape(chain, Q2, 1, P);
			else if (chain->tape[chain->pos] == B)
				break;
		}
		else if (chain->state == Q2) {
			if (chain->tape[chain->pos] == 0)
				update_tape(chain, Q3, 1, L);
			else if (chain->tape[chain->pos] == 1)
				update_tape(chain, Q2, 1, P);
			else if (chain->tape[chain->pos] == B)
				update_tape(chain, Q4, B, L);
		}
		else if (chain->state == Q3) {
			if (chain->tape[chain->pos] == 0)
				update_tape(chain, Q3, 0, L);
			else if (chain->tape[chain->pos] == 1)
				update_tape(chain, Q3, 1, L);
			else if (chain->tape[chain->pos] == B)
				update_tape(chain, Q0, B, P);
		}
		else if (chain->state == Q4) {
			if (chain->tape[chain->pos] == 0)
				update_tape(chain, Q4, 0, L);
			else if (chain->tape[chain->pos] == 1)
				update_tape(chain, Q4, B, L);
			else if (chain->tape[chain->pos] == B)
				update_tape(chain, Q6, 0, P);
		}
		else if (chain->state == Q5) {
			if (chain->tape[chain->pos] == 0)
				update_tape(chain, Q5, B, P);
			else if (chain->tape[chain->pos] == 1)
				update_tape(chain, Q5, B, P);
			else if (chain->tape[chain->pos] == B)
				update_tape(chain, Q6, B, P);
		}
		else if (chain->state == Q6)
			break;
		check_memory(chain);

		if (temp == 0)
			print_schematics(chain, check_b(chain));
	}
}