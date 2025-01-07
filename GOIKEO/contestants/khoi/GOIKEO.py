with open("GOIKEO.inp","r") as f:
    n,k=map(int,f.readline().split())
    a=list(map(int,f.readline().split()))
    f.close()
a=sorted(a)
s=0
for i in range (n-k,n):
    s+=a[i]
with open("GOIKEO.out","w") as f:
    f.write(str(s))
    f.close()