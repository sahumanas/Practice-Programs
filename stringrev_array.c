#include<stdio.h>
#include<stdlib.h>
#include<string.h>	
char *Reversesrting(char *str){
	if(str == NULL)
		return NULL ;
	char *pstart = str ;
	char *pend  = str;
	while(*pend){
		pend++;
	}
	--pend;
	while(pend > pstart){
		char temp = *pstart ;
		*pstart = *pend; 
		*pend = temp ;

		pstart++;
		pend--;
	}
	return str ;

}
int main(){
	char str[] = "ABCD ABCH";
	printf("input string %s\n",str);
	Reversesrting(str);
	printf("output string %s\n",str);
	return 0;
}
