with open("bai4.inp","r") as fi:
    n=int(fi.readline())
    d=0
    for x in range(1,n+1):
        for y in range(x+1,n+1):
            for z in range(y+1,n+1):
                if x+y+z==n:
                    d+=1
with open("bai4.inp","w") as fo:
    fo.write(str(d))
fi.close()
fo.close()