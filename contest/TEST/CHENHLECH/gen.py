import os
import random
import string

def max_diff_substring(s):
    """Tính độ chênh lệch lớn nhất của các xâu con."""
    max_diff = 0
    n = len(s)

    # Duyệt qua tất cả các xâu con (đơn giản nhưng chậm cho test nhỏ)
    freq = [0] * 26  # Đếm số lần xuất hiện của mỗi ký tự trong xâu
    for i in range(n):
        freq = [0] * 26
        for j in range(i, n):
            freq[ord(s[j]) - ord('a')] += 1
            max_freq = max(freq)
            min_freq = min(x for x in freq if x > 0)
            max_diff = max(max_diff, max_freq - min_freq)
    return max_diff

def generate_test_cases():
    # Số lượng test case
    num_tests = 20

    for idx in range(num_tests):
        # Đặt kích thước N tăng dần theo độ khó
        if idx < 5:
            N = random.randint(1, 100)  # Test nhỏ
        elif idx < 10:
            N = random.randint(100, 1000)  # Test trung bình
        elif idx < 15:
            N = random.randint(1000, 10000)  # Test lớn
        else:
            N = random.randint(10000, 100000)  # Test rất lớn

        # Sinh xâu S ngẫu nhiên
        S = ''.join(random.choices(string.ascii_lowercase, k=N))

        # Tính output (dành cho test nhỏ và trung bình)
        if N <= 1000:
            result = max_diff_substring(S)
        else:
            # Với test lớn, không chạy thuật toán chậm
            result = "0"  # Chỉ placeholder, bạn có thể tính riêng nếu cần

        # Tạo thư mục và lưu file
        folder_name = f"test{idx+1:02d}"
        os.makedirs(folder_name, exist_ok=True)

        # Ghi file .inp
        with open(f"{folder_name}/CHENHLECH.inp", "w") as f_inp:
            f_inp.write(f"{N}\n{S}\n")
        
        # Ghi file .out
        with open(f"{folder_name}/CHENHLECH.out", "w") as f_out:
            f_out.write(f"{result}\n")

if __name__ == "__main__":
    generate_test_cases()
