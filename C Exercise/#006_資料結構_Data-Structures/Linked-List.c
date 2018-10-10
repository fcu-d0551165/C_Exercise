//
//未完成Debug
//
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
}Node; 

/*get the memory*/
Node *create(){  
    Node *tmpNode;
    tmpNode = (Node *)malloc(sizeof(Node));	 
    if(tmpNode == NULL){
        printf("Not enough space!");
        exit(1);
    }
    tmpNode->next = NULL;
    return tmpNode;
}

/*create the Note*/
void Push(Node *head, int data){
    Node *tmp = create();
    tmp->next = NULL;
    tmp->data = data;
    
    /*add the new node in to linked lists*/ 
    Node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next; //walk to next.
    }
    ptr->next= tmp;	// add the new note in the back.
}

/*Print the List*/
void List(Node *head){
	reverseList(head);
    Node *ptr = head;
    while(ptr->next != NULL){
        ptr=ptr->next;
        printf("%d\t",ptr->data);
    }
    printf("\n");
    reverseList(head);	//Restore
}

/*Delete the Note(Last one)*/
void Pop(Node *head){
	
	if(head == NULL || head->next == NULL){
		printf("list is empty!");
		return;
	}
	
    Node *ptr = head;			
    Node *tmp = NULL;
    
    while(ptr->next != NULL){
        tmp = ptr;
        ptr = ptr->next;
    }
    free(ptr);
    tmp->next = NULL; 
}

int reverseList(Node* first){

	if(first == NULL || first->next == NULL){
 		exit(1);
	}

	Node* previous = NULL;
	Node* current = first->next;
	Node* preceding = current->next;

	while(preceding  != NULL){
 		current->next = previous;
 
 		previous = current;
 		current = preceding;
 		preceding = preceding->next;
	}
	
	current->next = previous;
	first->next = current;
}


int SWAP(Node* first){

	if(first == NULL || first->next == NULL){
 		exit(1);
	}
	
	Node*Holding = NULL;
	
	Node* previous = NULL;
	Node* current = first->next;
	Node* preceding = current->next;

	while(preceding  != NULL){
		
 		if(current->data > preceding->data){
 			Holding->next = preceding->next;
 			preceding->next = previous->next;
 			previous->next = Holding->next;
		}
			current->next = previous;
 
	  		previous = current;
	  		current = preceding;
	  		preceding = preceding->next;	
		
	}
	
	current->next = NULL;
}

void Instructions(void){
		printf(	"%s",	"\n-------  Instructions  ---------\n\n"

							"Selections:\n\n"
								"\t 1 - Push\n"
								"\t 2 - Pop\n"
								"\t 3 - List\n"
								"\t 4 - reverseList\n"
								"\t 0 - Exit\n\n"
								
								"--------------------------------\n");
}

int main(){
	
	int data;
	Node *head = create();
	char request;
	
	Instructions();
	
	while(1){
		printf("\n\t - Enter request ==>  ");
		scanf("%s",&request);	// request value 
		printf("\n");	
		
		switch(request){
			case'0':	//End of run
				printf("	- End of run -\n\n");
				exit(1); 
				break;
						
			case'1'://Push
					printf("Plz input the data:  ");
					scanf("%d",&data);
					Push(head, data);			
				break; 
				
			case'2'://Pop
				Pop(head);
				break; 
					
			case'3'://print List		
				printf("\n List:\t");
				List(head);
				printf("=====================\n");
				break;
			
//			case'4'://Pop
//				SWAP(head);
//				break;
			
			
			default://Eorr-Other key
				printf("\n Miss Eorr\n");
				break;
		}
	}
	
return 0;
} 