#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char name[30];
    int age;
    char sex;
} Person;

typedef struct node {
    Person data;
    struct node* link;
} NodeType, *NodePtr, *Stack;

void initStack (Stack *s);
bool isEmpty(Stack s);
void displayStack(Stack s);

bool push(Stack *s, Person p);
bool pop(Stack *s);
Person peek(Stack s);

/*Insert sorted base on lastname. Rember to use the property 
  of the stack using push, pop, and peek functions.*/
bool insertSorted1(Stack *s, Person p);

/*Insert sorted base on lastname. Rember to use the property 
  of the stack but without using push, pop, and peek functions.*/
bool insertSorted2(Stack *s, Person p);

/*Sort the values based on name. Use flag for ascending 
  or descending. */
void sortStack(Stack *s, bool flag);

void main(){
    Stack s;
    initStack(&s);
    Person x = {"Toledo, January Venice", 5, 'M'};
    Person y = {"Monsalud, Joel", 9, 'F'};
    Person z = {"Ouano, Cheska", 13, 'F'};
    Person w = {"Alvern, Heart Sumicad", 64, 'F'};
    
    push(&s, x);
    push(&s, y);
    push(&s, z);
    push(&s, w);
    // pop(&s);
    // Person p = peek(s);
    // printf("%-8s", "Name:");
    //     printf("%s\n", p.name);
    //     printf("%-8s", "Age:");
    //     printf("%d\n", p.age);
    //     printf("%-8s", "Sex:");
    //     printf("%c\n", p.sex);

    displayStack(s);
}

void initStack (Stack *s){
    *s = NULL;
}

bool isEmpty(Stack s){
    return s == NULL;
}



bool push(Stack *s, Person p){
    NodePtr temp = (NodePtr)malloc(sizeof(struct node));
    if(temp != NULL){
        strcpy(temp->data.name, p.name);
        temp->data.age = p.age;
        temp->data.sex = p.sex;
        temp->link = *s;
        *s = temp;
    }
}

bool pop(Stack *s){
    if(!isEmpty(*s)){
        NodePtr temp = *s;
        *s = temp->link;
        free(temp);
    }

    return isEmpty(*s);
}

Person peek(Stack s){
    return s->data;
}

void displayStack(Stack s){
    while(isEmpty(s) == false){
        Person p = peek(s);
        printf("%-8s", "Name:");
        printf("%s\n", p.name);
        printf("%-8s", "Age:");
        printf("%d\n", p.age);
        printf("%-8s", "Sex:");
        printf("%c\n\n", p.sex);
        pop(&s);
    }
}

/*Insert sorted base on lastname. Rember to use the property 
  of the stack using push, pop, and peek functions.*/
bool insertSorted1(Stack *s, Person p){

}


