#include<iostream>
#include<queue>
#include<list>

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

struct node* root ; 
struct node* insert(struct node* , int);
void inorder(struct node*);

void inorder(struct node* root){
	if(root == NULL) return ;
	else{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

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

void levelorder(struct node* root){
	struct node* ptr ;
	if(root == NULL) return ;
	else{
		std::queue<struct node*> q ;
		q.push(root);
		while(!q.empty()){
			ptr = q.front();
			q.pop();
			cout<<ptr->data <<" ";
			if(ptr->left != NULL)
				q.push(ptr->left);
			if(ptr->right != NULL)
				q.push(ptr->right);
		}
	}
}

void swap(struct node* swaplr){
	if(swaplr->left)
		cout<<"the left has 2 left leaf"<<endl;
	if(swaplr->right)
		cout<<"right -----"<<endl;
}
void levelorderlevel(struct node* root,int l){
        struct niode* ptr ;
	static struct node* lparent ;
	struct node* temp ;
	int level = 0 ; 
        if(root == NULL) return ;
	if(l == 0){
		swap(lparent);
		//cout<<"parent "<<lparent->data <<endl ;
		//temp = lparent->left ;
		//lparent->left = lparent->right ;
		//lparent->right = temp ;
		//cout<<lparent->left->data<<" "<<endl;
		//cout<<lparent->right->data<<" "<<endl;	
		return ; 
	}
	else{
		lparent = root ;
		levelorderlevel(root->left,l-1);
		levelorderlevel(root->right,l-1);
        }
	cout<<endl ;
}

void printDepth_list_again(struct node* root, vector<std::list<struct node*> > lists , int level){
	
	cout<<__func__<< "+++"<<endl ;
	if(root == NULL)
		return ;
	cout<<"level "<<level <<endl ; 
	list<struct node*> *ll = NULL ;
	if(lists.size() == level){
		ll = new list<struct node*>();
		cout<<"Addingt to the vetor "<<endl;
		lists.push_back(*ll);
	}
	else{
		auto l_pos = lists.begin();
		std::advance(l_pos,level);
		*ll = *l_pos ;
	}
	cout<<"adding "<< root->data <<endl ; 
	ll->push_back(root);
	printDepth_list_again(root->left,lists,level+1);
	printDepth_list_again(root->right,lists,level+1);
	cout<<__func__<<"---"<<endl ;
	
}
vector<list<struct node*> > printDepth_list(struct node* root){

	cout<<root->data <<endl ;	
	cout<<__func__<< "+++"<<endl ;
	vector<list<struct node*> > lists ;
	printDepth_list_again(root,lists,0);
	cout<<__func__<<"---"<<endl ;
//	printList(lists[2]);
	return lists ;  
}


void printList(list<struct node*> l){
	cout<<__func__<< "+++"<<endl ;
	list<struct node*>::iterator it = l.begin() ;
	while(it != l.end())
	{
		cout<<(*it)->data<<endl ;
		++it;
	}
	cout<<__func__<<"---"<<endl ;	
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
//	inorder(begin);
//	cout<<endl ;
//	cout<<endl ; 
//	levelorder(begin);
//	cout<<endl ; 
//	cout<<endl ;
//	levelorderlevel(begin,2);--not working 
//	cout<<endl ;
//	cout<<endl ;
//	levelorder(begin);
	cout<<endl ;
	cout<<endl ;
	vector<list<struct node*> > lists = printDepth_list(begin); 
	if(lists.size() > 0 ){
		for(int i = 0 ; i < lists.size() ; ++i){
			printList(lists[i]);
		}
	}
	return 0 ;	
}
