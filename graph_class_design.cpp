#include<iostream>
#include<vector>
#include<map>
#include<list>
using namespace std ;

class Edge ;
//class Vertex ;


class Vertex{
  private :
  int Vid ;
  int Vdata ;
  int size ;
  vector<Edge*> edge;
  vector<Vertex> adjecentVertexes;
  public :
  Vertex(){
  }
  Vertex(int id){
         Vid = id ;
  }
  int getVertexId(){
         return Vid ;
  }
  void setData(int data){
         Vdata = data ;
  }
  void addAdjecentVertex(Edge* e1 , Vertex v){
	cout<<"m in adjeacent "<<endl ;
        this->edge.push_back(e1);
        this->adjecentVertexes.push_back(v);
	for(int i = 0 ; i < adjecentVertexes.size() ; i++)
		cout<<adjecentVertexes[i].Vid<<" ";

	cout<<endl ;
  }
//  void getAllVertex(){
//	for(int i = 0 ; i < allVertex.size() ; i++)
//		cout<<allVertex[i] <<" ";
//  }
};

class Edge{
  int Eid;
  bool isDirected ;
  Vertex v1 ;
  Vertex v2 ;
  int weight ;
  public :
  Edge(Vertex v1 , Vertex v2 ){
         v1 = v1 ;
         v2 = v2 ;
         isDirected = false ;
  }
 
 Edge(Vertex v1 , Vertex v2 , bool isDirected , int weight){
         v1 = v1 ;
         v2 = v2 ;
         weight = weight ;
         isDirected = isDirected ;
  }
  Edge(Vertex v1 , Vertex v2 , bool isDirected){
         v1 = v1 ;
         v2 = v2 ;
         isDirected = isDirected ;
  }
  Vertex getVertex1(){
         return v1 ;
  }
  Vertex getVertex2(){
         return v2 ;
  }
  Vertex getWeight(){
         return weight ;
  }
  bool isDirectedEdge(){
         return isDirected ;
  }
};


class Graph{

 private : 
 vector<Edge*> allEdges ;
 map<int,Vertex> allVertex ;
 bool isDirected ;
 public : 
 Graph(bool isDirected){
	isDirected = isDirected ;
 }
 void addEdge(int v1 ,int v2 ){
	addEdge(v1,v2,0);
 }
 void addEdge(int v1,int v2, int weight){
	cout<<"addEdge to graph"<<endl ;
	Vertex vertex1 ;
	map<int,Vertex>::iterator it = allVertex.find(v1);
	if(it != allVertex.end()){
		 //Get Id from vertex class
		vertex1 = allVertex[v1];
	}
	else{
		cout<<"Inserting to the graph --v1 "<<endl ;
		allVertex.insert(pair<int,Vertex>(v1,vertex1));	
	}

        Vertex vertex2 ; // = NULL; //new Vertex() ;
        map<int,Vertex>::iterator it1 = allVertex.find(v2);
        if(it1 != allVertex.end()){
                  //get id v1 from vertex class 
		vertex2 = allVertex[v2];
        }
        else{
		cout<<"Inserting to the graph --v2 "<<endl ;
                 allVertex.insert(pair<int,Vertex>(v2,vertex2));
        }
	
	Edge* edge = new Edge(v1,v2,isDirected ,weight);
	allEdges.push_back(edge);
	vertex1.addAdjecentVertex(edge,vertex2);
	//After adding it to the edge
//	cout<<"After adding it to the edge "<<endl ;

//	for(int i  = 0 ; allEdges.size() ;i ++)
//		cout<<allEdges[i]->getVertexId()<<" " ;

//	cout<<endl;

	//	after adding to it to the vertex class
	cout<<"after adding it to v1 the vertex class "<<endl;
        map<int,Vertex>::iterator it3 = allVertex.begin();
        if(it3 != allVertex.end()){
                  cout<<it3->first <<" "<<(it3->second).getVertexId()<<" ";
        }
	cout<<endl ;
//	cout<<"aftering printing all the vertex"<<endl ; 
	//aftering printing all the vertex
	cout<<"Checking directed or not "<<endl;
	if(!isDirected){
		cout<<"not Directed "<<endl;
		cout<<"connecting v2 to v1 "<<endl;
		vertex2.addAdjecentVertex(edge,vertex1) ; //Vertex class ;
	}
 }
 void setDataForVertex(int id, int data){
	map<int,Vertex>::iterator it = allVertex.find(id);
        if(it != allVertex.end()){
                   Vertex v1 = allVertex[id];
		   v1.setData(data);///From vertex class
         }
 }
void getAllVertex(){
	map<int,Vertex>::iterator it = allVertex.begin();
        if(it != allVertex.end()){
                  cout<<it->first <<" "<<(it->second).getVertexId()<<" ";
	}
	cout<<endl ;
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
};
   
int main(){
        Graph graph = new Graph(false);
        graph.addEdge(1, 3);
        graph.addEdge(1, 2);
//       graph.addEdge(3, 4);
//        graph.addEdge(5, 6);
//        graph.addEdge(6, 3);
//        graph.addEdge(3, 8);
//        graph.addEdge(8, 11);
	cout<<"Graph created "<<endl ;
	graph.getAllVertex();
	return 0 ;
        
}
