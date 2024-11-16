import os
import random


def create_test_case(folder_name, n, k):
    # Tạo folder nếu chưa tồn tại
    if not os.path.exists(folder_name):
        os.makedirs(folder_name)

    # Tạo file BONUS.INP với giá trị n và k, và ma trận ngẫu nhiên
    with open(os.path.join(folder_name, "BONUS.INP"), "w") as inp:
        inp.write(f"{n} {k}\n")
        matrix = [[random.randint(1, 1000) for _ in range(n)] for _ in range(n)]
        for row in matrix:
            inp.write(" ".join(map(str, row)) + "\n")

    # Tính tổng cam lớn nhất với ma trận tích lũy
    prefix_sum = [[0] * (n + 1) for _ in range(n + 1)]

    # Xây dựng ma trận tích lũy
    for i in range(n):
        for j in range(n):
            prefix_sum[i + 1][j + 1] = (
                matrix[i][j]
                + prefix_sum[i][j + 1]
                + prefix_sum[i + 1][j]
                - prefix_sum[i][j]
            )

    # Tìm tổng lớn nhất cho hình vuông k x k
    max_sum = 0
    for i in range(n - k + 1):
        for j in range(n - k + 1):
            # Tính tổng của hình vuông k x k bắt đầu tại (i, j) sử dụng prefix_sum
            total = (
                prefix_sum[i + k][j + k]
                - prefix_sum[i][j + k]
                - prefix_sum[i + k][j]
                + prefix_sum[i][j]
            )
            max_sum = max(max_sum, total)

    # Lưu kết quả vào BONUS.OUT
    with open(os.path.join(folder_name, "BONUS.OUT"), "w") as out:
        out.write(str(max_sum))


# Tạo 20 test case với độ phức tạp tăng dần
for i in range(1, 21):
    n = (
        random.randint(1, 50) if i <= 5 else random.randint(51, 1000)
    )  # Giới hạn nhỏ hơn khi i <= 5
    k = random.randint(1, n)
    create_test_case(f"test{i:02d}", n, k)
