#include<iostream>
#include<list>

using namespace std ;


int main()
{
 list<int> ll ;
 ll.push_back(1) ;
 ll.push_back(2);
 ll.push_back(33);
 ll.push_back(55);
 
 cout<<" at the back " <<ll.back() <<endl;
 cout<<" at the front " <<ll.front() <<endl ;

 cout<<endl ;

 ll.push_back(25) ;
 ll.push_front(50);
 
 cout<<"list size "<< ll.size()<<endl ;
 cout<<"list max_ size "<< ll.max_size()<<endl<<endl<<endl ; ;

 list<int>::iterator it = ll.begin() ;

 while(it != ll.end()){
 cout<<*it<<endl ;
 ++it ;
 }

 list<int>::iterator it3 = ll.begin() ; 

 advance(it3,3); // delete the fourth index 
 ll.erase(it3);

 cout<<"reverse"  <<endl ;
 cout<<endl ;
 list<int>::reverse_iterator rit = ll.rbegin() ;

 while(rit != ll.rend()){
 	cout<<*rit<<endl ;
	rit++;
 }

 return 0 ; 

}
