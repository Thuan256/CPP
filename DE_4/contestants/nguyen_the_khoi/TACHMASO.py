import re
with open("TACHMASO.inp","r") as f:
    s=f.read().strip()
    f.close()
con=re.findall(r'\d+',s)
sort=sorted(con,key=int)
with open("TACHMASO.out","w") as f:
    for i in sort:
        f.write(i+" ")
        f.close