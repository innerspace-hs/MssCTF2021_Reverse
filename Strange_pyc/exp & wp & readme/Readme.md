# Strange_pyc

## Category

reverse

## Difficulty

mid(3)

## key words

- python字节码

## Description

人生苦短，我学python

python版本为python3.9.1

## Hint

- dis和marshal是两个好东西
- https://docs.python.org/zh-cn/3/library/dis.html

## Environment

python3.9.1

## WP

首先使用marshal获取字节码

```python
import dis,marshal
f=open("Strange_pyc.pyc","rb").read()

code = marshal.loads(f[16:])

dis.dis(code)
```

字节码如下

```python
1           0 LOAD_CONST               0 (0)
              2 LOAD_CONST               1 (None)
              4 IMPORT_NAME              0 (time)
              6 STORE_NAME               0 (time)

  3           8 LOAD_NAME                1 (print)
             10 LOAD_CONST               2 ('[Strange_pyc] Welcome to mssctf2021.')
             12 CALL_FUNCTION            1
             14 POP_TOP

  4          16 BUILD_LIST               0
             18 LOAD_CONST               3 ((75, 74, 76, 72, 75, 72, 28, 70, 31, 79, 72, 28, 72, 71, 73, 26, 31, 70, 72, 73, 79, 70, 72, 72, 76, 77, 26, 73, 27, 77, 74, 27))
             20 LIST_EXTEND              1
             22 STORE_NAME               2 (magic)

  7          24 LOAD_NAME                3 (input)
             26 LOAD_CONST               4 ('please input your password : ')
             28 CALL_FUNCTION            1
             30 STORE_NAME               4 (hanser)

  8          32 LOAD_NAME                5 (list)
             34 LOAD_NAME                4 (hanser)
             36 CALL_FUNCTION            1
             38 STORE_NAME               6 (ipt)

  9          40 LOAD_NAME                7 (len)
             42 LOAD_NAME                6 (ipt)
             44 CALL_FUNCTION            1
             46 LOAD_NAME                7 (len)
             48 LOAD_NAME                2 (magic)
             50 CALL_FUNCTION            1
             52 COMPARE_OP               3 (!=)
             54 POP_JUMP_IF_FALSE       82

 10          56 LOAD_NAME                1 (print)
             58 LOAD_CONST               5 ('QwQ , you are wrong . Try again ! ')
             60 CALL_FUNCTION            1
             62 POP_TOP

 11          64 LOAD_NAME                0 (time)
             66 LOAD_METHOD              8 (sleep)
             68 LOAD_CONST               6 (114514)
             70 CALL_METHOD              1
             72 POP_TOP

 12          74 LOAD_NAME                9 (exit)
             76 LOAD_CONST               6 (114514)
             78 CALL_FUNCTION            1
             80 POP_TOP

 13     >>   82 LOAD_NAME               10 (range)
             84 LOAD_NAME                7 (len)
             86 LOAD_NAME                6 (ipt)
             88 CALL_FUNCTION            1
             90 LOAD_CONST               7 (2)
             92 BINARY_FLOOR_DIVIDE
             94 CALL_FUNCTION            1
             96 GET_ITER
        >>   98 FOR_ITER                54 (to 154)
            100 STORE_NAME              11 (i)

 14         102 LOAD_NAME                6 (ipt)
            104 LOAD_NAME               11 (i)
            106 LOAD_CONST               7 (2)
            108 BINARY_MULTIPLY
            110 LOAD_CONST               8 (1)
            112 BINARY_ADD
            114 BINARY_SUBSCR
            116 LOAD_NAME                6 (ipt)
            118 LOAD_NAME               11 (i)
            120 LOAD_CONST               7 (2)
            122 BINARY_MULTIPLY
            124 BINARY_SUBSCR
            126 ROT_TWO
            128 LOAD_NAME                6 (ipt)
            130 LOAD_NAME               11 (i)
            132 LOAD_CONST               7 (2)
            134 BINARY_MULTIPLY
            136 STORE_SUBSCR
            138 LOAD_NAME                6 (ipt)
            140 LOAD_NAME               11 (i)
            142 LOAD_CONST               7 (2)
            144 BINARY_MULTIPLY
            146 LOAD_CONST               8 (1)
            148 BINARY_ADD
            150 STORE_SUBSCR
            152 JUMP_ABSOLUTE           98

 15     >>  154 LOAD_NAME               10 (range)
            156 LOAD_NAME                7 (len)
            158 LOAD_NAME                6 (ipt)
            160 CALL_FUNCTION            1
            162 CALL_FUNCTION            1
            164 GET_ITER
        >>  166 FOR_ITER                24 (to 192)
            168 STORE_NAME              11 (i)

 16         170 LOAD_NAME               12 (ord)
            172 LOAD_NAME                6 (ipt)
            174 LOAD_NAME               11 (i)
            176 BINARY_SUBSCR
            178 CALL_FUNCTION            1
            180 LOAD_CONST               9 (126)
            182 BINARY_XOR
            184 LOAD_NAME                6 (ipt)
            186 LOAD_NAME               11 (i)
            188 STORE_SUBSCR
            190 JUMP_ABSOLUTE          166

 17     >>  192 LOAD_NAME               10 (range)
            194 LOAD_NAME                7 (len)
            196 LOAD_NAME                6 (ipt)
            198 CALL_FUNCTION            1
            200 CALL_FUNCTION            1
            202 GET_ITER
        >>  204 FOR_ITER                46 (to 252)
            206 STORE_NAME              11 (i)

 18         208 LOAD_NAME                6 (ipt)
            210 LOAD_NAME               11 (i)
            212 BINARY_SUBSCR
            214 LOAD_NAME                2 (magic)
            216 LOAD_NAME               11 (i)
            218 BINARY_SUBSCR
            220 COMPARE_OP               3 (!=)
            222 POP_JUMP_IF_FALSE      204

 19         224 LOAD_NAME                1 (print)
            226 LOAD_CONST               5 ('QwQ , you are wrong . Try again ! ')
            228 CALL_FUNCTION            1
            230 POP_TOP

 20         232 LOAD_NAME                0 (time)
            234 LOAD_METHOD              8 (sleep)
            236 LOAD_CONST               6 (114514)
            238 CALL_METHOD              1
            240 POP_TOP

 21         242 LOAD_NAME                9 (exit)
            244 LOAD_CONST               6 (114514)
            246 CALL_FUNCTION            1
            248 POP_TOP
            250 JUMP_ABSOLUTE          204

 22     >>  252 LOAD_NAME                1 (print)
            254 LOAD_CONST              10 ('Congratulations!!!')
            256 CALL_FUNCTION            1
            258 POP_TOP

 23         260 LOAD_NAME                1 (print)
            262 LOAD_CONST              11 ('Here is your flag : mssctf{')
            264 LOAD_NAME                4 (hanser)
            266 BINARY_ADD
            268 LOAD_CONST              12 ('}')
            270 BINARY_ADD
            272 CALL_FUNCTION            1
            274 POP_TOP

 24         276 LOAD_NAME                0 (time)
            278 LOAD_METHOD              8 (sleep)
            280 LOAD_CONST               6 (114514)
            282 CALL_METHOD              1
            284 POP_TOP
            286 LOAD_CONST               1 (None)
            288 RETURN_VALUE
```

