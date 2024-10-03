#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const double pi = M_PI;
const int precision = 7;

string format(double x);

int main()
{
    double x1, x2, dx, eps;

    cout << "Enter x1: ";
    cin >> x1;
    cout << "Enter x2: ";
    cin >> x2;
    cout << "Enter dx: ";
    cin >> dx;
    cout << "Enter eps: ";
    cin >> eps;

    cout << "x\tarccos\tcount\tacos\n";
    for (double x = x1; x <= x2; x += dx)
    {
        double result = pi / 2 - x;
        double prev = pi / 2;
        double pow_x = x * x * x;
        double numerator = 1;
        double denomerator = 2;
        int n;
        for (n = 1; abs(result - prev) > 10 * eps; n++)
        {
            prev = result;
            result -= (numerator * pow_x) / (denomerator * (2 * n + 1));
            pow_x *= x * x;
            numerator *= 2 * n + 1;
            denomerator *= 2 * (n + 1);
        }
        cout << format(x) << "\t" << format(result) << "\t" << n << "\t" << format(acos(x)) << "\n";
    }
    return 0;
}

string format(double x)
{
    string s = to_string(x);
    return s.substr(0, precision);
}
