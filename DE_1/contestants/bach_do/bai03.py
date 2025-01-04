with open("bai03.inp","r") as fi:
    k=int(fi.readline())
    n=list(map(int,fi.readline().split()))
    d=0
    for i in n:
        for j in n:
            if i%j==0 and i!=j:
                d+=1
            break
with open("bai03.out","w") as fo:
    fo.write(str(d-1))
fo.close()
fi.close()
