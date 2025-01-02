with open ("BSET.inp","r") as f:
    n,m=map(int,f.readline().split())
    a=list(map(int,f.readline().split()))
    b=list(map(int,f.readline().split()))
    f.close()
count=0
d=list(a)
for i in range(m):
    d.append(b[i])
d=list(set(d))
c=[i for i in a if i in b]
with open("BSET.out","w") as f:
    f.write(str(len(d))+" "+str(len(c)))
    f.close()