with open("ext.inp","r") as fi:
    k=int(fi.readline())
    n=list(map(int,fi.readline().split()))
    d=0
    for i in range(1,len(n)-1):
        if (n[i]>n[i-1] and n[i]>n[i+1]) or (n[i]<n[i-1] and n[i]<n[i+1]):
            d+=1
with open("ext.out","w") as fo:
    fo.write(str(d))
fi.close()
fo.close()