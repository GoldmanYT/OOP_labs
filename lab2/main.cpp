#include <iostream>
using namespace std;

const double pi = 3.1415926535;
const int precision = 5;

double arccos(double x, int epsilon);
double format(double x, int precision);

int main()
{
    double x1, x2, dx;
    int epsilon;

    cout << "Enter x1: ";
    cin >> x1;
    cout << "Enter x2: ";
    cin >> x2;
    cout << "Enter dx: ";
    cin >> dx;
    cout << "Enter epsilon: ";
    cin >> epsilon;

    cout << "x\tarccos\tepsilon\n";
    for (double x = x1; x <= x2; x += dx)
    {
        cout << format(x, precision) << "\t" << 
                format(arccos(x, epsilon), precision) << 
                "\t" << epsilon << "\n";
    }
    return 0;
}

double arccos(double x, int epsilon)
{
    double result = pi / 2 - x;
    double pow_x = x * x * x;
    double numerator = 1;
    double denomerator = 2;
    for (int n = 1; n <= epsilon; n++)
    {
        result -= (numerator * pow_x) / (denomerator * (2 * n + 1));
        pow_x *= x * x;
        numerator *= 2 * n + 1;
        denomerator *= 2 * (n + 1);
    }
    return result;
}

double format(double x, int precision)
{
    for (int i = 0; i < precision; i++)
    {
        x *= 10;
    }
    x = int(x);
    for (int i = 0; i < precision; i++)
    {
        x /= 10;
    }
    return x;
}
