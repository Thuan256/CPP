#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const string INPUT_FILE = "CANDY.INP";
const string OUTPUT_FILE = "CANDY.OUT";

int N;                         // Số lượng phần tử
vector<int> a;                 // Mảng chứa các giá trị
vector<int> x;                 // Tập chứa trạng thái của các phần tử (1 hoặc 2)
int S[3];                      // Tổng của tập 1 và tập 2
int Delta;                     // Chênh lệch tổng giữa hai tập

// Đọc dữ liệu từ file
void ReadInput() {
    ifstream fi(INPUT_FILE);
    int value;
    while (fi >> value) {
        a.push_back(value);
    }
    N = a.size();
    fi.close();
}

// Khởi tạo ban đầu: tất cả phần tử vào tập 1
void Initialize() {
    x.assign(N, 1);  // Gán tất cả phần tử vào tập 1
    S[1] = S[2] = 0;
    for (int i = 0; i < N; ++i) {
        S[1] += a[i];
    }
    Delta = S[1];  // Chênh lệch ban đầu = tổng tập 1
}

// Chuyển phần tử k từ tập i sang tập (3 - i)
void Move(int i, int k) {
    int value = a[k];
    x[k] = 3 - i;            // Đổi tập của phần tử k
    S[i] -= value;           // Giảm tổng tập i
    S[3 - i] += value;       // Tăng tổng tập còn lại
    Delta = abs(S[1] - S[2]);
}

// Tìm phần tử tốt nhất từ tập i để chuyển sang tập còn lại
bool FindAndMoveSingle() {
    for (int i = 1; i <= 2; ++i) {
        for (int k = 0; k < N; ++k) {
            if (x[k] == i) {
                int newDelta = abs((S[i] - a[k]) - (S[3 - i] + a[k]));
                if (newDelta < Delta) {
                    Move(i, k);
                    return true;  // Có cải thiện
                }
            }
        }
    }
    return false;  // Không tìm thấy phần tử cải thiện
}

// Tìm cặp phần tử từ hai tập để hoán đổi nhằm giảm chênh lệch
bool FindAndSwapPair() {
    for (int i = 0; i < N; ++i) {
        if (x[i] == 1) {  // Phần tử thuộc tập 1
            for (int j = 0; j < N; ++j) {
                if (x[j] == 2) {  // Phần tử thuộc tập 2
                    int newDelta = abs((S[1] - a[i] + a[j]) - (S[2] + a[i] - a[j]));
                    if (newDelta < Delta) {
                        Move(1, i);  // Chuyển i sang tập 2
                        Move(2, j);  // Chuyển j sang tập 1
                        return true; // Có cải thiện
                    }
                }
            }
        }
    }
    return false;  // Không tìm thấy cặp phần tử hoán đổi
}

// Chia mảng thành 2 tập sao cho chênh lệch tổng là nhỏ nhất
void Solve() {
    Initialize();
    bool improved = true;
    while (improved) {
        improved = FindAndMoveSingle();  // Tìm phần tử đơn để chuyển
        if (!improved) {
            improved = FindAndSwapPair();  // Tìm cặp phần tử để hoán đổi
        }
    }
}

// Ghi kết quả ra file
void WriteOutput() {
    ofstream fo(OUTPUT_FILE);
    fo << S[1] << " " << S[2] << " " << Delta << "\n";
    for (int i = 0; i < N; ++i) {
        if (x[i] == 1) fo << i + 1 << " ";  // In chỉ số các phần tử của tập 1
    }
    fo << "\n";
    for (int i = 0; i < N; ++i) {
        if (x[i] == 2) fo << i + 1 << " ";  // In chỉ số các phần tử của tập 2
    }
    fo.close();
}

int main() {
    ReadInput();   // Đọc dữ liệu từ file
    Solve();       // Chia mảng thành hai tập
    WriteOutput(); // Ghi kết quả ra file
    return 0;
}

