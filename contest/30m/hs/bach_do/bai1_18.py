def uoc(n,k):
    d=0
    for i in range(1,n//2+1):
        if n%i==0:
            d+=1
    if d==k:
        return True
    return False
with open("bai1.inp","r") as fi:
    n,k=map(int,fi.readline().split())
    d=0
    for i in range(n):
        if uoc(i,k):
            d+=1
with open("bai1.out","w") as fo:
    fo.write(str(d))
fi.close()
fo.clsoe()