翻译字节码得到python源代码

```python
print("[Strange_pyc] Welcome to mssctf2021.")
magic = [75, 74, 76, 72, 75, 72, 28, 70, 31, 79, 72, 28, 72, 71, 73, 26, 31, 70, 72, 73, 79, 70, 72, 72, 76, 77, 26, 73, 27, 77, 74, 27]
hanser = input("please input your password : ")
input = list(hanser)
if len(input) != len(magic):
    print("QwQ , you are wrong . Try again ! ")
    exit(114514)
for i in range(len(input)//2):
    input[i], input[i+1] = input[i+1], input[i]
for i in range(len(input)):
    input[i] = ord(input[i]) ^ 126
for i in range(len(input)):
    if input[i] != magic[i]:
        print("QwQ , you are wrong . Try again ! ")
        exit(114514)
print("Congratulations!!!")
print("Here is your flag : " + "mssctf{" + hanser + "}")
```

写脚本解密

```python
ipt = [75, 74, 76, 72, 75, 72, 28, 70, 31, 79, 72, 28, 72, 71, 73, 26, 31, 70, 72, 73, 79, 70, 72, 72, 76, 77, 26, 73, 27, 77, 74, 27]
for i in range(len(ipt)):
    ipt[i] ^= 126
for i in range(len(ipt)//2):
    ipt[i*2], ipt[i*2+1] = ipt[i*2+1], ipt[i*2]
for i in range(len(ipt)):
    print(chr(ipt[i]),end="")
```

