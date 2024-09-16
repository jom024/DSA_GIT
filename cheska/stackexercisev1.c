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
    Person a = {"Cunado, Jomar ", 19, 'M'};
    
    push(&s, x);
    push(&s, y);
    push(&s, z);
    push(&s, w);

    insertSorted2(&s, a);

    sortStack(&s, true);

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
    Person p = {"", 0, 0};
    return (s == NULL) ? p : s->data;
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
    Stack temp;
    initStack(&temp);

    while(!isEmpty(*s) && (*s)->data.name[0] < p.name[0]){
        Person q = peek(*s);
        pop(s);
        push(&temp, q);
    }

    push(s, p);

    // displayStack(temp);
    //  displayStack(*s);
    while(!isEmpty(temp)){
        Person q = peek(temp);
        pop(&temp);
        push(s, q);
    }
}


/*Sort the values based on name. Use flag for ascending 
  or descending. */

  //asc = flag is true
  //desc = flag is false
void sortStack(Stack *s, bool flag){
    Stack temp;
    initStack(&temp);
    Stack temp2;
    initStack(&temp2);
    Person p, q;

    while(!isEmpty(*s)){
        p = peek(*s);
        pop(s);
        push(&temp, p);
    }

    while(!isEmpty(temp)){
        p = peek(temp);
        q = peek(*s);
        if((flag == true) ? p.name[0] < q.name[0] || isEmpty(*s) : 
                            p.name[0] >= q.name[0] || isEmpty(*s)){
            pop(&temp);
            push(s, p);
        } else {
            while((flag==true) ? !isEmpty(*s) && p.name[0] > q.name[0] :
                                    !isEmpty(*s) && p.name[0] <= q.name[0]){
                pop(s);
                push(&temp2, q);
                q = peek(*s);
            }
            pop(&temp);
            push(s, p);
            while(!isEmpty(temp2)){
                q = peek(temp2);
                pop(&temp2);
                push(s, q);
            }
        }
    }
}

/*Insert sorted base on lastname. Rember to use the property 
  of the stack but without using push, pop, and peek functions.*/
//   ascending by default
bool insertSorted2(Stack *s, Person p){
    NodePtr *trav;
    for(trav = s; *trav != NULL && (*trav)->data.name[0] < p.name[0]; trav = &(*trav)->link);
    printf("%s\n\n", (*trav)->data.name);
    NodePtr temp = (NodePtr)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = p;
        temp->link = *trav;
        *trav = temp;
    }

}
