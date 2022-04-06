#include <stdio.h>
#include <stdlib.h>
#include "turing.h"
#include "prints.h"

int main(void) {
	int m = 0, n = 0;
	
	info();

	printf("Podaj m : ");
	scanf_s("%d", &m);
	printf("Podaj n: ");
	scanf_s("%d", &n);
	putchar('\n');

	if (m < 0 || n < 0) {
		fprintf(stderr, "WRONG PARAMETERS VALUES");
		exit(EXIT_FAILURE);
	}

	chain_t* chain = make_chain(m, n);

	printf("Ciag opisow chwilowych : \n");
	delta(chain);
	putchar('\n');
	print_result(chain);
	free_chain(chain);

	exit(EXIT_SUCCESS);
}