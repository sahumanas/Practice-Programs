#include<iostream>
#include<cstring>
using namespace std ;

int main()
{
 string str1 = "There are two needles in this haystack with needles" ;
 string str2 = "needles" ;

 // strlength and strlen both are same 
 cout <<"str1 length " <<str1.length() <<endl ;
 cout <<"str1 strlen " <<strlen(str1.c_str()) <<endl ;

 // printing the value of string i.e c_str 
 cout<<str1.data() <<endl ; // c_str value 
 size_t pos = str1.find(str2) ;
 if (pos != string::npos )
	cout<<"string 2 found at "<<pos <<endl ;
 else
	cout<<"not found "<<endl ;
 
 // get a part of string in a source string
 string str3 = str1.substr(8,4);
 cout<<"part of string "<<str3<<endl ;
  
 return 0 ;
}
