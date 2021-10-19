import time

print("[Strange_pyc] Welcome to mssctf2021.")
magic = [75, 77, 72, 75, 28, 24, 28, 75, 24, 75, 26, 28, 26, 78, 70, 74, 70, 70, 70, 31, 27, 29, 76, 71, 26, 72, 73, 70, 78, 79, 73, 24]

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