#include<iostream>
using namespace std ;
#define R 4
#define C 3 

//int min(int a , int b , int c ){
//	return min(min(a,b),c);
//}
int min(int a, int b){
	return (a > b)? b : a ; 
}

int minCost(int arr[R][C],int m , int n ){
 int L[m+1][n+1];
 cout<<"Printint the input matrix "<<endl;
 cout<<endl ;
 
   for(int i = 0 ; i <R ; i++){
           for(int j = 0 ; j < C ; j++){
                 cout<<arr[i][j] << " ";
           }
           cout<<endl;
  }
 
  cout<<endl;

 int sum = 0 ;
 for(int i =0 ; i <=m;i++) {
	//Filling the first row 
	L[0][i] = sum + arr[0][i] ;
	sum = L[0][i];
 }

 sum = 0 ;
 for(int j =0 ; j <=m;j++){
	//Filling the first column 
        L[j][0] = sum + arr[j][0] ;
	sum = L[j][0];
 }

cout <<endl ; 

 for(int i = 1 ; i <=m ; i++){
  for(int j = 1 ; j <= n ; j++){
	L[i][j] = arr[i][j] + min(L[i][j-1],/*L[i-1][j-1]*/L[i-1][j]);
  }
 }

 cout<<endl ;
 cout<<"Printing after addition "<<endl ;
  for(int i = 0 ; i <R ; i++){
	  for(int j = 0 ; j < R ; j++){
        	cout<<L[i][j] << " ";
	  }
	  cout<<endl;
 }

 cout<<endl;

 return L[m-1][n-1];
}
int main(){
 int cost[R][C] = {{1,2,3},{4,8,2},{1,5,3},{6,2,9}};
// int cost[R][C] = {{1,3,5,8},{4,2,1,7},{4,3,2,3}};
 cout<<minCost(cost,3,2)<<endl;//11 
 cout<<minCost(cost,2,3)<<endl;//8
 return  0;
}
