#include <stdio.h>

int main(){
    int var1 = 10;
    long int var2;
    int var3;

    unsigned long int addr1 = (unsigned long int)(&var1);
    unsigned long int addr2 = (unsigned long int)(&var2);
    unsigned long int addr3 = (unsigned long int)(&var3);

    printf("%p, %p, %p\n", &var1, &var2, &var3);
    printf("%ld, %ld, %ld\n", addr1, addr2, addr3);
    printf("%ld, %ld, %ld\n", addr1-addr3, addr2-addr3, addr3-addr3);

    return 0;
}