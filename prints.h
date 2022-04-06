#ifndef _PRINTS_H_
#define _PRINTS_H_

#include "memory.h"

void print_start(chain_t* chain);

void print_state(chain_t* chain);

void print_schematics(chain_t* chain, int size);

int find_result(chain_t* chain);

void print_result(chain_t* chain);

int check_b(chain_t* chain);

void info(void);

#endif