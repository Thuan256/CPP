with open ("DIVISION.inp","r") as f:
    with open("DIVISION.out","w") as o:
        t=int(f.readline())
        for i in range(t):
             x,l=map(int,f.readline().split())
             a=f.readline()
             count=0
             for i in range(len(a)-l+1):
                 so = int(a[i:i+l])
                 if so%x==0 and so >= 10 ** (l - 1):
                     count+=1
             o.write(str(count)+"\n")
        o.close()
    f.close()