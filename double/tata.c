#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
int main() {
    double d = DBL_MIN / 2;

    typedef union {
        unsigned long long sign : 1;
        unsigned long long exp : 11;
        unsigned long long fract : 52;
    } double64u;
    double64u di;
    static_assert(sizeof(double) == sizeof(double64u), "");
    memcpy(&di, &d, sizeof(double));

    // extract **binary** digits from value into buffer
    char buffer[53] = {0};
    char *p = buffer + 52;
    unsigned long long tmp = di.fract;
    printf("tmp = %llu\n", tmp);
    for (int i = 0; i < 52; ++i) {
        *(--p) = (tmp & 0x1) + '0';
        tmp >>= 1;
    }

    char sign = di.sign < 0 ? -1 : 1;
    
    bool normal = di.exp != 0;

    printf("%g = \n", d);
    if (normal) {
        printf("%d * 2^(%d - 1023) * 1.%s(2)\n",
            sign, di.exp, buffer);
    } else {
        printf("%d * 2^(1 - 1023) * 0.%s(2)\n",
            sign, buffer);
    }
}
