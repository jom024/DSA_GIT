#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    int* arr;
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

    insertFirst(&L, 13);
    insertFirst(&L, 332);
    insertFirst(&L, 33);
    insertFirst(&L, 33);
    insertFirst(&L, 33);
    insertFirst(&L, 3);
    insertLast(&L, 4);

    display(L);

    sort(&L);

    insertSorted(&L, 17);

    printf("\n\nOrder after sorting: \n");
    display(L);

    deleteElem(&L, 332);
    deleteOcc(&L, 33);

    display(L);

    deleteAll(&L);
    display(L);
}

void initList(List* L){
    L->arr = (int*)malloc(sizeof(int) * MAX);
    L->count = 0;
}

void insertFirst(List* L, int x){
    if(L->count < MAX){
        int i;
        //shift elements
        for(i = L->count ; i > 0; --i){
            L->arr[i] = L->arr[i - 1];
        }
        L->arr[0]=x;
        L->count++;
    }
}

void insertLast(List* L, int x){
    if(L->count < MAX){
        L->arr[L->count++] = x;
    }
}

void sort(List* L){
    int i, j, key, temp;
    for(i = 0; i < L->count; i++){
        key = i;
        for(j = i + 1; j < L->count; j++){
            if(L->arr[j] < L->arr[key]){
                key = j;
            }
        }
        temp = L->arr[i];
        L->arr[i] = L->arr[key];
        L->arr[key] = temp;
    }
}          

void insertSorted(List* L, int x){
    int i, j;
    for(i = 0; i < L->count && L->arr[i] < x; i++);
    for(j = L->count++; j > i; --j){
        L->arr[j] = L->arr[j-1];
    }
    L->arr[i] = x;
}

int searchElem(List L, int elem){    //returns -1 if element is not found; the index of element if found
    int i;
    for(i = 0; i < L.count && L.arr[i] != elem; i++);

    return (i == L.count) ? -1 : i;
}

void deleteElem(List *L, int x){     //let x be the value to be deleted from the list
    int i = searchElem(*L, x);
    if(i > -1){
        while(i < L->count){
            L->arr[i++] = L->arr[i];
        }
        L->count--;
    }
}

void deleteOcc(List *L, int x){
    int i, j;
     for(i = 0; i < L->count; ){
        if(L->arr[i] == x){
            for(j = i; j < L->count; j++){
                L->arr[j] = L->arr[j+1];
            }
            L->count--;
        } else {
            i++;
        }
     }
}

void deleteAll (List *L){
    L->count = 0;
}

void display(List L){
    printf("\nList element: \t");
    int i;
    for(i = 0; i < L.count; ++i){
        printf("%d\t", L.arr[i]);
    }
}