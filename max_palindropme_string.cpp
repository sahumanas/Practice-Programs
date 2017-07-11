#include<iostream>

using namespace std ;

void printMaxPalindrome(string& srtingToBeParsed , int& l ){

 int tab[l][l] ;
 int maxLen = 1 ;
 int start = 0 ;
//Filling for first level 
 for(int i = 0 ; i < l ; ++i)
	tab[i][i] = true ;

 // string for length 2 
 for(int i = 0 ; i < l-1 ; ++i){
	if(srtingToBeParsed[i] == srtingToBeParsed[i + 1]){
		tab[i][i] = true ;
		maxLen = 2 ;
		start = i ;
	}
 }

 // string for length more than len 2 

 for(int k = 3 ; k <= l ; ++k){

  for(int i = 0 ; i < l - k + 1 ; ++i  ){
	
	int j =  i + k - 1 ;
  
	if(tab[i+1][j-1] && srtingToBeParsed[i] == srtingToBeParsed[j]){

		tab[i][j] = true ;
		if(k > maxLen){
			maxLen = k ;		
			start = i ;
		}
	}
  }
 }

 for(int i = start ; i <= start + maxLen - 1 ; ++ i )
	cout<<srtingToBeParsed[i];

cout<<endl ;
	

}
int main(){
 string str = "foofooxyz";
 int len = str.length();
 printMaxPalindrome(str,len);
 return 0 ;
}
