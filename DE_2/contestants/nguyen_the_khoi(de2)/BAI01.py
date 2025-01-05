with open("BAI01.inp","r") as f:
    a,b,n,m=map(int,f.readline().split())
    f.close()
kq=((a**n)%(10**9)+(b**m)%(10**9))
with open("BAI01.out","w") as f:
    f.write(str(kq))
    f.close()