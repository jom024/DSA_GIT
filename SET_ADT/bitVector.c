#include <stdio.h>
#include <stdlib.h>

#define MAX 15

typedef struct {
	int elem[MAX];
	int count;
} Set;

void initSet(Set* s);
void insert(Set *s, int x);
int isElem(Set s, int x);
int isFull(Set s);
int isEmpty(Set s);
void deleteElem(Set *s, int x);
Set symmetricDiff(Set x, Set y);
Set unionSet(Set x, Set y);

void display(Set s);

void main(){
	Set A, B;
	initSet(&A);
	initSet(&B);
	
	insert(&A, 5);
	insert(&A, 14);
	insert(&B, 9);
	insert(&B, 5);
	insert(&B, 10);
	
	Set C = unionSet(A, B);
	Set D = symmetricDiff(A, B);
	
	display(A);
	
	display(B);
	
		display(C);
		display(D);

}

void initSet(Set*s){
	int i;
	for(i = 0; i < MAX; ++i){
		s->elem[i] = 0;
	}
	s->count = 0;
}

void insert(Set *s, int x){
	if(!isFull(*s)){
		s->elem[x] = 1;
		s->count++;
	} else {
		printf("\nSet is full!\n");
	}
}

int isElem(Set s, int x){
	int i;
	for(i = 0; i < MAX && s.elem[i] != x; ++i);
	
	return (i != MAX) ? i : -1;	
}

int isFull(Set s){
	return s.count == MAX;
}

int isEmpty(Set s){
	return s.count == 0;
}

void deleteElem(Set *s, int x){
	if(!isEmpty(*s) && isElem(*s, x)){
		s->elem[x] = 0;
		s->count--;
	} else {
		printf("Element not found!");
	}
}

Set unionSet(Set x, Set y){
	Set Z;
	int i;
	for(i = 0; i < MAX; ++i){
		Z.elem[i] = (x.elem[i] || y.elem[i]) ? 1 : 0; 
	}
	
	return Z;
}

Set symmetricDiff(Set x, Set y){
	Set Z;
	int i;
	for(i = 0; i < MAX; ++i){
		Z.elem[i] = (x.elem[i] ^ y.elem[i]) ? 1 : 0;
	}
	
	return Z;
}

void display(Set s){
	int i;
	for(i = 0; i < MAX; ++i){
		if(s.elem[i] == 1){
			printf("%d ", i);
		}
	}
	printf("\n");
}
