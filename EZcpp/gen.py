import hashlib
import time
import os
import uuid
for i in range(1, 501):
    binaryPath = "../EZcpp_" + str(uuid.uuid4())[:8] + ".exe"
    flagPath = binaryPath + ".flag"
    # 生成flag
    timeStamp = str(time.time())
    timeMD5 = str(hashlib.md5(timeStamp.encode()).hexdigest())
    flag = 'mssctf{' + timeMD5 + '}'
    flagFile = open(flagPath, 'w+')
    flagFile.write(flag)
    flagFile.close()

    # 生成enc_flag
    timeMD5 = list(timeMD5)
    en_flag = ''
    for x in range(len(timeMD5)):
        xx = hex((ord(timeMD5[x]) ^ (x + x)) + 18)
        en_flag += xx
    en_flag = en_flag.replace('0x', '\\x')

    # 生成binary
    challFile = open('chall.cpp', 'r')
    challContent = challFile.read()
    challFile.close()
    challContent = challContent.replace('mssctf{please_set_a_flag}', en_flag)
    destFlie = open('dest.cpp', 'w')
    destFlie.write(challContent)
    destFlie.close()
    commandLine = 'g++ dest.cpp -o ' + binaryPath
    print("start compile " + str(i))
    print('commandline : ' + commandLine)
    os.system(commandLine)
    commandLine = "strip ./" + binaryPath
    print('commandline : ' + commandLine)
    os.system(commandLine)
    print("finish")