with open("bai01.inp","r") as fi:
    n=int(fi.readline())
with open("bai01.out","w") as fo:
    s=0
    d=0
    x=n
    while x!=0:
        d+=x%10
        x//=10
    for i in range(1,d//2+1):
        if d==i**2:
            s+=1
            fo.write(str(d))
        break
    if s==0:
        fo.write(str(d%11))
fi.close()
fo.close()
