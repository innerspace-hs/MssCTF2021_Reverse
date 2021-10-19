import dis,marshal
f=open("Strange_pyc_7f66cf52.pyc","rb").read()

code = marshal.loads(f[16:])

dis.dis(code)