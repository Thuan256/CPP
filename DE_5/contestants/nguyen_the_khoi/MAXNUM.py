import itertools
with open("MAXNUM.inp","r") as f:
    x=f.read().strip()
    f.close()
n=len(x)
m=[int(''.join(p)) for p in itertools.permutations(x) if len(p) == n and int(''.join(p)) < int(x)]
if len(m)==0:
    m.append(0)
with open("MAXNUM.out","w") as f:
    f.write(str(max(m)))
    f.close()