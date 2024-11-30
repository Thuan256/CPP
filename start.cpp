#include <fstream>
#include <iostream>
using namespace std;

int main() {

    cout << stoi("1");

    ofstream outfile("input.txt");
    for (int i = 1; i <= 1000; ++i) {
        outfile << i << " ";
    }
    outfile.close();
    return 0;
}
