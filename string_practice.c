#include<stdio.h>
#include<stdlib.h>

void reverse_char(char** to){
	printf("\n");
	printf("\n");
	printf("\n");
	printf("to-----%p\n",to);
	printf("to-----%p\n",*to);
	char *begin = *to ;
	char *end = *to ;
	while(*end){
		end++ ;
	}
	
	--end; 
	printf("%c\n\n\n",*begin);
	while(begin > end){
		char temp = *begin ;
		*begin++ = *end ; 	
		*end-- = temp ;
	}
//begin = '\0';
//        printf("%c\n\n\n",*begin);
	--begin ; 
        printf("%c\n\n\n",*begin);
	--begin ; 
        printf("%c\n\n\n",*begin);
}
int main(){
	char* from = malloc(50);
	from = "here i m" ; 
	printf("%s\n",from);
	printf("%p\n",from);
	printf("%p\n",&from);
	reverse_char(&from);
	printf("%s",from);
	return 0 ;
}
