#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }
    tokens.push_back(str.substr(start));

    return tokens;
}

int main() {
    string str = "A B C D E F";

    vector<string> splited = split(str, ' ');

    for (const auto& word : splited) {
        cout << word << endl;
    }
}