import os
import random


def generate_test_cases():
    for i in range(1, 21):
        # Tên test case với số thứ tự
        test_case_number = f"test{i:02d}"

        # Tạo thư mục nếu chưa tồn tại
        if not os.path.exists(test_case_number):
            os.makedirs(test_case_number)

        # Số lượng phần tử N
        n = min(100000, 2**i)  # Số lượng phần tử tăng dần, giới hạn là 100,000
        array = [random.randint(-(10**9), 10**9) for _ in range(n)]

        # Tạo file input
        with open(f"{test_case_number}/SUMSEQ.inp", "w") as inp_file:
            inp_file.write(f"{n}\n")
            inp_file.write(" ".join(map(str, array)) + "\n")

        # Để tạo file output, sử dụng giải pháp Kadane's Algorithm với độ phức tạp O(N)
        def max_subarray_sum(arr):
            max_ending_here = max_so_far = arr[0]
            for x in arr[1:]:
                max_ending_here = max(x, max_ending_here + x)
                max_so_far = max(max_so_far, max_ending_here)
            return max_so_far

        max_sum = max_subarray_sum(array)

        # Tạo file output
        with open(f"{test_case_number}/SUMSEQ.out", "w") as out_file:
            out_file.write(f"{max_sum}\n")


if __name__ == "__main__":
    generate_test_cases()
