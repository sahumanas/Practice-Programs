#include<iostream>
#include<list>
#include<queue>
#include<stack>
#define pb push_back
using namespace std ;
class graph{
	int nodes ;
	list<int>* adjmat ;
	bool *visited ; 	// uncomment it for dfs-- bfs --topological sort 
   public :
	graph(int n ){
		nodes = n ;
		adjmat = new list<int>[n];
		visited = new bool[n];
	}
	
	void addEdge(int u , int v){
		adjmat[u].pb(v);
	}
	

	bool isCyclicUtil(int v ,bool visited[] , bool recStack[]){
		if(recStack[v] == false){
			visited[v] = true ;
			recStack[v] = true ;
			list<int>::iterator it = adjmat[v].begin();
			while(it != adjmat[v].end()){
				if(!visited[*it] && isCyclicUtil(*it, visited, recStack))	
					return true ;
				else if(recStack[*it])
					return true;
				it++;
			}
		}
		recStack[v] = false ;
		return false ;
	}
	//Traverse the node from the given node 
	bool isCyclic(){
		bool *visited = new bool[nodes];
		bool *recStack = new bool[nodes];
		for(int i = 0 ; i < nodes ; i++){
			visited[i] = false ;
			recStack[i] = false ;
		}
                for(int i = 0 ; i < nodes ; i++){
			if(isCyclicUtil(i,visited,recStack))
				return true ;
                 }
		return false ;
	}

};

int main(){
    // Create a graph given in the above diagram
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    if(g.isCyclic())
        cout << "Graph contains cycle"<<endl;
    else
        cout << "Graph doesn't contain cycle"<<endl;
    return 0;
}
