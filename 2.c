#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, c, d;
    int *pa, *pb, *pc, *pd;

    pa = &a;
    pb = &b;
    pc = &c;
    pd = &d;

    *pa = 3;
    printf("%d %d", *pa, a);
    
    return 0;
}