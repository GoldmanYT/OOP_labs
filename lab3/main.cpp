#include <iostream>
#include <fstream>

using namespace std;

const int max_size = 100;

void part_a();
void part_b();

double sum_negative(double a[], int n);
double product_min_max(double a[], int n);
int min_index(double a[], int n);
int max_index(double a[], int n);
void sort(double a[], int n);

int count_no_zero_rows(int a[][max_size], int n);
int max_repeated(int a[][max_size], int n);
bool repeated(int x, int a[][max_size], int n);

int main()
{
    part_a();
    part_b();
    return 0;
}

void part_a()
{
    ifstream file("lab3_input_part_a.txt");
    int n;
    file >> n;
    double a[max_size];
    cout << "part A:\n";
    cout << "array: ";
    for (int i = 0; i < n; i++)
    {
        file >> a[i];
        cout << a[i] << " ";
    }
    cout << "\n";

    cout << "sum_negative: " << sum_negative(a, n) << "\n";
    cout << "product_min_max: " << product_min_max(a, n) << "\n";
    sort(a, n);
    cout << "sorted: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n\n";
}

void part_b()
{
    ifstream file("lab3_input_part_b.txt");
    int n;
    file >> n;
    int a[max_size][max_size];
    cout << "part B:\n";
    cout << "matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> a[i][j];
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    file.close();
    cout << "\n";
    
    cout << "count_no_zero_rows: " << count_no_zero_rows(a, n) << "\n";
    cout << "max_repeated: " << max_repeated(a, n) << "\n";
}

double sum_negative(double a[], int n)
{
    double result = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            result += a[i];
        }
    }

    return result;
}

double product_min_max(double a[], int n)
{
    int i1 = min_index(a, n), i2 = max_index(a, n);
    if (i1 > i2)
    {
        swap(i1, i2);
    }

    double result = 1;

    for (int i = i1 + 1; i < i2; i++)
    {
        result *= a[i];
    }

    return result;
}

int min_index(double a[], int n)
{
    int index = 0;
    double min_value = a[0];
    
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min_value)
        {
            min_value = a[i];
            index = i;
        }
    }

    return index;
}

int max_index(double a[], int n)
{
    int index = 0;
    double max_value = a[0];
    
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max_value)
        {
            max_value = a[i];
            index = i;
        }
    }

    return index;
}

void sort(double a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int j = max_index(a, n - i);
        swap(a[j], a[n - i - 1]);
    }
}

int count_no_zero_rows(int a[][max_size], int n)
{
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        bool has_zero = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                has_zero = 1;
                break;
            }
        }
        if (!has_zero)
        {
            result++;
        }
    }

    return result;
}

int max_repeated(int a[][max_size], int n)
{
    int result = -0x7f'00'00'00;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (repeated(a[i][j], a, n) && a[i][j] > result)
            {
                result = a[i][j];
            }
        }
    }

    return result;
}

bool repeated(int x, int a[][max_size], int n)
{
    bool count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == x)
            {
                if (count)
                {
                    return true;
                }
                count = true;
            }
        }
    }
    return false;
}
