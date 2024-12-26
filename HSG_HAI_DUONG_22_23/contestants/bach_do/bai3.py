with open("bai3.inp","r") as fi:
    n,m=map(int,fi.readline().split())
    s=list(map(int,fi.readline().split()))
    d=0
    for i in range (m):
        if s[0]>=s[len(s)-1]:
            d+=s[0]
            s.remove(s[0])
        elif s[0]<=s[len(s)-1]:
            d+=s[len(s)-1]
            s.remove(s[len(s)-1])
with open("bai3.out","w") as fo:
    fo.write(str(d))
fi.close()
fo.close()