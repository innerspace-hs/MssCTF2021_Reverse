import time
print("[Strange_pyc] Welcome to mssctf2021.")
magic = [75, 74, 76, 72, 75, 72, 28, 70, 31, 79, 72, 28, 72, 71, 73, 26, 31, 70, 72, 73, 79, 70, 72, 72, 76, 77, 26, 73, 27, 77, 74, 27]
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