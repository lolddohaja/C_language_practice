#include <stdio.h>
int main(){
char ch ;
int i ;
i = 'a' ;
printf("%d = %c \n", i, i) ;
ch = 65 ;
printf("%d = %c \n", ch, ch) ;
ch = ch + 1 ;
printf("%d = %c \n", ch, ch) ;

ch++ ;
printf("%d = %c \n", ch, ch) ;
return 0;
}
