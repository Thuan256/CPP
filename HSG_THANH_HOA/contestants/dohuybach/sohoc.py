def ngto(n):
    d=0
    for i in range(1,n//2+1):
        if n%i==0:
            d+=i
    if d!=1:
        return False
    return True
with open("sohoc.inp","r") as fi:
    n=int(fi.read())
    a=[n]
    s=[]
    for i in range(1,n//2+1):
        if n%i==0:
            a.append(i)
            if ngto(i):
                s.append(i)
    j=len(a)
    if j==2:
        s.append(n)
    k=max(s)
with open("sohoc.out","w") as fo:
    fo.write(str(j)+"\n")
    fo.write(str(k))
fi.close()
fo.close()