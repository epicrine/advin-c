#include "../src/advin.h"
#include <stdio.h>

int main(void)
{
	printf("------------- TESTING -------------\n");
	unsigned int input = get_uint("Number: ");

	printf("Number: %u\n", input);
}
