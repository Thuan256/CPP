with open ("DGROUP.inp","r") as f:
    n,m,k=map(int,f.read().split())
    f.close()
n=n/2
if n>=m:
    team=m
    du=(n-m)*2
else:
    team=n
    du=m-n
tong=team*3-k+du
s=tong//3
with open ("DGROUP.out","w") as f:
    f.write(str(int(s)))
    f.close()