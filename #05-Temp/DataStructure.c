#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];  
int top = -1; 

void push(int data); 
int pop();
void show();
int isEmpty();
 
int main(){

    int value;
    char request;
    int i;

    while(1){

        printf( 
            " Menu\n"
            " ============================\n"
            " Press 1 push\n"
            " Press 2 pop\n"
            " Press 0 End of run\n"
            " ============================\n\n"
        );
            
        scanf("%s", &request);

        switch(request){
        case '1':
            printf("Plz input data: ");
            scanf("%d", &value);
            push(value);
            break;
        case '2':
            pop();
            break;
        case '0':
            printf("End of run... ...\n\n");
            return 0;
            break;
        default:
            printf("Error\n");
            break;
        }
        show();
    } 
    system("pause");
    return 0;
}

int isEmpty() { return (top == -1) ? 1 : 0; }

void push(int data) {
    if(top >= MAX) { printf("Stack is full\n"); 
    } else {
        top++;
        stack[top] = data;
    }
} 

int pop() {

    int data;

    if(isEmpty()){ printf("Stack is empty\n");
    } else {
        data = stack[top];
        top--;
        return data; 
    }
    return 0;
}

void show(){
    int i;
    printf("************************\n\n");
    for(i=0; i<=top; i++) printf(" %d ",stack[i]);
    printf("\n************************\n\n");
}