with open("dgroup.inp") as fi:
    n,m,k=map(int,fi.readline().split()) 
    a=0 
with open("dgroup.out") as fo:
    if n//2 > m:
        a+=m
        k-=(n//2-m+n%2)
    elif n//2 < m:
        a+=n//2
        k-=(m-n//2+n%2)
    elif n//2==m:
        a+=m
    if k<=0:
        fo.write(str(a))
    elif k>0:
        while k>0:
            a-=1
            k-=6
        fo.write(str(a))
fi.write()
fo.close()       