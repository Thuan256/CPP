with open("PO.inp","r") as f:
    n,s=map(int,f.readline().split())
    q=int(f.readline())
    a=list(map(int,f.readline().split()))
    f.close()
tong=0
for i in a:
    if i==s:
        tong=i
        break
    elif i<s and s>tong+i:
        tong+=i
with open("PO.out","w") as f:
    f.write(str(tong))
    f.close()
        