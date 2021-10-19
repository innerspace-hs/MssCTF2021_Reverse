#include <stdio.h>
int main()
{
    unsigned char en_flag[100] = "\x81\x6B\xB5\xEE\x92\x7D\x90\xE1\xC6\xE5\xCC\x48\x33\xBA\xCC\x72\x45\xC2\xDC\x0A\xFA\x7B\xA6\x50\x49\x4D\xAD\x69\x0B\xC7\xDE\xF6";
    unsigned int flag[8] = {0};
    for (int i = 0; i < 4; i++)
    {
        unsigned int var1 = *((unsigned int *)&en_flag[i*8]);
        unsigned int var2 = *((unsigned int *)&en_flag[i*8] + 1);
        unsigned int key[4] = {114, 514, 1919, 810};
        unsigned int delta = 0xdeadbeef;
        unsigned int sum = 0xd5b7dde0;
        for (int j = 0; j < 32; j++)
        {
            var2 -= (sum + var1) ^ (key[2] + 16 * var1) ^ ((var1 >> 5) + key[3]);
            var1 -= (sum + var2) ^ (key[0] + 16 * var2) ^ ((var2 >> 5) + key[1]);
            sum -= delta;
        }
        flag[2 * i] = var1;
        flag[2 * i + 1] = var2;
    }
    char buf[100]={0};
    for(int i=0;i<32;i++){
        buf[i] = *((char *)flag + i);
    }
    puts(buf);
}