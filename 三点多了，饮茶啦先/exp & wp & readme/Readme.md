# 三点多了，饮茶啦先

## Category

reverse

## Difficulty

ez（2）

## key words

- TEA加密
- upx壳的去除
- 数据类型的识别
- 某些ida宏定义的识别

## Description

三点多了，饮茶啦先，做那么多也是拿不到flag的，出题人不会心疼你的

## Hint

- 茶在ctf的逆向中代表什么呢？

## Environment

c语言

## WP

简单的TEA加密，只不过把key和delta替换了

```python
#include <stdio.h>
int main()
{
    unsigned char en_flag[100] = "\x7A\xE8\xD9\x07\x59\x2B\x30\x92\x54\x3A\x62\xB6\x6D\x99\x83\x41\x7E\x65\x01\xA4\xFE\x4A\x47\x8B\x91\x23\x3D\xCD\x8D\xF0\xCB\x4A";
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
```

