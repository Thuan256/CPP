with open("SUBSTR.inp","r") as f:
    k=int(f.readline())
    a=f.readline().strip()
    f.close()
count=0
for i in range (len(a)):
    for j in range(i+1,len(a)+1):
        mang=a[i:j]
        if mang.count('1')==k:
            count+=1
with open("SUBSTR.out","w") as f:
    f.write(str(count))
    f.close()