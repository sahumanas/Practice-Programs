#include<iostream>
#include<list>
#include <fstream>
#include <algorithm>
using namespace std ;

//namespace my_namespace{
ostream &operator<<( ostream &output, const list<int> &l ) { 
	list<int>::const_iterator it = l.begin();	
	ofstream out("output.txt");
	while(it != l.end()){
	        output << *it<<endl ;
		out << *it<<endl ;
		out << "\n";
		it++ ;
	}
        return output;            
}
//}
/*
template <typename T>
ostream &operator<<( ostream &strm, const T &val){
        ofstream file("output_anyvalue.txt");
    // save output buffer of the stream
	streambuf* strm_buffer = strm.rdbuf();
    // redirect ouput into the file
	strm.rdbuf (file.rdbuf());
	//file << "one row for the file" << endl;
	strm << "one row for the stream" << endl;
    // restore old output buffer
	strm.rdbuf (strm_buffer);

        return strm ;
}
*/

int main(){
//	cout<< 5 <<endl ;
	//cout<<"hello there " <<endl ;

	list<int> ll ;
	ll.push_back(5);
	ll.push_back(10);
	ll.push_back(15);
	ll.push_back(25);
	ll.push_back(35);
	bool found = (find(begin(ll), end(ll), 15) != end(ll) ) ? true : false ;
	cout<< found <<endl ;
//	if(res != end(ll)) cout<< *res ;
	cout<<endl ;
	cout<<ll ;
	return 0 ;

}

