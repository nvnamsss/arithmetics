#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Arithmetics
{
public:
    double naiveMul(double x, long n)
    {
        double ans = 0;
        while (n > 0)
        {
            ans += x;
            n--;
        }
        return ans;
    }

    double mul(double x, long n)
    {
        if (n < 0)
        {
            x = -x;
        }

        double ans = 0;
        double sum = x;
        while (n != 0)
        {
            if (n % 2)
            {
                ans = ans + sum;
            }

            sum = sum + sum;
            n /= 2;
        }
        return ans;
    }

    double naivePow(double x, long n)
    {
        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }

        double ans = 1;
        while (n != 0)
        {
            ans = ans * x;
            n--;
        }

        return ans;
    }

    double pow(double x, long n)
    {
        if (n < 0)
        {
            x = 1 / x;
        }
        double ans = 1;
        double product = x;

        while (n != 0)
        {
            if (n % 2)
            {
                ans = ans * product;
            }

            product = product * product;
            n /= 2;
        }

        return ans;
    }
};

int main()
{
    Arithmetics a;
    cout.precision(17);
    // O(logn) multiply
    cout << "[O(logn] 1.391*0 = " << a.mul(1.391, 0) << endl;
    cout << "[O(logn] 1.391*1 = " << a.mul(1.391, 1) << endl;
    cout << "[O(logn] 1.391*2 = " << a.mul(1.391, 2) << endl;
    cout << "[O(logn] 1.391*3 = " << a.mul(1.391, 3) << endl;
    cout << "[O(logn] 1.391*10 = " << a.mul(1.391, 10) << endl;
    cout << "[O(logn] 1.391*1375 = " << a.mul(1.391, 1375) << endl;
    cout << "[O(logn] 1.391*-1375 = " << a.mul(1.391, -1375) << endl;

    // O(logn) pow
    cout << "[O(logn)] 2^0 = " << a.pow(2, 0) << endl;
    cout << "[O(logn)] 2^-2 = " << a.pow(2, -2) << endl;
    cout << "[O(logn)] 2^32 = " << a.pow(2, 32) << endl;
    cout << "[O(logn)] 2^45 = " << a.pow(2, 45) << endl;
    cout << "[O(logn)] -4.5^4 = " << a.pow(-4.5, 4) << endl;
    cout << "[O(logn)] -4.5^13 = " << a.pow(-4.5, 13) << endl;

    cout << "Benchmarking" << endl;
    // benchmark multiply
    long n = 1e10;
    auto t1 = high_resolution_clock::now();
    a.mul(1.3, n);
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> measure = t2 - t1;

    cout << "O(logn) mul: " << measure.count() << "ms" << endl;

    t1 = high_resolution_clock::now();
    a.naiveMul(1.3, n);
    t2 = high_resolution_clock::now();
    measure = t2 - t1;
    cout << "O(n) mul: " << measure.count() << "ms" << endl;

    // benchmark pow
    t1 = high_resolution_clock::now();
    a.pow(1.3, n);
    t2 = high_resolution_clock::now();
    measure = t2 - t1;

    cout << "O(logn) pow: " << measure.count() << "ms" << endl;

    t1 = high_resolution_clock::now();
    a.naivePow(1.3, n);
    t2 = high_resolution_clock::now();
    measure = t2 - t1;

    cout << "O(n) pow: " << measure.count() << "ms" << endl;

    return 0;
}
