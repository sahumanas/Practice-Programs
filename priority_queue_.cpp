#include<iostream>
#include<vector>
#include <cstdlib>
using namespace std ;

#define pb push_back
struct MaxHeap{
	MaxHeap(){
		v.pb(0);
	}

	void print_array(){ 
         for(int i = 0 ; i < v.size() ; ++i ){
                cout<<v[i]<<" ";
         }
 	 cout<<endl ;
	}

	void max_heap(int index){
		cout<<"max_heap called with index " <<index <<endl;
		cout<<"max_heap v at index "<<v[index ]<<endl;
		int largest = index ;
	
        	if(((index << 1 ) < v.size()) && (v[index << 1] > v[largest])){
                         largest = index << 1 ;
                         cout<<"now left is largest ---change" <<endl;
	        }

		if(((index << 1) + 1   < v.size()) && (v[(index << 1) + 1 ] > v[largest])){
			largest = ( index << 1 ) + 1  ;
			cout<<"now right is largest ---change" <<endl;
		}
	
		cout<<"largest is "<<largest <<endl ; 
		if(largest != index){
			cout<<"before swap "<<v[index] << " largest "<<v[largest] <<endl ;
			std::swap(v[index], v[largest]);
			cout<<"after swap "<<v[index] << " largest "<<v[largest] <<endl;
			max_heap(largest);
		}
		cout<<endl ;
	}

	void build_heap(){
		for(int i = (v.size() /2 ) ; i > 0 ; i--){
			cout<<"build_heap index "<< i <<endl;
			max_heap(i);
		}
	}
	void add(){
		v.pb(8);v.pb(3);v.pb(9);
		v.pb(12);v.pb(89);v.pb(34);
		print_array();
		build_heap();
		print_array();
	}
	bool isEmpty(){
		return v.size() > 1 ? false : true ;
	}
	int top(){
		return v[1];
	}
	void pop(){
		if(v.size() == 1 )
			return ;
		std::swap(v[1], v[v.size() - 1]);
		v.pop_back();
		int index = 1 ;
		while(index < v.size()){
			int largest = index ;
			if(((index << 1 ) < v.size()) && (v[index << 1] > v[largest])){
				largest = index << 1 ;
			}
			if(((index << 1) + 1   < v.size()) && (v[(index << 1) + 1 ] > v[largest])){
				largest = ( index << 1 ) + 1  ;
			}
			if(largest != index){
				std::swap(v[index], v[largest]);
				index = largest;
			}
			else
				break ;
		}
	}
        private :
		vector<int> v ;
  
};
int main(){
 MaxHeap h ;
 h.add();
 while(!h.isEmpty()){
	cout<<h.top()<<" "<<endl;
	h.pop();
 }
 return 0 ;
}
