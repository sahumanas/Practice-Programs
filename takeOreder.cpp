#include<iostream>
#include<map>
using namespace std ;

class Store{
 private :
 struct list{
  int m_pen_count ;
  int m_pencil_count ;
  int m_eraser_count ; 
 };
 public : 
  map<int,list> m_order_list ;
  void buy(int,int,int,int);
  void get();
};

void Store::get(){
	int iPenCount = 0 ;int iPencilCount = 0, iEraserCount = 0 ;
	map<int,list>::iterator it = m_order_list.begin();
	while(it != m_order_list.end()){
		cout<<"Order"<<it->first<<"-->";
		if((it->second).m_pen_count){
			cout<<"Pen "<<(it->second).m_pen_count <<" "; 
			iPenCount = iPenCount + (it->second).m_pen_count ;
		}
		if((it->second).m_pencil_count){
			cout<<"Pencil "<<(it->second).m_pencil_count <<" " ;
			iPencilCount += (it->second).m_pencil_count ;
		}
		if((it->second).m_eraser_count){		
			cout<<"Eraser "<<(it->second).m_eraser_count <<" ";
			iEraserCount += (it->second).m_eraser_count ;
		}
		++it ; 
		cout<<endl ;
	}

	cout<<"Total Pen " << iPenCount <<endl ;
	cout<<"Total Pencil " << iPencilCount <<endl ;
	cout<<"Total Eraser " << iEraserCount <<endl ;
}
void Store::buy(int order , int pen , int pencil , int eraser){
	struct list ll ;
	ll.m_pen_count = pen ;
	ll.m_pencil_count = pencil ;
	ll.m_eraser_count = eraser ;
	m_order_list.insert(make_pair(order,ll));
}
int main(){
 int Q ;
 int i = 1 ; 
 int pen , pencil , eraser ;
 cin >> Q ; 
 Store s; 
 while(i <= Q){ 
	cout<<"pen"<<endl ;
	cin>>pen ;
	cout<<"pencil"<<endl ;
	cin>>pencil ;
	cout<<"eraser"<<endl;
	cin>>eraser ;
	s.buy(i,pen , pencil , eraser);
	++i ;
 }
 
 s.get();

 return 0 ;
}
