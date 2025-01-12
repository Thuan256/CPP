# Subtask 1 (10%): s = 1; g = 0
# Subtask 2 (20%): s = 1; sum_g <= 1000
# Subtask 3 (10%): g = 0
# Subtask 4 (20%): sum_g <= 1000
# Subtask 5 (40%): n, m <= 5 * 10^5; g, s <= n

import os
import random
import subprocess

for numTest in range(31, 51):
    # Mkdir Test
    test_id = str(numTest).zfill(2)
    
    if not os.path.exists("Test" + test_id):
        os.makedirs("Test" + test_id)
    
    # Gen input
    with open("Test" + test_id + "/aws.inp", "w") as f:
        if numTest <= 5:
            n = random.randint(50000, 100000)
            s = 1
            g = 0
            m = random.randint(50000, 100000)
        elif numTest <= 15:
            n = random.randint(50000, 100000)
            s = 1
            g = random.randint(1, 500)
            m = random.randint(50000, 100000)
        elif numTest <= 20:
            n = random.randint(50000, 100000)
            s = random.randint(1, 1000)
            g = 0
            m = random.randint(50000, 100000)
        elif numTest <= 30:
            n = random.randint(50000, 100000)
            s = random.randint(1, 1000)
            g = random.randint(1, 500)
            m = random.randint(50000, 100000)
        else:
            n = random.randint(50000, 100000)
            s = random.randint(1, 500)
            g = random.randint(1, 100)
            m = random.randint(50000, 100000)
        
        if g > 0:
            g_list = []
            sum_g = 0

            for i in range(g):
                g_list.append(2)
                sum_g += 2
            
            max_g = random.randint(500, 1000)
            if numTest > 30:
                max_g = random.randint(10000, n)

            while sum_g < max_g:
                id = random.randint(0, g - 1)
                g_list[id] += 1
                sum_g += 1
        
        f.write(str(n) + " " + str(s) + " " + str(g) + " " + str(m) + "\n")
        
        # Element in server must be unique
        servers = []
        for i in range(s):
            server = random.randint(1, n)
            while server in servers:
                server = random.randint(1, n)
            servers.append(server)
        
        for i in range(s):
            f.write(str(servers[i]) + " ")
        f.write("\n")

        for i in range(g):
            groups = []
            for j in range(g_list[i]):
                group = random.randint(1, n)
                while group in groups:
                    group = random.randint(1, n)
                groups.append(group)
            
            f.write(str(g_list[i]) + " ")
            for j in range(g_list[i]):
                f.write(str(groups[j]) + " ")
            
            val = random.randint(1, 1000000000)
            f.write(str(val) + "\n")
        
        for i in range(m):
            u = random.randint(1, n)
            v = random.randint(1, n)
            while u == v:
                v = random.randint(1, n)
            
            val = random.randint(1, 1000000000)
            f.write(str(u) + " " + str(v) + " " + str(val) + "\n")
        
        q = random.randint(1, 100000)
        f.write(str(q) + "\n")

        for i in range(q):
            id = random.randint(1, n)
            f.write(str(id) + "\n")

        f.close()

    # Gen output
    os.chdir("/home/flash/FinalContest/aws")
    proc = subprocess.run(["./aws"], stdin=open("Test" + test_id + "/aws.inp", "r"), stdout=open("Test" + test_id + "/aws.out", "w"))