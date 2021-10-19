# Signin

## Category

reverse

## Difficulty

white give(1)

## key words

- C语言逆向
- 小端序数字转字符串
- 简单异或加密

## Description

热心的含树学长来送flag啦，大家快来签到吧

## Hint

- 你知道大小端序吗

## Environment

C语言

## WP

本题中比较坑的一点就是，ida将en_flag识别成了4个long long的数字，因此在ida中看到的en_flag是小端序形式存储的。

有两种方法能得到字符串形式的en_flag，一种是动态调试查看hex表，另一种是手动将小端序转化，两种方法都不是很难。

exp如下

```python
en_flag = "\x31\x6C\x3D\x3F\x71\x71\x24\x27\x2D\x29\x2F\x27\x44\x16\x45\x47\x1E\x1A\x15\x4B\x55\x04\x02\x02\x59\x0A\x0D\x58\x23\x24\x74\x72"
flag = ""
print(len(en_flag))
for i in range(32):
    flag += chr(ord(en_flag[i])^(2*(i+4)))
print(flag)	
```

