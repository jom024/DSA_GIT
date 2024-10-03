#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} *List;

void initList(List* L);
void insertFirst(List* L, int x);    //let x be the value to be inserted into the list
void insertLast(List* L, int x);
void sort(List* L);          
void insertSorted(List* L, int x);
int searchElem(List L, int elem);    //returns -1 if element is not found; the index of element if found
void deleteElem(List *L, int x);     //let x be the value to be deleted from the list
void deleteOcc(List *L, int x);
void deleteAll(List*L);
void display(List L);

void main(){
    List L;
}

void initList(List* L){
    *L == NULL;
}

void insertFirst(List* L, int x){
    
}