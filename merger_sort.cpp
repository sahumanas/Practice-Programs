#include<iostream>

using namespace std ;

void merge(int arr[],int low , int mid , int high){
	int i ,j,k;
	int n1 = mid - low  + 1 ;
	int n2 = (high - mid );
	int L[n1] ,R[n2] ;
	for(int i = 0 ; i< n1; i++)  
		L[i] = arr[i + low ];
	for(int j = 0 ; j < n2;j++)
		R[j] = arr[mid + j + 1];

	i = 0 ; j = 0 ; k= low ;

	while(i < n1  && j < n2 ){

		if(L[i] <= R[j]){
			arr[k] = L[i]; i++ ;
		}
		else{
			arr[k] = R[j];j++;
		}
		k++ ;
	}

	while(i < n1){
		arr[k] = L[i];
		k++ ;i++;
	}
	while(j < n2){
		arr[k] = R[j];
		k++;j++;
	}
}
void mergeSort(int arr[],int low , int high){

	if(low < high ){
		int mid = low + (high - low ) / 2 ;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
	
}
void disply(int arr[], int size){
	for(int i = 0 ; i <= size ; i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
 int arr[] = {10,40,50,20,10,80,90,30,70,60,100};
 disply(arr, sizeof(arr)/sizeof(arr[0]) -1 );
 cout<<endl ;
 mergeSort(arr,0,sizeof(arr)/sizeof(arr[0]) - 1);
 disply(arr, sizeof(arr)/sizeof(arr[0]) - 1);
 cout<<endl ;
 return 0 ;
}
