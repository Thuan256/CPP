with open ("sohoc.inp","r") as f:
    n=int(f.read())
    f.close()
def dem_uoc(n):
    count=0
    for i in range(1,n+1):
        if n%i==0:
            count+=1
    return count
def ngt(n):
    d=0
    if n<2:
        return False
    elif n==2:
        return True
    else:
        for i in range(2,n//2+1):
            if n%i==0:
                d+=1
        if d==0:
            return True
        else :
            return False
a=[]
for i in range(1,n+1):
    if n%i==0:
        a.append(i)
a=a[::-1]
with open ("sohoc.out","w") as f:
    f.write(str(dem_uoc(n))+"\n")
    for i in(a):
        if ngt(i)==True:
            f.write(str(i))
            break
    f.close()