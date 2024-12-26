with open ("bai4.inp","r") as f:
    n=int(f.readline())
    f.close()
count=0
for z in range(n+1):
    for y in range(z):
        for x in range(y):
            if 1<=x<y<z<=n and x+y+z==n:
                count+=1
with open ("bai4.out","w") as f:
    f.write(str(count))
    f.close()