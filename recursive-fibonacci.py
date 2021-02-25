import sys

def fibonacci(n):
    fib = 0
    if n > 1:
        fib = fibonacci(n - 1) + fibonacci(n - 2)
        return fib
    elif n == 1:
        return 1
    else:
        return 0


if len(sys.argv) > 1:
    print(fibonacci(int(sys.argv[1])))
else:
    print(fibonacci(5))
