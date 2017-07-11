#include<iostream>
using namespace std ;
class list{

public : 
	void insert(int data);
	void display();
	struct Node{
	 int data ;
	 struct Node *next ;
	} *head;
	list(){
		head = NULL ;
	}
};

void list::display(){
  cout<<"display "<<endl;

  while(head->next != NULL){
	cout<<"after while dis "<<endl;
 	cout<<head->data<<"->";
	head = head->next;
  }
  cout<<head->data<<endl ;
}

void list::insert(int data){
 cout<<data<<" insert "<<endl;
 struct Node *ptr = new Node();
 ptr->data = data ;
 ptr->next = NULL ;
 if(head == NULL)
	head = ptr ; 
 else{
	cout<<"at the end "<<endl;
	struct Node *temp = new Node();
	temp = head ;
	while(temp->next != NULL){
		temp = temp->next ;
	}
	temp = ptr ;
 }
}

int main()
{
 list ll ;
 ll.insert(5);
 ll.insert(10);
// insert(head,15);
// insert(&head,20);
 ll.display();
 return 0 ;
}
