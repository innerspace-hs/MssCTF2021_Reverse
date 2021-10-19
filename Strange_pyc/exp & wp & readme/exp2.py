ipt = [75, 74, 76, 72, 75, 72, 28, 70, 31, 79, 72, 28, 72, 71, 73, 26, 31, 70, 72, 73, 79, 70, 72, 72, 76, 77, 26, 73, 27, 77, 74, 27]
for i in range(len(ipt)):
    ipt[i] ^= 126
for i in range(len(ipt)//2):
    ipt[i*2], ipt[i*2+1] = ipt[i*2+1], ipt[i*2]
for i in range(len(ipt)):
    print(chr(ipt[i]),end="")