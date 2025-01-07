with open("BOISO.inp","r") as f:
    n=int(f.read())
    f.close()
count=(n//3)+(n//5)-(n//15)
with open ("BOISO.out","w") as f:
    f.write(str(count))
    f.close()