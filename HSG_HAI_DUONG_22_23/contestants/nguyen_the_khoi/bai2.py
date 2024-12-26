with open ("bai2.inp","r") as f:
    n=int(f.readline())
    a=f.readline()
    f.close()
s=0
count=0
for i in a:
    if i=='1':
        count+=1
        s+=count
    else:
        count=0
with open ("bai2.out","w") as f:
    f.write(str(s))
    f.close()