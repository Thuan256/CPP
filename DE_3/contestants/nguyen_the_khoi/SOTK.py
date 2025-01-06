with open("SOTK.inp","r") as f:
    n,k=map(int,f.readline().split())
    a=list(map(int,f.readline().split()))
    f.close()
a=list(sorted(set(a)))
a=a[::-1]
with open("SOTK.out","w") as f:
    f.write(str(a[k-1]))