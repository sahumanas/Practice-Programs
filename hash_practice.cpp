#include<iostream>
#include<array>
using namespace std ;
struct mset{ int key ;  string value ; } ;
array<struct mset*,11> tab ;
int pre_hash(int key , int length){
	int h_key = key % 11 ; //length ;
	cout << h_key <<endl ;
	return h_key ;
}
 
void insert_hash(int hk , struct mset *pair){
	tab[hk] = pair ;
}

void print_hash(int size){

	for(int i = 0 ; i < size ; i++ ){
	cout<<"key ---i "<< i <<" ---"<<endl ;
	if(tab[i]){
		struct mset *p2 = tab[i] ;
		cout<<"     key--> "<<p2->key <<endl ;
		cout<<"     value--> "<<p2->value <<endl ;
	}
	}
}

int main()
{
 mset *p1 = new mset() ; p1->key = 87 ; p1->value = "A";
 //111 - A //222 - B //333 - C //444 - D //555 - E
 int hash_key = pre_hash(p1->key,5);
 insert_hash(hash_key,p1);
 print_hash(11);
 cout<<endl ;
 return 0 ;
}

