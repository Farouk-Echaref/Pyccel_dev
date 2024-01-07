def factorial(n : int) -> int:
    if n <= 0: return 1
    else     : return n * factorial(n - 1)

def binomial_coefficient(n : int, k : int):
    num = factorial(n)
    den = factorial(k) * factorial(n - k)
    return num // den