def dao_so(n):
    d=[i for i in str(n)]
    d=d[::-1]
    d=int("".join(map(str,d)))
    return d
def snt(n):
    d=0
    if n<2:
        return False
    elif n==2:
        return True
    else:
        for i in range(2,int(n**0.5)+1):
            if n%i==0:
                d+=1
        if d==0:
            return True
        else:
            return False
def dem(n):
    d=dao_so(n)
    if snt(n) and snt(d):
        return True
with open ("BAI02.inp","r") as f:
    a,b=(map(int,f.read().split()))
    f.close()
count=0
for i in range (a,b+1):
    if dem(i):
        count+=1
with open ("BAI02.out","w") as f:
    f.write(str(count))
    f.close()