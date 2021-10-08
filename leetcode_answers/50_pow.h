#pragma once


double myPow(double x, int n)
{
    if (n == 0) return 1;
    else if (n == 1) return x;

    int p = n / 2;
    if (n < 0) {
        p = -p;
        x = 1 / x;
    }
    double res = myPow(x, p);
    if (n % 2 == 0) return res * res;
    else return res * res * x;
}