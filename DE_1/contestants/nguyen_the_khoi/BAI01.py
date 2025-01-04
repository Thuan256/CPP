def scp(n):
    p=int(n**0.5)
    if p**2==n:
        return True
def tong(n):
    s=0
    while n>0:
        s+=n%10
        n//=10
    return s
with open("BAI01.inp","r") as f:
    n=int(f.readline())
    f.close()
s=tong(n)
print(n)
print(str(s))
with open ("BAI01.out","w") as f:
    if(scp(s)):
        f.write(str(s))
    else:
        f.write(str(s%11))
    f.close()