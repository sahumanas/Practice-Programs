#include<iostream>
#include<cstring>
using namespace std ;

int max(int a , int b){
  return a > b ? a : b ;
}
int maxPaliSequence(string& stringToBeChecked , int& len){
 cout<<len<<endl ; 
 int table[len][len] ;
 //For length 1 fille out the table 
 for(int i  = 0 ; i < len ; i++ ){
	table[i][i] = 1 ;
 }
 //For length > 1
 for(int l = 2 ; l <= len ; ++l){
  for(int i = 0 ; i < len - l + 1  ; ++i){
   int j = i + l - 1 ; 
   if(l == 2 && stringToBeChecked[i] == stringToBeChecked[j]){ // This case is foe --while checking with 2 length string 
	table[i][j] = 2 ;
	
   }
   else if(stringToBeChecked[i] == stringToBeChecked[j]){ 
	table[i][j] = 2 + table[i+1][j-1] ;
   }
   else{
	table[i][j] = max(table[i][j-1],table[i+1][j]);

   }
   
  }
 }

 cout<<endl<<table[0][len - 1]<<endl ;
}
int main(){
 string str = "foofooxyz";
 int len = str.length();
 maxPaliSequence(str,len);
 return 0 ;
}
