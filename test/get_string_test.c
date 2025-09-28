#include "../src/advin.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("------------ TESTING ------------\n");

	// A Normal String
	char *input1 = get_string("");
	printf("Output: %s\n", input1);
	printf("Length: %i\n", (int)strlen(input1));
	free(input1);
}
