#include "../src/advin.h"
#include <stdio.h>

int main(void)
{
	printf("------------- TESTING -------------\n");
	long int input = get_long("Number: ");

	printf("Number: %ld\n", input);
}
