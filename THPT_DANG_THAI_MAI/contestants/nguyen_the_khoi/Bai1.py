with open ("Bai1.inp","r") as f:
    a=list(map(int,f.readline().split()))
    f.close()
def nt(n):
    d=0
    if n<2:
        return False
    elif n==2:
        return True
    else:
        for i in range(2,int(n**0.5)+1):
            if n%i==0:
                d+=1
        if d==0 :
            return True
        else:
            return False
for i in range(1,len(a)-1):
    if nt(a[i-1])==True and nt(a[i+1])==True:
        so=i
with open ("Bai1.out","w") as f:
    if so>0:
        f.write(str(so+1))
    else:
        f.write(str(so))
    f.close()