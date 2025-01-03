with open("bset.inp","r") as fi:
    a=list(map(int,fi.readline().split()))
    b=list(map(int,fi.readline().split()))
with open("bset.out","w") as fo:
    x=list(set(a) & set(b))
    y=list(set(a) | set(b))
    for i in y:
        fo.write(str(i)+" ")
    fo.write(""+"\n")
    for i in x:
        fo.write(str(i)+" ")
fi.close()
fo.close()