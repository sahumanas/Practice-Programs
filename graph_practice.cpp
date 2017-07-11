#include<iostream>
#include<map>
#include<string>
#include<set>
#include<vector>
#include<list>
using namespace std ;
struct vertex ;
typedef map<string,bool> visited ;
typedef pair<int,vertex*> vpair ; // cost of vertex , dest vertex
typedef map<string,vertex*> vmap ; // source string , dest vertex
struct vertex{
        vector<vpair> adj ;
        string v ;
        vertex(string s): v(s){ }
};

struct Edge{
	string src ;
	string dest ;
};

typedef multimap<int,Edge*> edgePair ;

struct subset
{
    set<string> parent;
    int rank;
};

typedef vector<subset*> vSet ;

class graph{
        bool isDirected ;
        public :
        graph(bool flag):isDirected(flag){ 
	}
        vmap workingVertex ;
        void addVertex(const string&);
        void addEdge(const string& from , const string& dest , int cos);
        int getNodeCount(){ return workingVertex.size() ; }
        vmap allVertex(){ return workingVertex ; }
        vector<vpair> getAdjacent(const string& source);
	edgePair edg ;
	void printEdges();
	vSet allSet ;
	void makeSet(string& val ) ;
	bool find(string &findme);
	void Union(string& lead1,string& lead2) ;
	subset *unionset(subset *x , subset *y);
};

vector<vpair> graph::getAdjacent(const string& src){
        vmap::iterator it = workingVertex.find(src) ;
        if(it !=  workingVertex.end()){
                vertex *f = (workingVertex.find(src)->second) ;
                return f->adj ;
        }
        cout<<"not found" <<endl ;
}

void graph::addVertex(const string& src){
        vmap::iterator it = workingVertex.find(src) ;
        if( it == workingVertex.end()){
                cout<<src <<endl ;
                vertex *v = new vertex(src) ;
                workingVertex[src] = v ;
                return ;
        }
        cout<<"Alread exists"<<endl ;
}

void graph::addEdge(const string& from, const string& to, int cos){
        vertex *f = (workingVertex.find(from)->second) ;
        vertex *t = (workingVertex.find(to)->second) ;
        pair<int,vertex*> edge = make_pair(cos,t);
        f->adj.push_back(edge);

	//For Krushkal algo
	Edge *ed = new Edge() ;
	ed->src = f->v ;
	ed->dest = t->v ;
	pair<int,Edge*> edpair = make_pair(cos,ed);
	edg.insert(pair<int,Edge*>(cos,ed)) ; //[cos] = ed ; //(edpair);

	//For directed graph adding the same edge for the other end 	
        if(!isDirected){
                pair<int,vertex*> edge = make_pair(cos,f);
                t->adj.push_back(edge);
        }
}

void graph::printEdges(){
	cout<<endl ;
	edgePair::iterator it = edg.begin();
	while(it != edg.end()){
		cout<< (*it).first<<"---"<<" src "<<((*it).second)->src << " des " << (*(it)->second).dest ;
		cout<<endl ;
		it++ ;
	}
}

void graph::makeSet(string &val){
	subset *s = new subset();	
	(s->parent).insert(val) ;
	s->rank = 0 ;
	allSet.push_back(s);
}

/*
 
 struct subset
 {   
     set<string> parent;
     int rank;
 };
 
 typedef vector<subset*> vSet ;
 

*/
string graph::find(string& name){
	string res = NULL ;
	//vector<subset*> vSet	
	vSet::iterator it = allSet.begin();
	while(it != allSet.end()){// for each set 
		set<string> sString = (*it)->parent ;
		set<string>::iterator it1 = sString.begin() ; //Inside each set 
		while(it1 != sString.end()){
			cout<<*it1 <<" ";
			if(*it1 == name){
				cout<<"found "<<endl ;
				return sString ;
			}
			it1++ ;	
		}
	it++ ;
	cout<<endl ;
	}

	return res ;
}

subset *graph::unionset(subset *x , subset *y){
	set<string> xRoot = x->parent ;
	set<string> yRoot = y->parent ;
	xRoot.insert(yRoot.begin(), yRoot.end());
	return x;	
} 

int main(){
 graph g(false) ;//connected --- undirected-- weighted
 g.addVertex("A") ;
 g.addVertex("B") ;
 g.addVertex("C") ;
 g.addVertex("D") ;
 g.addVertex("D") ;
 g.addVertex("E") ;
 g.addVertex("F") ;
 g.addVertex("G") ;
 g.addEdge("A","B",5);
 g.addEdge("C","A",6);
 g.addEdge("C","B",7);
 g.addEdge("A","D",10);
 g.addEdge("C","F",8);
 g.addEdge("C","E",2);
 g.addEdge("B","E",5);
 g.addEdge("D","F",2);
 g.addEdge("C","G",2);
 cout<<"Total node count " <<g.getNodeCount()<<endl ;
 for(auto res : g.getAdjacent("A"))
        cout << res.first <<" ---- > "<< (res.second)->v<<endl  ;
 cout<<"========================================================="<<endl ;
 for(auto res : g.getAdjacent("C"))
        cout << res.first <<" ---- > "<< (res.second)->v<<endl  ;
// cout<<"=========================DFS=========================="<<endl ;
// string src = "A" ;
 g.printEdges();
 cout<<endl ;
 for(auto vmapeach : g.allVertex()){
 	string st = vmapeach.first  ;
	g.makeSet(st);
 }

 int e = 0; //initialise edge to index 0 

// while (e < (g.getNodeCount() - 1) )
 {
//	pair<int,Edge*> ed_next = edg[i++] ; 
//	cout<<(g.edg[cos].second)->src <<endl ;
// }
//Edge* ptr = {string src , src }
 // typedef multimap<int,Edge*> edgePair ;
/*
18 struct Edge{
 19         string src ;
 20         string dest ;
 21 };
*/
 edgePair resultMap ; 
 edgePair::iterator mapitr;
 for(mapitr= edg.begin();mapitr!= edg.end() && e!=((g.getNodeCount() - 1) ) ;i++)
 {
        string x=find((*mapitr)->src);
        string y=find((*mapitr)->dest);
        if(x!=y)
        {
            result[e++]=*i;
		resultMap.insert(make_pair());	
            Union(x,y);
        }
 }




 string s = "A" ;
 g.find(s);
// g.unionset();
  return 0 ;
}
