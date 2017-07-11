#include <string>
#include <bitset>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int number_needed(string a, string b) {
  
	std::map<char, int> chars; 
	std::map<char, int>::iterator itr;  
	for (int i = 0 ; i < a.length() ; i++ ) 
		++chars[a[i]];

	cout<<"After traversing first string "<<endl;

        itr = chars.begin();
        while(itr != chars.end()){
		cout<<itr->first<<"--- ### "<<itr->second <<endl;
                ++itr ;
        }

	for (int i = 0 ; i < b.length() ; i++ )
		--chars[b[i]]; 

	cout<<"After traversing second string "<<endl;

        itr = chars.begin();
        while(itr != chars.end()){
                cout<<itr->first<<"--- ### "<<itr->second <<endl;
                ++itr ;
        }

//	cout<<"Traversing finished "<<endl;

//        itr = chars.begin();
//        while(itr != chars.end()){
//                cout<<itr->first<<"--- ### "<<itr->second <<endl;
//                ++itr ;
//        }

	cout<<"Calculation begins "<<endl;

	int needed = 0; 

	itr = chars.begin();
	while(itr != chars.end()){
		needed = needed + abs(itr->second);
		++itr ;
	}
		
    return needed;  
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
