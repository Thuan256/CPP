with open("BAI03.inp","r") as f:
    n=int(f.readline())
    a=list(map(int,f.readline().split()))
    f.close()
def dem(a,n):
    count=0
    b=[]
    for i in range(n-1):
        for j in range(i+1,n):
            tb_cong=(a[i]+a[j])/2
            if tb_cong.is_integer() and int(tb_cong) in a:
                 b.append(tb_cong)
            c=set(b)
    return len(c)
with open("BAI03.out","w") as f:
    f.write(str(dem(a,n)))
    f.close()