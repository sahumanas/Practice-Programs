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
	

	void topologicalSortUtil(int v , bool visited[], stack<int>& st){
		cout<<"topologicalSortUtil "<<endl ;
		visited[v] = true ;
		
		list<int>::iterator i ;
		cout<<"looping "<<endl;
		i = adjmat[v].begin();
		while(i != adjmat[v].end()){
			if(!visited[v])
				topologicalSortUtil(*i,visited,st);
			++i ;
		}
		st.push(v);
		
	}
//	Topological sort
	void topologicalSort(){
		cout<<"topologicalSort"<<endl ;
		stack<int> st ;
		for (int i = 0; i < nodes; i++)
			visited[i] = false;
		
		cout<<"assigned false to vector "<<endl ;
		for(int i  = 0 ; i < nodes; i++){
//			cout<<"looping for node "<<v[i]<<endl ;
			if(visited[i] == false)
				topologicalSortUtil(i,visited,st);
		}
		
		while(st.empty() == false){
			cout<<st.top() ;
			st.pop();
		}
	
	}
	//Traverse the graph from the given node
	void BFSTraversal(int n ){
		for(int i =  0 ; i < nodes ; i++ ){
			visited[i] = false ;
		}

		list<int>::iterator it ;

		list<int> q ;
		q.push_back(n);

		while(!q.empty()){
			int currNode = q.front();
			cout<<currNode<<" " ;
			q.pop_front();
			for(it = adjmat[currNode].begin() ; it != adjmat[currNode].end();it++){
				if(!visited[*(it)]){
					visited[*it] = true ;
					q.push_back(*it);
				}
			}
		}
		cout<<endl ;
	}
	
	//cout<<"DFS Utility function "<<endl;
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
/*	graph g(4);
	cout<<"created .."<<endl;
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	cout<<"BFS from 3 "<<endl;
	g.BFSTraversal(3);
	cout<<endl ;
	cout<<"DFS from 3 "<<endl;
	g.DFSTraversal(3);
	cout<<endl;
	cout<<"Traverse all node of the graph "<<endl;
	g.TraverseAllDFS();
	cout<<endl;
*/
	//Test data for topological sort 
	graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
 
	cout << "Following is a Topological Sort of the given graph \n";
	g.topologicalSort();

	//Check cyclic in directed graph 






 	return 0 ;
}
