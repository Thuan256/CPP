def sang_nt(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    return is_prime
def dem(n):
    max_p = 3 * n 
    prime = sang_nt(max_p)
    count = 0
    for p in range(3, max_p + 1):
        if prime[p]:
            for y in range(1, n + 1):
                x = p - 2 * y
                if 1 <= x <= n:
                    count += 1
    return count
with open("BIEUTHUCNT.inp","r") as f:
    n=int(f.read())
    f.close()
with open("BIEUTHUCNT.out","w") as f:
    f.write(str(dem(n)))
    f.close()