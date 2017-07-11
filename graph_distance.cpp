#include<iostream>
#include<map>

using namespace std ;

class Delivery{
 struct path{
 int u ;
 int v ;
 };
 map<int,path > info ;

 public : 
 void addPoints(int truckNum , int src , int des);
 int checkPossibility(int );
};

void Delivery::addPoints(int truckNum , int src , int des){
	struct path way ;
	way.u = src;
	way.v = des;
	info.insert(make_pair(truckNum,way));	
}

int Delivery::checkPossibility(int M){
	int count = 0;
	for(int i = 1 ; i <= M ; i++){
		map<int,path >::iterator it = info.find(i);
		if(((it->second).u == 1)  && ((it->second).v == 5)) count += 1 ;
		if((it->second).u > (it->second).v) continue ; 
	}
	return count ;
}

int main(){
 Delivery d;
 int M ; int U ; int V ;
 cout<<"enter number of trucks"<<endl;
 cin>>M ;
 for(int i = 1 ; i <= M ; i++){
	cin >> U ;
	cin >> V ;
	d.addPoints(i ,U ,V ) ;
 }
 cout<<endl<<endl  ;
 cout<<d.checkPossibility(M)<<endl ;;
 return 0 ;
}
