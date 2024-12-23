with open("kstrpow.inp","r") as fi:
    n=fi.readline().strip()
    m=fi.readline().strip()
    k=int(fi.readline().strip())
with open("kstrpow.out","w") as fo:
    if m*k==n:
        fo.write("YES")
        print("yes")
    elif m*k!=n:
        fo.write("NO")
        print("no")
fi.close()
fo.close()