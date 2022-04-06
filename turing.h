#ifndef _TURING_H_
#define _TURING_H_

#include "memory.h"
#include "prints.h"

#define TRUE 1
#define L -1
#define P 1

void update_tape(chain_t* chain, int value, int state, int movement);

void delta(chain_t *chain);

#endif