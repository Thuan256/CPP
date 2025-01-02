with open("tg.inp","r") as fi:
    s=[]
    k=[]
    a,b=map(int,fi.readline().split())
with open("tg.out","w") as fo:
    for i in range(a+((b-a)//2),b):
       s.append(abs((b+i)*(((b-i)+1)//2)-(a+i)*(((i-a)+1)//2)))
       k.append(i)
    for i in range(len(k)):
        if s[i]==min(s):
            fo.write(str(k[i]))
fi.close()
fo.close()