#include <stdio.h>



void swap(int *lhs, int *rhs);

int main(void) {
	int a = 4;
	int b = 7;
	
	printf("\n before==%d \t%d", a, b);
	
	swap(&a, &b);
	
	printf("\n after==%d \t%d", a, b);
	
	return 0;
}

void swap(int *lhs, int *rhs) {
	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;	
}