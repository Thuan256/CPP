def fibo(n):
    f0=0
    f1=1
    if n==0:
        return 0
    elif n==1:
        return 1
    for i in range(n+1):
        f0,f1=f1,f0+f1
    return f1-1
with open ("TongNF.inp","r") as f:
    n=int(f.readline())
    a=list(map(int,f.readline().split()))
    f.close()
with open("TongNF.out","w") as f:
    fi=" ".join(str(fibo(i))for i in a)
    f.write(fi)
    f.close()