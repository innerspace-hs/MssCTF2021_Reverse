en_flag = "\x74\x42\x46\x49\x51\x4C\x4E\x51\x38\x33\x89\x84\x8F\x34\x3D\x8C\x24\x28\x27\x57\x2C\x30\x30\x2C\x18\x19\x68\x16\x6E\x1D\x21\x6E"
flag = ""
for i in range(32):
    flag += chr((ord(en_flag[i])-18)^(i*2))
print(flag)