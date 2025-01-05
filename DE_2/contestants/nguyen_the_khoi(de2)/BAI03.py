with open("BAI03.inp", "r") as f:
    d,n = map(int, f.readline().split())
    a = list(map(int, f.readline().split()))
    f.close()
s=0
count=0
dem={0:1}
for i in a:
    s+=i
    mod=s%d
    if mod<0:
        mod+=d
    if mod in dem:
        count+=dem[mod]
    if mod in dem:
        dem[mod]+=1
    else:
        dem[mod]=1
with open("BAI03.out","w") as f:
    f.write(str(count))
    f.close()