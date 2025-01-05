with open("BAI02.inp","r") as f:
    n=int(f.readline())
    a=list(map(int,f.readline().split()))
    f.close()
def nt(n):
    d=0
    if n<2:
        return False
    if n==2:
        return True
    if n%2==0:
        return False
    for i in range(3,int(n**0.5)+1):
        if n%i==0:
            return False
    return True
def bac_thang(n):
    n = str(n)
    if len(n)<=1:
        return False
    for i in range(len(n) - 1):
        if n[i] >= n[i + 1]:
            return False
    return True
count=sum(1 for i in a if nt(i)==True and bac_thang(i)==True)
with open("BAI02.out","w") as f:
    f.write(str(count))
    f.close()