import sys

def factorial(n):
    if n <= 1:
        return 1
    return factorial(n - 1) * n

n = 0
if len(sys.argv) > 1:
    n = int(sys.argv[1])

print(factorial(n))
