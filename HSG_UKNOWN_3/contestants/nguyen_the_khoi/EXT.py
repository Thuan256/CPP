with open("EXT.inp","r") as f:
    n=int(f.readline())
    a=list(map(int,f.readline().split()))
    f.close()
count=0
for i in range(1,len(a)-1):
    if (a[i]>a[i-1] and a[i]>a[i+1]) or (a[i]<a[i-1] and a[i]<a[i+1]):
        count+=1
with open("EXT.out","w") as f:
    f.write(str(count))
    f.close()