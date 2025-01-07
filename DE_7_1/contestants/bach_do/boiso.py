with open("boiso.inp","r") as fi:
    n=int(fi.readline())
with open("boiso.out","w") as fo:
    s=n//3+n//5-n//15
    fo.write(str(s))
fi.close()
fo.close()
