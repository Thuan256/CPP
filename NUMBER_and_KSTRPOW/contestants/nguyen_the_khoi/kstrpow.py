with open ("kstrpow.inp","r") as f:
    s=f.readline().strip()
    t=f.readline().strip()
    k=int(f.readline())
    f.close()
a=len(s)
b=len(t)
with open ("kstrpow.out","w") as f:
    if a*k==b:
        f.write("YES")
    else:
        f.write("NO")
    f.close()