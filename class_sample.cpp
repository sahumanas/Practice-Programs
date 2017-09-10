#include<iostream>

using namespace std ;

class X{
// public : 
// string text ;
// char *ptr ;
 public :
 X(){
	cout<<"m in ctor"<<endl;
 }
 X(string s ): text(s)
 {
	cout<<"m in parameterised ctor"<<endl;
 }
 ~X()
 {
	cout<<"m in dtor"<<endl;
 }
 X(const X& obj){
	cout<<"m in copy ctor"<<endl;
//	cout<<"copy ctor "<<obj.text<<endl;
//	cout<<"copy ctor address  "<<&(obj.text)<<endl;
	this->text = obj.text ;
 }
};

int main()
{
 X x("initialisation") ; 
 X y = x ;
 return 0 ;
}
