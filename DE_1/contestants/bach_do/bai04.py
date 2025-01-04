with open("bai04.inp","r") as fi:
    n,k=map(int,fi.readline().split())
    a=list(map(int,fi.readline().split()))
    s=[]
with open("bai04.out","w") as fo:
    d=0
    z=0
    while n!=0:
        for i in range(d,d+3):
            s.append(i)
        z+=min(s)
        for i in range(3):
            if min(s)==s[i]:
                n-=i+1
                d+=i+1
            break
        s.clear()
with open("bai04.out","w") as fo:
    fo.write(str(z))
fi.close()
fo.close()