#include<iostream>
#include<queue>
#include<list>
#include<cmath>
using namespace std ;
void printList(list<struct node*> );
struct node{
 int data ;
 struct node *left ;
 struct node *right;
 node(int d){
	data = d ;
	left = right = NULL ; 
 };
};
int lheight ;
int rheight ;
struct node* root ; 
struct node* insert(struct node* , int);


struct node* insert(struct node *root , int data){

 if(root == NULL) return new node(data) ;
 if(root->data > data){
	root->left = insert(root->left,data); 
 }
 else if(root->data < data){
	root->right = insert(root->right,data);
 }
 return root ; 

}

int getHeight(struct node* root){
	if(root == NULL)
		return -1 ;
	else{
		cout<<root->data <<endl ; 
		int lheight = getHeight(root->left) ;
//		cout<<" lheight after getHeight "<< lheight <<endl ;
		int rheight = getHeight(root->right) ;
		cout<<" returning "<< max(lheight , rheight) + 1 <<endl ;
		return (max(lheight , rheight) + 1) ;
	}
}
int main(){
	struct node* begin = NULL;
	begin = insert(begin,50);
	insert(begin,40);
	insert(begin,70);
	insert(begin,25);
	insert(begin,41);
	insert(begin,60);
	insert(begin,75);
	insert(begin,20);
	insert(begin,26);
	cout<<endl ;
	cout<<endl ;
	cout<<getHeight(begin)<<endl;;
}
