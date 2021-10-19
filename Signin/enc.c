#include <stdio.h>
//flag = "9f11ac015339d4aa609ee664a01fcf04";
int main()
{
    unsigned char a[100] = "9f11ac015339d4aa609ee664a01fcf04";
    for (int i=0;i<32;i++){
        a[i] ^= (i + 4)*2;
    }
    for (int j=0;j<32;j++){
        printf("\\x%02x",a[j]);
    }
    return 0;
}