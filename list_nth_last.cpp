#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
/* Function to reverse the linked list */
static void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
 
/* Function to push a node */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
            
    /* put in the data  */
    new_node->data  = new_data;
                
    /* link the old list off the new node */
    new_node->next = (*head_ref);    
        
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
}    

void printnthLast(struct node *head , int n )
{
	printf("\n\nprintnthLast\n");
	struct node *firstptr = head ;
	struct node *slowptr = head ;
	for(int i = 0 ; i < n-1 ; i++){
		if(slowptr == NULL){
			printf("\nbreak\n");
			break;
		}
		slowptr = slowptr->next ;
	}
	
	while (slowptr->next != NULL) {
		firstptr = firstptr->next;
		slowptr = slowptr->next;
	  }

	printf("nth last --%d  ", firstptr->data);
}
 
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
   
	push(&head, 20);
	push(&head, 4);
	push(&head, 15); 
	push(&head, 85);      
	push(&head, 35);
	push(&head, 25);
	push(&head, 100);
	push(&head, 40);
	
     
     printf("Given linked list\n");
     printList(head);    
     printnthLast(head, 2);
//    reverse(&head);                      
//     printf("\nReversed Linked list \n");
//     printList(head);    
     getchar();
}
