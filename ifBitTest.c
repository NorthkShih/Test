#include <stdio.h>

#define DEFER 0x00000002


int main(){

	int i = DEFER & DEFER;
	int j = !(DEFER & DEFER);
	int k = ~(DEFER & DEFER);

	if(i)
		printf("DEFER & DEFER is true");
	printf(", %d\n", i);
	if(!j)
		printf("!(DEFER &DEFER) is false");
	printf(", %d\n", j);
	if(k)
		printf("~(DEFER &DEFER) is true");
	printf(", %d\n", k);

	return 0;
}
