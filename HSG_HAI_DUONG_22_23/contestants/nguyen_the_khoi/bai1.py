from math import *
with open ("bai1.inp","r") as f:
    a=int(f.readline())
    A=float(f.readline())
    h=int(f.readline())
A=radians(A)
s=h+tan(A)*a
s=round(s,4)
with open ("bai1.out","w") as f:
    f.write(f"{s:.3f}")
    f.close()