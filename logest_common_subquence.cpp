#include<iostream>
#include<map>

using namespace std ;

void commonSubsequence(string s1 , string s2){

 int l1 = s1.length();
 int l2 = s2.length();
 int tab[l1+1][l2+1]; 

 cout<<endl; 
 cout<<endl ;
 // print the length of the string 
 for(int i = 0 ; i <= l1 ; ++i){
  for(int j = 0 ; j<= l2 ; ++j){

	if (i == 0 || j == 0)
        	tab[i][j] = 0;
 	else if(s1[i-1] == s2[j-1]){
		tab[i][j] = 1 + tab[i-1][j-1] ;
	}
	else{
		tab[i][j] = max(tab[i][j-1],tab[i-1][j]);
	}
  }

 }

  cout <<tab[l1][l2]<<endl ;
  int index = tab[l1][l2] ;
  cout<<endl ;
  char newchar[index+1] ;
  newchar[index] = '\0';
  //print the common sub swquence string 
   int i = l1 ; 
   int j = l2 ;
   while(i > 0 && j > 0 ){
         if(s1[i-1] == s2[j-1]){
                 newchar[index - 1 ] = s1[i-1] ;
		 index-- ; i-- ; j-- ;
	}

	else if(tab[i][j-1] < tab[i-1][j])
		i-- ;
	else
		j--;
	
   }
 

 cout<<newchar ; 
 cout<<endl ; 

}
int main(){
 string s1 = "abcdef";
 string s2 = "acbcf";
 commonSubsequence(s1,s2);
 return 0;
}
