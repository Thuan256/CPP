with open("arr.inp","r") as fi:
    s=int(fi.readline())
    n=list(map(int,fi.readline().split()))
    k=n
    a=n
    b=n    
    for i in range(len(n)-1):
        for j in (1,i):
            if a[i]==b[j]:
                n.remove(n[j])
with open("arr.out","w") as fo:
    for i in n:
        fo.write(str(i)+" ")
fi.close()
fo.close()