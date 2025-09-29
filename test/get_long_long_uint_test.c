#include "../src/advin.h"
#include <stdio.h>

int main(void)
{
	printf("------------- TESTING -------------\n");
	unsigned long long int input = get_long_long_uint("Number: ");

	printf("Number: %llu\n", input);
}
