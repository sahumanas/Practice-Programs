#include<stdio.h>
#include<stdlib.h>
#include<string.h>	
char *Reversesrting(char *str){
	if(str == NULL)
		return NULL;
	else{
		printf("\n\ninput string in Reverse string %s\n",str);	
		printf("\n\ninput string in Reverse string size %lu\n",strlen(str));	
		char *start = str ;
		char *end = str ;
		while(*end){
			end++;
		}
		--end;
		while(end > start){
			char temp = *end ;
			*end = *start ;
			*start = temp ;

			end-- ;
			start++ ;
		}
		return str ;
	}

}
int main(){
//	char *str = (char*)malloc( 50 * sizeof(char) ); //malloc allocated ptr
//	strcpy( str, "ABCD ABCH");
	char str[50] = "ABCD ABCH";// reversing char array 
	printf("\n\ninput string %s\n",str);
	Reversesrting(str);
	printf("\n\noutput string %s\n",str);
	return 0;
}
