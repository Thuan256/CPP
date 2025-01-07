with open("SQUARE.inp","r") as f:
    n=f.read().strip()
    f.close()
s=0
for i in range(len(n)):
    s+=(int(n[i]))**2
with open("SQUARE.out","w") as f:
    f.write(str(s))
    f.close()