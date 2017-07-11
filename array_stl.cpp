#include<iostream>
#include<array>
#include<cstring>
#include <algorithm>
using namespace std ;

int main()
{
 array<int,6> a = {67,5,7,8,90,100} ;

 cout<<"back "<<a.back()<<endl;
 cout<<"front "<<a.front()<<endl;
 for(int i : a){
 cout<<i<<endl;
 }

 const char* cstr = "my string" ;
 array<char,25> c ;
 memcpy(c.data(),cstr,10);
 
 cout<<c.data()<<endl ;

 for(char c1  : c) 
	cout<< c1 ;
 cout<<endl ;

 
 cout<<a.size()<<endl ;

 cout<<a[3]<<endl;


 sort(a.begin(),a.end());
 for(int i : a)  cout<<i<<endl;


 return 0 ;
}

