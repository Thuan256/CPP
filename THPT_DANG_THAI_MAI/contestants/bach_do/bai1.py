def ngto(n):
    d=0
    for i in range(1,n//2+1):
        if n%i==0:
            d+=i
    if d!=1:
        return False
    return True
with open("bai1.inp","r") as fi:
    n=list(map(int,fi.readline().split()))
    n=n[::-1]
with open("bai1.out","w") as fo:
    for i in range(1,len(n)-1):
        if ngto(n[i-1]) and ngto(n[i+1]):
            fo.write(str(len(n)-i))
            break
fi.close()
fo.close()