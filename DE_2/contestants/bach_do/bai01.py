with open("bai01.inp","r") as fi:
    a,b,n,m=map(int,fi.readline().split())
with open("bai01.out","w") as fo:
    x=a**n
    y=b**m
    z=x+y
    fo.write(str(z))
fi.close()
fo.close()