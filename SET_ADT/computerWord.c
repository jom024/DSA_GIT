//insertfirst
//insertlast
//insertpos
//deletefirst
//deletelast
//deleteany

//union
//intersection
//difference
//asymdiff

#include <stdio.h>

typedef unsigned char Set;

void insertFirst(Set* S){
	unsigned char mask = 1;
	*S = (*S) | mask;
}

void insertLast(Set* S){
	unsigned char mask = 1 << sizeof(unsigned char) * 8 - 1;
	*S = (*S) | mask;
}

void insertPos(Set *S, int pos){
	unsigned char mask = 1 << sizeof(unsigned char) * pos - 1;
	*S = (*S) | mask;
}

void deleteFirst(Set*S){
	unsigned char mask = 1;
	*S = (*S) & (~mask);
}

void deleteLast(Set *S){
	unsigned char mask = 1 << sizeof(unsigned char) * 8 - 1;
	*S = (*S) & (~mask);
}
void deletePos(Set *S, int pos){
	unsigned char mask = 1 << sizeof(unsigned char) * 8 - 1;
	*S = (*S) & (~mask);
}

void display(Set S){
	unsigned char mask = 1 << sizeof(char) * 8 - 1;
	while (mask > 0) {
		printf("%u", ((S & mask)!=0) ? 1 : 0);
		mask >>= 1;
	}
}

void main(){
	Set A = 0;
	
	insertFirst(&A);
	insertLast(&A);
	insertPos(&A, 3);
//	deleteLast(&A);
	
	display(A);
	
}
