#include<iostream>
#include<string.h>
#include<bits/stdc++.h>

using namespace std ;

int min(int a , int b , int c ){
 return min(min(a,b),c);
}
int minEdit(char *c1 , char* c2 ,int m, int n){
 cout<< m <<endl ; 
 cout<< n <<endl ;
 int L[m+1][n+1];
 for(int i = 0 ; i <= m ; i++){
  for(int j =0 ; j <=n ; j++ ){
	if(i == 0 )
		L[i][j] = j ;
	else if (j == 0 )
		L[i][j] = i ;
	else if(c1[i-1] == c2[j-1])
		L[i][j] = L[i-1][j-1];
	else{
		L[i][j]	= 1 + min(L[i][j-1],L[i-1][j],L[i-1][j-1]);
	}
  }
 }


 cout<<"After filing up teh dynamic matrix"<<endl;
 for(int i = 0 ; i <= m ; i++){
  for(int j = 0 ; j <=n ; j++ ){
  	cout<<L[i][j] <<" ";
  }
 cout<<endl ;
 }

 cout<<endl ;

 
 return L[m][n];
}
int main(){
 char c1[] = "abcdef" ;
 char c2[] = "agced";
 int m = strlen(c1);
 int n = strlen(c2);
 cout<<"minimum no of operation required to chnage c1 to c2 "<<endl;
 cout<<minEdit(c1,c2,m,n)<<endl;
 return 0 ;
}
