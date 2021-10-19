ipt = list(input())
en_flag = ""

for i in range(len(ipt)//2):
    ipt[i*2], ipt[i*2+1] = ipt[i*2+1], ipt[i*2]
for i in range(len(ipt)):
    ipt[i] = ord(ipt[i]) ^ 126

print(ipt)