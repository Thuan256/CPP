import os
import random
import string

def is_palindrome(s):
    return s == s[::-1]

def count_palindromic_substrings(s):
    n = len(s)
    count = 0
    # Kiểm tra từng xâu con của s
    for i in range(n):
        # Palindrome lẻ
        l, r = i, i
        while l >= 0 and r < n and s[l] == s[r]:
            count += 1
            l -= 1
            r += 1
        # Palindrome chẵn
        l, r = i, i + 1
        while l >= 0 and r < n and s[l] == s[r]:
            count += 1
            l -= 1
            r += 1
    return count

def create_test_case(folder_name, s):
    # Tạo folder nếu chưa tồn tại
    if not os.path.exists(folder_name):
        os.makedirs(folder_name)

    # Tạo file SUBPAL.INP với chuỗi s
    with open(os.path.join(folder_name, "SUBPAL.INP"), "w") as inp:
        inp.write(s)

    # Đếm số lượng xâu con liên tiếp là Palindrome
    result = count_palindromic_substrings(s)

    # Lưu kết quả vào SUBPAL.OUT
    with open(os.path.join(folder_name, "SUBPAL.OUT"), "w") as out:
        out.write(str(result))

# Tạo 20 test case với độ dài chuỗi khác nhau
for i in range(1, 21):
    if i <= 5:
        length = random.randint(1, 100)  # Giới hạn nhỏ hơn khi i <= 5
    elif i <= 10:
        length = random.randint(101, 1000)
    else:
        length = random.randint(1001, 100000)  # Tối đa 10^5 ký tự
    s = ''.join(random.choices(string.ascii_lowercase, k=length))
    create_test_case(f"test{i:02d}", s)
