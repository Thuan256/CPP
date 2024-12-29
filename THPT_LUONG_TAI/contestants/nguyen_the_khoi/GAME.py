with open ("game.inp","r") as f:
    n=int(f.readline())
    a=list(map(int,f.readline().split()))
    f.close()
    
ans = 0

if (n >= 3):
    s1 = a[0]
    s2 = a[0] + a[1]
    s3 = max(a[0]+a[1], a[1]+a[2], a[0]+a[2])
    
    ans = s3
    
    for i in range(3, n):
        ans = max(s3, s2 + a[i], s1 + a[i - 1] + a[i])
        s1 = s2
        s2 = s3 
        s3 = ans
else:
    ans = sum(a)
    
    
# s=0
# s1=a[1]
# s2=a[1]+a[2]
# s3=max(a[1]+a[2],a[2]+a[3],a[3]+a[1])
# if n==1:
    # s=s1
# elif n==2:
    # s=s2
# elif n==3:
    # s=s3
# elif n>3:
    # for i in range(4,n):
        # s=max(s3,s2+a[i],s1+a[i-1]+a[i])
        # s1=s2
        # s2=s3
        # s3=s
with open ("game.out","w") as f:
    f.write(str(ans))
    f.close()