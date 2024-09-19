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
    insertFirst(&L, 3);
    insertLast(&L, 7);
    sort(&L);
    insertSorted(&L, 6);

    insertFirst(&L, 2);
    insertFirst(&L, 1);

    deleteElem(&L, 3);
    deleteOcc(&L, 1);
    display(L);
    
    deleteAll(&L);

}

void initList(List* L){
    L->count = 0;
}

void insertFirst(List* L, int x){    //let x be the value to be inserted into the list
    int i;
    for(i = (L->count)++; i > 0; i--){
        L->arr[i] = L->arr[i-1];
    }
    L->arr[0] = x;
}

void insertLast(List *L, int x){
    L->arr[L->count++] = x;
}

void display(List L){
    int i;
    for(i = 0; i < L.count; i++){
        printf("%d ", L.arr[i]);
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





