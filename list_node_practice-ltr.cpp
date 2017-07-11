#include<iostream>
#include<list>

using namespace std ;

typedef struct node{
	int data ;
	struct node *next ;
} nodelist;
int main(){
 list<nodelist> ll ;
 nodelist *n1 = new nodelist() ; 
 nodelist *n2 = new nodelist() ;
 nodelist *n3 = new nodelist() ;
 nodelist *n4 = new nodelist() ;
 nodelist *n5 = new nodelist() ;
 n1->data = 5 ;n1->next = n2 ;
 n2->data = 15 ;n2->next = n3 ;
 n3->data = 25 ;n3->next = n4 ;
 n4->data = 35 ;n4->next = n5 ;
 n1->data = 55 ;n1->next = NULL ;
 return 0 ;
}

