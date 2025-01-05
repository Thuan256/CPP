def ngto(n):
    d=0
    for i in range(1,n//2+1):
        if n%i==0:
            d+=i
    if d!=1:
        return False
    return True
with open("bai02.inp","r") as fi:
    k=int(fi.readline())
    n=list(map(int,fi.readline().split()))
    s=[]
    for i in range(k):
        d=0
        while n[i] != 0:
            d+=1
            n//=10
        s.append(d)
with open("bai02.out") as fo:
    fo.write(d)
    
    