#include<iostream>
#include<list>
#include<queue>

#define pb push_back
using namespace std ;
class graph{
	int nodes ;
	list<int>* adjmat ;
	bool *visited ; 	
   public :
	graph(int n ){
		nodes = n ;
		adjmat = new list<int>[n];
		visited = new bool[n];
	}
	
	void addEdge(int u , int v){
		adjmat[u].pb(v);
	}

	void DFSUtil(int v ,bool visited[] ){
		visited[v] = true ;
		cout<< v << " " ;
		list<int>::iterator it = adjmat[v].begin();
		while(it != adjmat[v].end()){
		if(!visited[*it])	
			DFSUtil(*it,visited) ;
		it++;
		}
		
	}
	//Traverse the node from the given node 
	void DFSTraversal(int n ){
		for(int i = 0 ; i < nodes ; i++)
			visited[i] = false ;
		
		DFSUtil(n,visited);
	}

	//Traverse all node 
	void TraverseAllDFS(){
                for(int i = 0 ; i < nodes ; i++)
                        visited[i] = false ;		
                for(int i = 0 ; i < nodes ; i++){
			if(visited[i] == false )
	                        DFSUtil(i,visited);
		}
	}
};

int main(){
	graph g(7);
	cout<<"created .."<<endl;
	g.addEdge(1,3);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(2,5);
	g.addEdge(4,6);
	g.addEdge(5,6);
	g.addEdge(6,7);
	cout<<endl ;
	cout<<"DFS from 3 "<<endl;
	g.DFSTraversal(6);
	cout<<endl;
	cout<<"Traverse all node of the graph "<<endl;
	g.TraverseAllDFS();
	cout<<endl;
}
