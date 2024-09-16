#include <stdio.h>
#include <stdlib.h>

#define MAX 10

//type definition
typedef struct {
    int arr[MAX];
    int count;
} List;

//function ops
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
    initList(&L);

    insertFirst(&L, 1);
    insertLast(&L, 5);
    insertLast(&L, 3);
    insertLast(&L, 7);
    
    
}