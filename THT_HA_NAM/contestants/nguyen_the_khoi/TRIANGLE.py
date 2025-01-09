with open("TRIANGLE.inp","r") as f:
    n=int(f.readline())
    a={"b":[],"g":[],"r":[]}
    for i in range (n):
        c,l=map(str,f.readline().split())
        l=int(l)
        a[c].append(l)
    f.close()
count=0
for r in a["r"]:
    for b in a["b"]:
        for g in a["g"]:
            canh=sorted([r,b,g])
            if canh[0]+canh[1]>canh[2]:
                count+=1
with open("TRIANGLE.out","w") as f:
    f.write(str(count))
    f.close()