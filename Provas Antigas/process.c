#include <stdio.h>

typedef union {
    float f;
    unsigned int i;
} U;

float process(float v)
{
    U u;
    unsigned int s, e, f;

    u.f = v;
    s = getsig(u.i);
    e = getexp(u.i);
    f = getfrac(u.i);

    f = f | (e << 13);
    u.i = makefloat(s, e, f);

    return u.f;
}

int main(){
    float resultado = process(2.5);
    printf("%.2lf", &resultado);
}
