#include <stdio.h>
#include <string.h>

struct Z {
    int size;
    short *ptr;
    char str[8];
};

union W {
    struct Z z;
    short *s;
};

void dump(void *addr, int n) {
    unsigned char *p = (unsigned char*)addr;
    while (n--) { printf("%p - %02x\n", p, *p); p++;}
}

union W w;

int main() {
    w.s = (short*)&w;

    strcpy(w.z.str, "FLUTUAR");
    w.z.ptr = (short*)w.z.str;

    w.s[4] = w.z.ptr[3];
    w.z.size = 0x60;

    *w.z.ptr = w.z.ptr[1] | w.s[2];

    dump(&w, sizeof(w));

    return 0;
}
