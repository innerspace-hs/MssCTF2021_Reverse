import hashlib
import py_compile
import time
import os
import subprocess
import uuid
for i in range(1,501):
    binaryPath = "../Strange_pyc_" + str(uuid.uuid4())[:8] + ".pyc"
    flagPath = binaryPath + ".flag"
    #生成flag
    timeStamp=str(time.time())
    timeMD5 = str(hashlib.md5(timeStamp.encode()).hexdigest())
    flag = 'mssctf{' + timeMD5 +'}'
    flagFile = open(flagPath,'w+')
    flagFile.write(flag)
    flagFile.close()
    
    #生成enc_flag
    p = subprocess.Popen('python enc.pyc',stdin=subprocess.PIPE,stdout=subprocess.PIPE)
    p.stdin.write(timeMD5.encode())
    en_flag = p.communicate()[0].decode()
    
    #生成binary
    challFile = open('chall.py','r')
    challContent = challFile.read()
    challFile.close()
    challContent = challContent.replace('mssctf{please_set_a_flag}',en_flag)
    destFlie = open('./dest.py','w')
    destFlie.write(challContent)
    destFlie.close()
    py_compile.compile("./dest.py" , cfile=binaryPath)
    print(str(i) + " : finish")