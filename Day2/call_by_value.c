#include <stdio.h>
void func(int n){
    n = 20;
    printf("%p\n", &n);
}

int main(){
    int n = 10;
    func(n);
    printf("%d\n", n);
    printf("%p\n", &n);
    
    return 0;
}