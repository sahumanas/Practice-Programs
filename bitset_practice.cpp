#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

int main(){
 
 int i = 100 ;
 bitset<8> bit(i) ; 
 cout << bit <<endl ;
 int numberof1 = bit.count();
 cout<<"number of 1 "<<numberof1 <<endl ;
 cout<<"test---"<<bit.test(2)<<endl ;
 cout<<"flip bit 2 ---"<<bit.flip()<<endl ;

 bitset<18> bit1 ;

 bit1.set() ;

 cout<<bit1 <<endl ;

 return 0 ;
}
