import math
with open("COINLK.inp","r") as f:
    with open("COINLK.out","w") as fo:
        t=int(f.readline())
        for i in range(t):
            n=0
            s=0
            p=f.readline().strip()
            for i in p:
                if i=='N':
                    n+=1
                elif i=="S":
                    s+=1
            gcd=math.gcd(s,n)
            s//=gcd
            n//=gcd    
            fo.write(f"{s}/{n}"+"\n")
f.close()
fo.close()