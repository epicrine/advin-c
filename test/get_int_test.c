#include "../src/advin.h"
#include <stdio.h>

int main(void)
{
	printf("------------- TESTING -------------\n");
	int input = get_int("Number: ");

	printf("Number: %i", input);
}
