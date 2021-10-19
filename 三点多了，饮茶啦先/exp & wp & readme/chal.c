#include <stdio.h>
#include <windows.h>
unsigned char en_flag[100] = "\x7a\xe8\xd9\x07\x59\x2b\x30\x92\x54\x3a\x62\xb6\x6d\x99\x83\x41\x7e\x65\x01\xa4\xfe\x4a\x47\x8b\x91\x23\x3d\xcd\x8d\xf0\xcb\x4a";
unsigned int sum = 0;
unsigned int delta = 0xdeadbeef;
unsigned int key[4] = {114, 514, 1919, 810};
//flag : mssctf{0d0cf01ef10ebcaca7ad3d4b2c1bfd65}
void tea_encrypt(char *input)
{
    unsigned long long M[4];
    M[0] = *((unsigned long long *)input);
    M[1] = *((unsigned long long *)(input + 8));
    M[2] = *((unsigned long long *)(input + 16));
    M[3] = *((unsigned long long *)(input + 24));
    for (int j = 0; j < 4; j++)
    {
        sum = 0;
        for (int i = 0; i < 32; i++)
        {
            unsigned int var1 = *((unsigned int *)&(M[j]));
            unsigned int var2 = *((unsigned int *)&(M[j]) + 1);
            sum += delta;
            var1 += ((var2 << 4) + key[0]) ^ (var2 + sum) ^ ((var2 >> 5) + key[1]);
            var2 += ((var1 << 4) + key[2]) ^ (var1 + sum) ^ ((var1 >> 5) + key[3]);
            *((unsigned int *)&(M[j])) = var1;
            *((unsigned int *)&(M[j]) + 1) = var2;
        }
    }
    for (int i = 0; i < 32; i++)
    {
        input[i] = *((char *)M + i);
    }
}
int main()
{
    unsigned char input[100] = {0};
    unsigned char tmp[100] = {0};
    printf("[三点多了，饮茶啦先] welcome to mssctf2021. Please input your flag and I will check it.\n");
    printf("input:");
    scanf("%s", input);
    memcpy(tmp, input, 100);
    tea_encrypt(tmp);
    for (int i = 0; i < 32; i++)
    {
        if (tmp[i] != en_flag[i])
        {
            printf("WRONG!!!!!");
            Sleep(0xdeadbeef);
        }
    }
    printf("Congratulations");
    printf("Here is your flag : mssctf{%s}", input);
    Sleep(0xdeadbeef);
}