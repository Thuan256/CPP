with open("SUMN.inp","r") as f:
    n=f.read().strip()
    f.close()
s=0
for i in range(len(n)):
    s+=int(n[i])
with open("SUMN.out","w") as f:
    f.write(str(s))
    f.close()