#include <stdio.h>
#include <windows.h>
unsigned char en_flag[100] = "\x88\xf1\x03\x67\x7f\x61\xff\x29\x63\xfe\x49\x8a\x27\x21\x64\xd7\xe7\xf6\x2a\xb6\x6f\x45\x51\xe6\xc3\x84\x71\x33\x97\x1f\x85\x1b";
unsigned int sum = 0;
unsigned int delta = 0xdeadbeef;
unsigned int key[4] = {114, 514, 1919, 810};
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