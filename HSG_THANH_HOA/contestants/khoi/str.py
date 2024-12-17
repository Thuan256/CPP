with open ("str.inp","r") as f :
    s=f.read()
    f.close()
a=list(set([char for char in s if char.islower()]))
with open ("str.out","w") as f:
    f.write(str(len(a)))
    f.close()