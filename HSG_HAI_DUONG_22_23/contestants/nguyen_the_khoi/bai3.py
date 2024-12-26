with open ("bai3.inp","r") as f:
    n,m=map(int,f.readline().split())
    a=list(map(int,f.readline().split()))
    f.close()
n-=1
s=0
i=0
for j in range (m):
    if a[i]>=a[n]:
        s+=a[i]
        a.pop(i)
    else :
        s+=a[n]
        a.pop(n)
    n-=1
with open ("bai3.out","w") as f:
    f.write(str(s))
    f.close()