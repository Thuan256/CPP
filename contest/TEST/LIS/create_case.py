import os
import random


def generate_test_cases():
    for i in range(1, 21):
        # Tên test case với số thứ tự
        test_case_number = f"test{i:02d}"

        # Tạo thư mục nếu chưa tồn tại
        if not os.path.exists(test_case_number):
            os.makedirs(test_case_number)

        n = min(100000, 2**i)  # Số lượng phần tử tăng dần (giới hạn tối đa là 100,000)
        array = [random.randint(1, 10**9) for _ in range(n)]

        # Tạo file input
        with open(f"{test_case_number}/LIS.inp", "w") as inp_file:
            inp_file.write(f"{n}\n")
            inp_file.write(" ".join(map(str, array)) + "\n")

        # Để tạo file output, sử dụng giải pháp tìm LIS với độ phức tạp O(N log N)
        def lis_length(arr):
            from bisect import bisect_left

            lis = []
            for x in arr:
                pos = bisect_left(lis, x)
                if pos == len(lis):
                    lis.append(x)
                else:
                    lis[pos] = x
            return len(lis)

        lis_len = lis_length(array)

        # Tạo file output
        with open(f"{test_case_number}/LIS.out", "w") as out_file:
            out_file.write(f"{lis_len}\n")


if __name__ == "__main__":
    generate_test_cases()
