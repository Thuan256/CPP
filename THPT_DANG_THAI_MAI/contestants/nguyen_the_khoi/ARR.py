with open ("ARR.inp","r") as f:
    n=int(f.readline())
    a=list(map(int,f.readline().split()))
    f.close()
def tia_mang(a):
    mang=set()
    kq=[]
    for i in a:
        if i not in mang:
            mang.add(i)
            kq.append(i)
    return kq
with open ("ARR.out","w") as f:
    kq=tia_mang(a)
    f.write(" ".join(map(str,kq)))
    f.close()