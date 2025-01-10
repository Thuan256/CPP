def nt(n):
    if n<2:
        return False
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return False
    return True
sang_nt=[i for i in range(10^7) if nt(i)]
def ba_uoc(r,l):
    count=0
    dau=int(r**0.5)
    cuoi=int(l**0.5)
    for i in range(dau,cuoi+1):
        if i in sang_nt:
            if r<=i*i<=l:
                count+=1
    return count
with open("NUMBER.inp","r") as f:
    l,r=map(int,f.readline().split())
    f.close()
with open("NUMBER.out","w") as f:
    f.write(str(ba_uoc(l,r)))
    f.close()