#include <stdio.h>
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
    unsigned char input[100]={0};
    scanf("%s",input);
    tea_encrypt(input);
    for(int i=0;i<32;i++){
        printf("\\x%02x",input[i]);
    }
}