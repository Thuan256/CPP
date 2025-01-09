import math 
with open ("FROG.inp","r") as f:
     n=int(f.readline())
     k=int(f.readline())
     f.close()
with open("FROG.out","w") as f:
    f.write(str(math.gcd(n,k)))
    f.close()