with open("SNTO.inp","r")as f:
    n=int(f.readline())
    a=list(map(int,f.readline().split()))
    f.close()
def sang_nt(n):
    mang_nt=[True]*(n+1)
    mang_nt[0]=mang_nt[1]==False
    for p in range(2,int(n**0.5)):
        if mang_nt[p]==True:
            for i in range (p*p,n+1,p):
                mang_nt[i]=False
    nt=[i for i in range(2,n+1) if mang_nt[i]]
    return nt
nt=sang_nt(10**6)
b=[i for i in a if i>0 and i in nt]
c=list(set(b))
c=c[::-1]
with open("SNTO.out","w") as f:
    if len(b)>0:
        f.write(str(len(b))+"\n")
        f.write(str(c[0]))
    else:
        f.write(str(0)+"\n")
        f.write(str(0))
    f.close()