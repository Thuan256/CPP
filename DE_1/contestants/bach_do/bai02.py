def ngto(n):
    d=0
    for i in range(1,n//2+1):
        if n%i==0:
            d+=1
    if d!=1:
        return False
    return True
def nto(n):
    a=0
    a+=n
    a=str(a)
    a=int(a[::-1])
    if ngto(n) and ngto(a):
        return True
    return False
with open("bai02.inp","r") as fi:
    n,m=map(int,fi.readline().split())
with open("bai02.out","w") as fo:
    a=[]
    for i in range(n,m+1):
        if nto(i):
            a.append(i)
    fo.write(str(len(a)))