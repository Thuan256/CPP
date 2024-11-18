#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ifstream inp("DOREMON.inp");

    string line;
    short n, k;

    getline(inp, line);
    inp.close();

    stringstream ss(line);
    ss >> n;
    ss >> k;
}

/*

x 0 0 0
1
1
1

5 3
10000 x i = 0; d = 5-0-1 = 4 > 3;
01000 o i = 1; d = 5-1-1 = 3 = 3;
00100 o i = 2; 
00010
00001 x


10001
10010
10100
11000

01001
01010
01100

00101
00110

00011


11001
11010
11100

10101
10110

10011

01101
01110

00111

0010
0011
0100
0110
0101
1001
1010
1011
1100
1101

*/
