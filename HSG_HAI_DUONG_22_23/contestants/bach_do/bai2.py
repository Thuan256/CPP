with open ("bai2.inp","r") as fi:
    n=int(fi.readline())
    s=str(fi.readline())
    a=0
    b=0
    if s[0]==str(0):
        a=0        
    elif s[0]==str(1):
        a+=1
        b+=a
    for i in range(1,n):
        if s[i]==str(1):
            a+=1
            b+=a
        elif s[i]==str(0):
            a-=a
with open("bai2.out","w") as fo:
    fo.write(str(b))
fi.close()
fo.close()