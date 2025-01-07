with open("BDSO.inp","r") as f:
    n=int(f.read())
    f.close()
count=0
while n!=1:
    if n%2==0:
        n//=2
        count+=1
    elif n%2==1:
        n=n*3+1
        count+=1
with open("BDSO.out","w") as f:
    f.write(str(count))
    f.close()