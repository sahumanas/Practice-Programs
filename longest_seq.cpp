#include<iostream>
#include<vector>
using namespace std ;

//This function is onlyt to get the ceile index 
int GetIndex(int arr[], std::vector<int> &temp , int l , int r , int key){
 while(r - l > 1 ){
  int m = l + (r - l ) /2 ;
  if(arr[temp[m]] >= key)
        r = m ;
  else
        l = m ;
 }
 return r ;
}

// This is main functiuonm to get the longest increasing sequence  
int getLongestIncreasingSequence(int v[] , int n ){
 for(int i = 0 ; i < n; i++)
	cout<<v[i]<<" " ; 

 cout<<endl;

 std::vector<int> temp(n , 0 );
 std::vector<int> res(n , -1 );
 int len = 1 ; //default length 
 for(int i = 1 ; i < n; i++){
  if(v[i] < v[temp[0]]){
        temp[0] = i ;
  }
  else if ( v[i] > v[temp[len - 1]]){
        res[i] = temp[len - 1] ;
	temp[len++] = i ;
  }
  else{
        //Get the ceilIndex 
        int pos = GetIndex(v , temp , -1 , len-1 , v[i]);
        res[i] = temp[pos - 1] ;
	temp[pos] = i ;
  }
 }

//Printing the rtemporary array 
 cout<<"print temp"<<endl ;
  for(int i = 0 ; i < n; i++)
        cout<<temp[i]<<" " ;

 cout<<endl;

//Printing  the result array
 cout<<"print res"<<endl ;
  for(int i = 0 ; i < n; i++)
        cout<<res[i]<<" ";

 cout<<endl ;
 
//Printing the increasing order sequence  
 for(int i = temp[len-1] ; i >0 ; i= res[i])
	cout<<v[i]<<" ";

 cout<<endl ;
 return len ;
}

int main(){
 int arr[] = {2, 5, 3, 7, 11, 8, 10, 13, 6};
// vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]) );
// std::vector<int> v(2, 5, 3, 7, 11, 8, 10, 13, 6);
// int n = sizeof(arr) / sizeof(arr[0]) ;
 int n = sizeof(arr) / sizeof(arr[0]);
 cout<< getLongestIncreasingSequence(arr,n)<<endl;
 return 0 ;
}
