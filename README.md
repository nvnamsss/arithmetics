# How to run
Simply `build` then `run` using `make`.

`g++` is required to build the source code
```bash
make build
make run
```

# Result
## Testing
For multiplying x by n, the code has tested these cases:
- n = 0
- n is even
- n is odd
- n < 0

For powering x by n, the code has tested these cases:
- n = 0
- n < 0
- x > 0, n is even
- x > 0, n is odd
- x < 0, n is even
- x < 0, n is odd

After running the code, this is the result:
```
[O(logn] 1.391*0 = 0
[O(logn] 1.391*1 = 1.391
[O(logn] 1.391*2 = 2.782
[O(logn] 1.391*3 = 4.173
[O(logn] 1.391*10 = 13.91
[O(logn] 1.391*1375 = 1912.625
[O(logn] 1.391*-1375 = -1912.625
[O(logn)] 2^0 = 1
[O(logn)] 2^-2 = 0.25
[O(logn)] 2^32 = 4294967296
[O(logn)] 2^45 = 35184372088832
[O(logn)] -4.5^4 = 410.0625
[O(logn)] -4.5^13 = -310286355.99719238
```

## Benchmarks
Below is a table showing performance of arithmetics using different time complexity algorithm.

There are two arithmetics `Multiply(double x, long n)` and `Power(double x, long n)`. These arithmetics are implemented using two approaches having `O(n)` and `O(logn)` time complexity.

This test was consulted by running these two arithmetics with large `n`.

| arithmetic | n | execution time (ms) |
|------|-----|--------|
| O(logn) mul | 1e9  | 0.0008   |
| O(n) mul | 1e9  | 2001.81    |
| O(logn) mul | 1e10  | 0.0009   |
| O(n) mul | 1e10  | 21800.69    |
| O(logn) pow | 1e9  | 0.0001 |
| O(n) pow | 1e10  | 1979.66   |
| O(logn) pow | 1e9  | 0.0002 |
| O(n) pow | 1e10  | 21987.58   |
