"""
Subtask 1 (30%): n, m <= 20
Subtask 2 (30%): n, m <= 70
Subtask 3 (40%): n, m <= 5000
"""

import os
import random
import subprocess

for numTest in range(1, 41):
    # Change num to string
    test_id = str(numTest)
    if len(test_id) < 2:
        test_id = '0' + test_id
    
    # Mkdir Test + numTest
    if not os.path.exists('Test' + test_id):
        os.makedirs('Test' + test_id)

    # Write input
    with open('Test' + test_id + '/beautipair.inp', 'w') as f:
        if numTest <= 12:
            n = random.randint(10, 20)
            m = random.randint(10, 20)
        elif numTest <= 24:
            n = random.randint(50, 70)
            m = random.randint(50, 70)
        else:
            n = random.randint(4000, 5000)
            m = random.randint(4000, 5000)
        
        f.write(str(n) + ' ' + str(m) + '\n')

        charList = []
        sz = random.randint(3, 10)
        for i in range(sz):
            charList.append(chr(random.randint(97, 122)))

        for i in range(n):
            f.write(charList[random.randint(0, sz - 1)])

        f.write('\n')

        for i in range(m):
            f.write(charList[random.randint(0, sz - 1)])
        f.write('\n')
    
    os.chdir('/home/flash/FinalContest/beautypair')
    proc = subprocess.run(['./beautypair'], stdin=open('Test' + test_id + '/beautipair.inp', 'r'), stdout=open('Test' + test_id + '/beautipair.out', 'w'))