import time

print("[Strange_pyc] Welcome to mssctf2021.")
magic = mssctf{please_set_a_flag}
hanser = input("please input your password : ")
ipt = list(hanser)
if len(ipt) != len(magic):
    print("QwQ , you are wrong . Try again ! ")
    time.sleep(114514)
    exit(114514)
for i in range(len(ipt)//2):
    ipt[i*2], ipt[i*2+1] = ipt[i*2+1], ipt[i*2]
for i in range(len(ipt)):
    ipt[i] = ord(ipt[i]) ^ 126
for i in range(len(ipt)):
    if ipt[i] != magic[i]:
        print("QwQ , you are wrong . Try again ! ")
        time.sleep(114514)
        exit(114514)
print("Congratulations!!!")
print("Here is your flag : " + "mssctf{" + hanser + "}")
time.sleep(114514)