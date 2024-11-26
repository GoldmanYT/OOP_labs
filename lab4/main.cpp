#include <iostream>
#include <string>

using namespace std;

const int max_size = 100;

void print(double *a, int n);
double sum_negative(double *a, int n);
double product_min_max(double *a, int n);
int min_index(double *a, int n);
int max_index(double *a, int n);
void sort(double *a, int n);

void print(int **a, int n);
int count_no_zero_rows(int **a, int n);
int max_repeated(int **a, int n);
bool repeated(int x, int **a, int n);

typedef double (*PF)(double*, int);
void do_task8(PF, double*, int);

int main()
{
    // Задание 1
    int var_int = 5;
    bool var_bool = true;
    char var_char = 'g';
    wchar_t var_wchar = 'w';
    float var_float = 3.14f;
    double var_double = 6.28;

    int *ptr_int = &var_int;
    bool *ptr_bool = &var_bool;
    char *ptr_char = &var_char;
    wchar_t *ptr_wchar = &var_wchar;
    float *ptr_float = &var_float;
    double *ptr_double = &var_double;

    cout << "address: " << ptr_int << "\tvalue: " << *ptr_int << endl;
    cout << "address: " << ptr_bool << "\tvalue: " << *ptr_bool << endl;
    cout << "address: " << (int *)ptr_char << "\tvalue: " << *ptr_char << endl;
    cout << "address: " << ptr_wchar << "\tvalue: " << *ptr_wchar << endl;
    cout << "address: " << ptr_float << "\tvalue: " << *ptr_float << endl;
    cout << "address: " << ptr_double << "\tvalue: " << *ptr_double << endl;
    cout << endl;

    // Задание 2
    enum Color
    {
        red,
        green,
        blue
    };

    const int color_count = 4;
    Color color_sequence[color_count]{red, blue, green, red};
    Color *ptr_color_sequence = color_sequence;

    cout << "color red id: " << red << endl;
    cout << "color green id: " << green << endl;
    cout << "color blue id: " << blue << endl;
    cout << "color sequence: ";
    for (int i = 0; i < color_count; i++)
    {
        cout << *(ptr_color_sequence + i);
        cout << ((i != color_count - 1) ? ", " : "\n");
    }
    cout << endl;

    // Задание 3
    struct Person
    {
        enum Sex
        {
            male,
            female
        };
        string name;
        int age;
        Sex sex;
    };

    Person vanya{"Ivan", 18, Person::male};
    Person dasha{"Dariya", 19, Person::female};

    Person *ptr_vanya = &vanya;
    Person *ptr_dasha = &dasha;

    cout << "name: " << ptr_vanya->name;
    cout << "\tage: " << ptr_vanya->age;
    cout << "\tsex: " << ptr_vanya->sex << endl;

    cout << "name: " << ptr_dasha->name;
    cout << "\tage: " << ptr_dasha->age;
    cout << "\tsex: " << ptr_dasha->sex << endl;
    cout << endl;

    // Задание 4
    cout << ptr_char << " -> " << (int *)ptr_char << endl;
    cout << ptr_wchar << " -> " << (int *)ptr_wchar << endl;
    cout << ptr_float << " -> " << (int *)ptr_float << endl;
    cout << endl;

    // Задание 5, 7
    {
        const int n = 5;
        double a[]{-4.4, 1.1, -2.2, 3.3, 5.5};
        cout << "array:\t";
        print(a, n);
        cout << endl;
        cout << "sum of negative:\t" << sum_negative(a, n) << endl;
        cout << "product between min & max:\t" << product_min_max(a, n) << endl;
        sort(a, n);
        cout << "sorted array:\t";
        print(a, n);
        cout << endl;
    }

    // Задание 6
    {
        const int n = 5;
        int **a = new int *[max_size] {};
        int data[][max_size]{
            {1, 2, 3, 4, 5},
            {0, 1, 2, 3, 4},
            {10, 9, 8, 7, 6},
            {-1, -2, -3, -4, -5},
            {1, 3, 5, 7, 9}};
        for (int i = 0; i < n; i++)
        {
            a[i] = new int[max_size];
            for (int j = 0; j < n; j++)
            {
                a[i][j] = data[i][j];
            }
        }
        cout << "matrix:\n";
        print(a, n);
        cout << "count no zero rows:\t" << count_no_zero_rows(a, n) << endl;
        cout << "max repeated:\t" << max_repeated(a, n) << endl;
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            delete[] a[i];
        }
        delete[] a;
    }

    // Задание 8
    {
        const int n = 5;
        double a[]{-4.4, 1.1, -2.2, 3.3, 5.5};
        PF ptr_fun = product_min_max;
        cout << "array:\t";
        print(a, n);
        cout << endl;
        cout << "product between min & max:\t";
        do_task8(ptr_fun, a, n);
		cout << endl << endl;
    }

    // Задание 9
    void *ptr_void;
    cout << "int value: " << *ptr_int << endl;
    cout << "bool value: " << *ptr_bool << endl;
    cout << "char value: " << *ptr_char << endl;
    cout << "wchar_t value: " << *ptr_wchar << endl;
    cout << "float value: " << *ptr_float << endl;
    cout << "double value: " << *ptr_double << endl << endl;
    
    ptr_void = ptr_int;
    cout << "int value: " << *(int *)ptr_void << endl;
    ptr_void = ptr_bool;
    cout << "bool value: " << *(bool *)ptr_bool << endl;
    ptr_void = ptr_char;
    cout << "char value: " << *(char *)ptr_char << endl;
    ptr_void = ptr_wchar;
    cout << "wchar_t value: " << *(wchar_t *)ptr_wchar << endl;
    ptr_void = ptr_float;
    cout << "float value: " << *(float *)ptr_float << endl;
    ptr_void = ptr_double;
    cout << "double value: " << *(double *)ptr_double << endl << endl;
    
    ptr_void = ptr_vanya;
    cout << "name: " << ((Person *)ptr_void)->name;
    cout << "\tage: " << ((Person *)ptr_vanya)->age;
    cout << "\tsex: " << ((Person *)ptr_vanya)->sex << endl;
    
    ptr_void = ptr_dasha;
    cout << "name: " << ((Person *)ptr_void)->name;
    cout << "\tage: " << ((Person *)ptr_vanya)->age;
    cout << "\tsex: " << ((Person *)ptr_vanya)->sex << endl;
    
    return 0;
}

