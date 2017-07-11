#include<iostream>
#include<vector>
using namespace std ;

#define pb push_back

void print_array(int arr[],int len ){
	for(int i = 0 ; i < len ; ++i ){
		cout<<arr[i]<<" ";
	}
	cout<<endl ;
}

void swap(int *a , int *b ){
	int temp = *b ;
	*b = *a ;
	*a = temp ;
}

int maxofThree(int v[],int l , int r , int index, int &largest){
	if(l < 6 && v[l] > v[r]){
		if(v[l] > v[index])   return 	largest = l ;	
	}
	else if (r < 6 && v[l] < v[r]){
		return largest = r;
	}
		
}
void max_heap(int v[],int index){
	cout<<"max_heap called with index " <<index <<endl;
	cout<<"max_heap v at index "<<v[index ]<<endl;
	int left = (2 * index ) + 1  ;	int right = (2  * index) + 2 ; 
	int largest = index ;
	cout<<"left "<<left <<endl;
	cout<<"right "<<right <<endl;
	
	largest = maxofThree(v ,left ,right , index, largest);
/*	if(v[left] < v[right])
	{
		if(left < 6 && v[left] > v[index]){
			largest = left;
			cout<<"now left is largest -----change" <<endl;
		}
		if(right < 6 && v[right] > v[index]){
			largest = right ;
			cout<<"now right is largest ---change" <<endl;
		}
	}
        else if(right < 6 && v[right] > v[index]){
                 largest = right ;
                 cout<<"now right is largest ---change" <<endl;
        }
*/	
	cout<<"largest is "<<largest <<endl ; 
	if(largest != index){
		cout<<"before swap "<<v[index] << " largest "<<v[largest] <<endl ;
		swap(&v[largest],&v[index]);
		cout<<"after swap "<<v[index] << " largest "<<v[largest] <<endl;
		max_heap(v,largest);
	}
	cout<<endl ;
	print_array(v,6);	
//	max_heap(v,largest);
	cout<<"return "<<endl;
}

void build_heap(int v[],int len ){
	for(int i = (len /2 )  - 1 ; i >= 0 ; i--){
		cout<<"build_heap index "<< i <<endl;
		max_heap(v,i);
	}
}

int main(){
 int v[] = {8,3,9,12,89,34};
// std::vector<int> v ;
// v.pb(8);v.pb(3);v.pb(9);
// v.pb(12);v.pb(34);v.pb(89);
// v.pb(43);v.pb(31);v.pb(30);
//.pb(100);v.pb(90);v.pb(99);

 print_array(v,sizeof(v)/sizeof(v[0]));
 build_heap(v,sizeof(v)/sizeof(v[0]));
 print_array(v,sizeof(v)/sizeof(v[0]));
 return 0 ;
}
