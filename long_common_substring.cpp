#include<iostream>

using namespace std ;

void long_common_sring(string s1, string s2){
 int l1 = s1.length();
 int l2 = s2.length();
 int max = 0 ;
 int tab[l1+1][l2+1];
 for( int i = 0 ; i < l1 ; ++i){
  for(int j = 0 ; j < l2 ; ++j){
	if(i == 0 || j == 0 )
		tab[i][j] = 0	;
	else if(s1[i-1] == s2[j-1]){
		tab[i][j] = 1 + tab[i-1][j-1] ;
		if( max < tab[i][j])
			max = tab[i][j];
	}
	else{
		tab[i][j] = 0 ;
	}
  }
 }

cout<<endl <<max<<endl ;
}

int main(){
 string s1 = "abcdaf" ;
 string s2 = "gbcdf";
 long_common_sring(s1,s2);
 return 0 ;
}
