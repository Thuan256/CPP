from math import *
with open("MAXGCD.inp","r") as f:
    a,b=map(int,f.read().split())
    f.close()
if a>b:
    gcd=factorial(b)%(10**9+7)
else:
    gcd=factorial(a)%(10**9+7)
with open("MAXGCD.out","w") as f:
    f.write(str(gcd))
    f.close()