#include<iostream>
#include<string.h>
using namespace std ;

int max(int a , int b ){
	return (a > b) ? a : b ;
}
int checkLCS(char* c1 , char* c2 , int m , int n ){
 cout<<"char 1 "<<c1<<endl;
 cout<<"char 2 "<<c2<<endl;
 int L[m+1][n+1];
 for(int i = 0 ; i <= m ; i++){
  for(int j = 0 ; j <= n ; j++){
	if(i == 0 || j == 0 ) 	
		L[i][j] = 0 ;
	else if (c1[i-1] == c2[j-1])
		L[i][j] = L[i-1][j-1] + 1 ;
	else
		L[i][j] = max(L[i-1][j],L[i][j-1]);
   }
 }


 cout<<endl ; 
 cout<<"After filling up the dynamic matrix "<<endl;
  for(int i = 0 ; i <= m ; i++){
  	for(int j = 0 ; j <= n ; j++){
                cout<<L[i][j] <<" ";
   }
   cout<<endl ;
 }
 
 cout<<endl ;
 return L[m][n];
}
int main(){
 char c1[] = "abcdaf";
 char c2[] = "acbcf";
 int m = strlen(c1);
 int n = strlen(c2);
 cout<<checkLCS(c1,c2,m,n)<<endl ;
 return  0 ;
}
