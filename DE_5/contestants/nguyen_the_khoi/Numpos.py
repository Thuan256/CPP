with open ("Numpos.inp","r") as f:
    n=int(f.read())
    f.close()
if n==1:
    n=1
elif n==2:
    n=2
elif n==3:
    n=3
else:
    n=(n-2)*3
with open ("Numpos.out","w") as f:
    f.write(str(n))
    f.close()