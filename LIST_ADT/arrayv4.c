#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct List {
    int* arr;
    int count;
} *List;

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
    *L = (List)malloc(sizeof(struct List));
    (*L)->arr = (int*)malloc(sizeof(int) * MAX);
    (*L)->count = 0;
}

void insertFirst(List* L, int x){
    if((*L)->count < MAX){
        int i;
        for(i = (*L)->count; i > 0; --i){
            (*L)->arr[i] = (*L)->arr[i-1];
        }
        (*L)->count++;
        (*L)->arr[0] = x; 
    } 
}

void insertLast(List* L, int x){
    if((*L)->count < MAX){
        (*L)->arr[((*L)->count++)] = x;
    }
}

void sort(List* L){
    int min, i, j, temp;
    for(i = 0; i < (*L)->count; ++i){
        min = i;
        for(j = i+1; j < (*L)->count; ++j){
            if((*L)->arr[j] < (*L)->arr[min]){
                min = j;
            }
        }
        temp = (*L)->arr[i];
        (*L)->arr[i] = (*L)->arr[min];
        (*L)->arr[min] = temp;
    }
}   

void insertSorted(List* L, int x){
    int i, j;
    for(i = 0; i < (*L)->count && (*L)->arr[i] < x; i++);
    for(j = (*L)->count++; j > i; j--){
        (*L)->arr[j] = (*L)->arr[j-1];
    }

    (*L)->arr[i] = x;
}

int searchElem(List L, int elem){
    int index;
    for(index = 0; index < L->count && L->arr[index] != elem; index++);

    return (index < L->count) ? index : -1;
}

void deleteElem(List *L, int x){
    if(searchElem(*L, x) != -1){
        int i = searchElem(*L, x);
        while(i < --(*L)->count){
            (*L)->arr[i] = (*L)->arr[i + 1]; 
        }
    }
    
}

void deleteOcc(List *L, int x){
    int i;
    for(i = 0; i < (*L)->count;){
        if((*L)->arr[i] == x){
            int j;
            (*L)->count--;
            for(j = i; j < (*L)->count; j++){
                (*L)->arr[j] = (*L)->arr[j+1];
            }
        } else {
            ++i;
        }
    }
}

void deleteAll(List*L){
    (*L)->count = 0;
}


void display(List L){
    printf("\nList Elements: \t");
    int i;
    for(i = 0; i < L->count; ++i){
        printf("%d\t", L->arr[i]);
    }
}

