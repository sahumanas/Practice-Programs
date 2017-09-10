#include<iostream>

using namespace std ;

int main(){
 char *from = "from my character" ;
 char *to = from;
 if(from){
	while(*to){
		++to ;
 	}
 }
 --to ;
// cout<<"print to "<<*to ;
 char temp ;
 while(from > to)
 {
	temp = *from ; 
	*from++ = *to;
	*to-- = temp ;

 }

// cout<< from <<endl;
 while(*to){
	
	cout<<*to ;
	++to;
 }
// cout<< to <<endl; 
 return 0; 
}

