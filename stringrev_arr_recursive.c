#include<stdio.h>
#include<stdlib.h>
#include<string.h>	
void Reversesrting(char *str){
	if(*str == '\0')
		return ;
	else{
		Reversesrting(str +1);
		printf("%c",*str) ;
	}

}
int main(){
	char str[] = "ABCD ABCH";
	printf("\n\ninput string %s\n",str);
	Reversesrting(str);
	return 0;
}
