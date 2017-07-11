#include<iostream>
using namespace std ;

#define ALPHABATE_SEZE 26 

#define CHAR_TO_INDEX(x) ((int)x - (int)'a')

typedef struct node{
	struct node *child[ALPHABATE_SEZE] ;
	int isLeaf ;
} TrieNode ;

TrieNode *getNode(){
	struct node *pNode = new struct node() ;
	pNode->isLeaf = false ;
	for(int level = 0 ; level < ALPHABATE_SEZE ; level++ ){
		pNode->child[level] = NULL ;
	}
}

void insert(TrieNode *root,string &w){
	int tlevel ;
	int index ;
	TrieNode *storeRootNode = root ; 
	for(int level = 0 ; level < w.length() ; level++){
		index = CHAR_TO_INDEX(w[level]);
                 if(!storeRootNode->child[index])
			storeRootNode->child[index] = getNode();

		storeRootNode = storeRootNode->child[index] ;
	}
	storeRootNode->isLeaf = true ;
}

bool search(TrieNode *root , string &w){
	int index ;
	TrieNode *begin = root ;
	for(int level = 0 ; level < w.length() ; level++){
        	index = CHAR_TO_INDEX(w[level]);
		if(!begin->child[index])
                   	return false ;
                begin = begin->child[index] ;
	}
	
	return (begin != NULL && begin->isLeaf) ; 
}

int main(){
 TrieNode *begin = getNode() ;
 string word = "book";
 string word3 = "bookkeeper";
 insert(begin,word);
 insert(begin,word3);

 if(search(begin,word))
	cout<<" found" <<endl ;
 else
	cout<<" not found" <<endl ;

 string word1 = "world";

 if(search(begin,word3))
         cout<<" found" <<endl ;
 else
         cout<<" not found" <<endl ;

 return 0 ;	
}
