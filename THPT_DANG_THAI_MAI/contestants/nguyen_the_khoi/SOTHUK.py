def cat_mang(a,b):
    return [x for x in a if x not in b]

with open("SOTHUK.inp","r") as f:
    with open("SOTHUK.out","w") as fo:
        t=int(f.readline())
        for i in range (t):
            n,m,k=map(int,f.readline().split())
            b=list(map(int,f.readline().split()))
            a=[i for i in range(1,n+1)]
            c=cat_mang(a,b)
            k-=1
            fo.write(str(c[k])+"\n")
    f.close()
    fo.close()