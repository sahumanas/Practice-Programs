#include<iostream>
#include<forward_list>

using namespace std ;

int main(){
 forward_list<int> n1 ;
 forward_list<int>::iterator it , it2 ;
 n1.push_front(2);
 n1.push_front(3);
 n1.push_front(30);
 n1.push_front(34);
 n1.push_front(31);
// n1.pop_front();
 it2 = n1.begin() ;
 n1.insert_after(n1.begin(),10);

 it = n1.begin() ;
 while(it != n1.end()){
 cout<<*it <<" "<<endl ;
 it++ ;
 }
 return 0 ; 
}