void print(double *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
    cout << endl;
}

double sum_negative(double *a, int n)
{
    double result = 0;

    for (int i = 0; i < n; i++)
    {
        if (*(a + i) < 0)
        {
            result += *(a + i);
        }
    }

    return result;
}

double product_min_max(double *a, int n)
{
    int i1 = min_index(a, n), i2 = max_index(a, n);
    if (i1 > i2)
    {
        swap(i1, i2);
    }

    double result = 1;

    for (int i = i1 + 1; i < i2; i++)
    {
        result *= *(a + i);
    }

    return result;
}

int min_index(double *a, int n)
{
    int index = 0;
    double min_value = *a;

    for (int i = 0; i < n; i++)
    {
        if (*(a + i) < min_value)
        {
            min_value = *(a + i);
            index = i;
        }
    }

    return index;
}

int max_index(double *a, int n)
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

void sort(double *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int j = max_index(a, n - i);
        swap(*(a + j), *(a + n - i - 1));
    }
}

void print(int **a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int count_no_zero_rows(int **a, int n)
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

int max_repeated(int **a, int n)
{
    int result = -0x7f'ff'ff'ff - 1;

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

bool repeated(int x, int **a, int n)
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

void do_task8(PF ptr_fun, double *a, int n)
{
	cout << ptr_fun(a, n);
}