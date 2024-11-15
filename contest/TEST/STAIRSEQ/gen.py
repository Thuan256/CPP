import os
import random


# Function to compute the longest staircase subsequence
def longest_staircase_subsequence(arr, d):
    n = len(arr)
    # This will hold the smallest possible ending value for subsequences of length i
    subseq = []

    for num in arr:
        # Use binary search to find the correct position
        low, high = 0, len(subseq) - 1
        while low <= high:
            mid = (low + high) // 2
            if subseq[mid] + d <= num:
                low = mid + 1
            else:
                high = mid - 1

        # If found valid, update subseq with new value
        if low < len(subseq):
            subseq[low] = num
        else:
            subseq.append(num)

    return len(subseq)


# Function to generate test cases for Longest Staircase Subsequence problem
def generate_staircase_test_cases():
    for i in range(1, 21):
        test_case_number = f"test{i:02d}"
        os.makedirs(test_case_number, exist_ok=True)

        # Number of elements N and step D
        n = min(100000, 2**i)  # Limit N up to 100,000
        d = random.randint(0, 10**5)  # Random D between 0 and 100,000

        array = [random.randint(-(10**9), 10**9) for _ in range(n)]

        # Write input file
        with open(f"{test_case_number}/STAIRSEQ.inp", "w") as inp_file:
            inp_file.write(f"{n} {d}\n")
            inp_file.write(" ".join(map(str, array)) + "\n")

        # Calculate the correct answer using the function
        result = longest_staircase_subsequence(array, d)

        # Write output file with the correct result
        with open(f"{test_case_number}/STAIRSEQ.out", "w") as out_file:
            out_file.write(f"{result}\n")


if __name__ == "__main__":
    generate_staircase_test_cases()
