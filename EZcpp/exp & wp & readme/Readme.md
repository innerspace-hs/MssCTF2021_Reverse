# EZcpp

## Category

reverse

## Difficulty

ez（2）

## key words

- ida交叉引用
- 初步c++逆向

## Description

美妙的命名空间以及c++逆向

## Hint

- 当你有东西找不到时，为什么不试试神奇的交叉引用呢

## Environment

c++

## WP

本体难点主要在于c++逆向中，string类型的全局变量初始化使用的时basic_string方法,并且初始化函数并不在main函数中，需要使用交叉引用来寻找被加密的flag在哪里。

另一个难点就是ida识别出来的c++代码比较难以阅读，需要识别出at、==等方法。

```python
en_flag = "\x77\x4D\x49\x44\x4B\x44\x4C\x4B\x34\x85\x88\x38\x3C\x8B\x8B\x3D\x27\x22\x29\x59\x5C\x2B\x26\x2F\x17\x19\x67\x66\x1B\x1F\x17\x6F"
flag = ""
for i in range(32):
    flag += chr((ord(en_flag[i])-18)^(i*2))
print(flag)
```

