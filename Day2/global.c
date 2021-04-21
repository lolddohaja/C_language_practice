#include <stdio.h>
void Add(int val);
int num; //global variable, 0으로 초기화
int main(){
printf("num: %d\n",num);
Add(3);
printf("num:%d\n", num);
num++;
printf("num:%d\n", num);
return 0;
}
void Add(int val){
num +=val;//전역변수 num에 val만큼 증가
}