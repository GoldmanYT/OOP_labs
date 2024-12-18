#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

// Task 1
const double pi2 = M_PI_2;
const size_t precision = 7;

double arccos(double x, double eps);
string format(double x);
void print_table_acos(double a, double b, double eps, double dx = 0.1);
void task1();

// Task 2
void do_task2(void (*task1_func)(double, double, double, double));
void task2();

// Task 3
const unsigned max_size = 100;

void print_array(double a[], unsigned n);
double negative_sum(double a[], unsigned n);
double product_min_max(double a[], unsigned n);
void sort_array(double a[], unsigned n);
void task3();

// Task 4
unsigned digit_count(char s[], unsigned n);
void task4();

// Task 5
void print_array(int a[][max_size], unsigned n, unsigned m);
unsigned count_no_zero_rows(int a[][max_size], unsigned n, unsigned m);
int max_repeated(int a[][max_size], unsigned n, unsigned m);
unsigned element_count(int elem, int a[][max_size], unsigned n, unsigned m);
void task5();

// Task 6
struct Student
{
	string name;
	unsigned age;
};
void print_struct(Student student);
void task6();

// Task 7
void merge_sort(int* a, unsigned n);
void print_array(int a[], unsigned n);
void task7();

// Task 8
void print_array(int a[], unsigned n);
int negative_sum(int a[], unsigned n);
int product_min_max(int a[], unsigned n);
void sort_array(int a[], unsigned n);
void task8();

// Task 9
template <typename T> void print_array(T a[][max_size], unsigned n, unsigned m);
template <typename T> unsigned count_no_zero_rows(T a[][max_size], unsigned n, unsigned m);
void task9();

int main()
{
	task1();
	task2();
	task3();
	task4();
	task5();
	task6();
	task7();
	task8();
	task9();

	return 0;
}

double arccos(double x, double eps)
{
	double ans = pi2 - x, prev = ans - 2 * eps;
	double numerator_iter = 1, denominator_iter = 2;
	double numerator = x * x * x, denominator = 2 * 3;

	while (abs(ans - prev) >= eps)
	{
		prev = ans;
		ans -= numerator / denominator;
		numerator_iter += 2;
		denominator_iter += 2;
		numerator *= numerator_iter * x * x;
		denominator *= denominator_iter * (denominator_iter + 1) / (denominator_iter - 1);
	}

	return ans;
}

string format(double x)
{
	return to_string(x).substr(0, precision);
}

void print_table_acos(double a, double b, double eps, double dx)
{
	cout << "x\tarccos\tacos\n";
	for (double x = a; x <= b; x += dx)
	{
		cout << format(x) << "\t"
			<< format(arccos(x, eps)) << "\t"
			<< format(acos(x)) << "\t"
			<< endl;
	}
	cout << endl;
}

void task1()
{
	print_table_acos(-0.9, 0.9, 1e-5);
}

void do_task2(void(*task1_func)(double, double, double, double))
{
	task1_func(-0.5, 0.5, 1e-5, 0.2);
}

void task2()
{
	void (*task1_func_ptr)(double, double, double, double) = print_table_acos;
	do_task2(task1_func_ptr);
}

void print_array(double a[], unsigned n)
{
	for (unsigned i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

double negative_sum(double a[], unsigned n)
{
	double ans = 0.0;

	for (unsigned i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			ans += a[i];
		}
	}

	return ans;
}

double product_min_max(double a[], unsigned n)
{
	unsigned min_i = 0;
	double min_value = a[0];
	unsigned max_i = 0;
	double max_value = a[0];

	for (unsigned i = 0; i < n; i++)
	{
		if (a[i] < min_value)
		{
			min_value = a[i];
			min_i = i;
		}
		if (a[i] > max_value)
		{
			max_value = a[i];
			max_i = i;
		}
	}

	unsigned i1 = min_i, i2 = max_i;
	double ans = 1;

	if (i1 > i2)
	{
		swap(i1, i2);
	}

	for (unsigned i = i1 + 1; i < i2; i++)
	{
		ans *= a[i];
	}

	return ans;
}

void sort_array(double a[], unsigned n)
{
	for (unsigned i = 0; i < n; i++)
	{
		unsigned min_i = i;
		double min_value = a[i];

		for (unsigned j = i; j < n; j++)
		{
			if (a[j] < min_value)
			{
				min_value = a[j];
				min_i = j;
			}
		}

		swap(a[i], a[min_i]);
	}
}

void task3()
{
	const unsigned size_a = 5;
	double array_a[] = { -5.5, 1.1, -2.2, 3.3, -4.4 };

	cout << "array a: ";
	print_array(array_a, size_a);

	cout << "sum of negative: " << negative_sum(array_a, size_a) << endl;

	cout << "product between min and max: "
		<< product_min_max(array_a, size_a) << endl;

	sort_array(array_a, size_a);

	cout << "sorted a: ";
	print_array(array_a, size_a);
	cout << endl;
}

unsigned digit_count(char s[], unsigned n)
{
	unsigned ans = 0;

	for (unsigned i = 0; i < n; i++)
	{
		ans += (s[i] >= '0' && s[i] <= '9');
	}

	return ans;
}

void task4()
{
	char input_string[max_size];
	unsigned n;

	cout << "Enter string: ";
	cin >> input_string;
	n = strlen(input_string);

	cout << "Digit count: "
		<< digit_count(input_string, n) << endl << endl;
}

void print_array(int a[][max_size], unsigned n, unsigned m)
{
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

unsigned count_no_zero_rows(int a[][max_size], unsigned n, unsigned m)
{
	unsigned ans = 0;

	for (unsigned i = 0; i < n; i++)
	{
		bool has_zero = false;

		for (unsigned j = 0; j < m; j++)
		{
			has_zero |= (a[i][j] == 0);
		}

		ans += !has_zero;
	}

	return ans;
}

int max_repeated(int a[][max_size], unsigned n, unsigned m)
{
	int ans = -0x7fff'ffff - 1;

	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < m; j++)
		{
			if (a[i][j] > ans && element_count(a[i][j], a, n, m) > 1)
			{
				ans = a[i][j];
			}
		}
	}

	return ans;
}

unsigned element_count(int elem, int a[][max_size], unsigned n, unsigned m)
{
	unsigned ans = 0;

	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < m; j++)
		{
			ans += (a[i][j] == elem);
		}
	}

	return ans;
}

void task5()
{
	const unsigned size1_b = 5, size2_b = 5;
	int array_b[][max_size] = {
		{1, 8, 4, 8, 7},
		{6, 2, 9, 0, 1},
		{7, 4, 2, 3, 5},
		{5, 3, 1, 7, 6},
		{4, 0, 8, 3, 5}
	};

	cout << "array b: " << endl;
	print_array(array_b, size1_b, size2_b);
	cout << "count of rows without zeros: "
		<< count_no_zero_rows(array_b, size1_b, size2_b) << endl;
	cout << "max repeated element: "
		<< max_repeated(array_b, size1_b, size2_b) << endl << endl;
}

void print_struct(Student student)
{
	cout << "name: " << student.name
		<< "\tage: " << student.age << endl;
}

void task6()
{
	Student john{ "John", 18 };
	Student sam{ "Sam", 19 };

	print_struct(john);
	print_struct(sam);
	cout << endl;
}

void merge_sort(int* a, unsigned n)
{
	if (n <= 1)
		return;
	int* left = new int[n / 2];
	int* right = new int[(n + 1) / 2];
	for (unsigned i = 0; i < n / 2; i++)
	{
		left[i] = a[i];
	}
	for (unsigned i = n / 2; i < n; i++)
	{
		right[i - n / 2] = a[i];
	}
	merge_sort(left, n / 2);
	merge_sort(right, (n + 1) / 2);
	unsigned left_i = 0, right_i = 0, i = 0;
	while (left_i < n / 2 && right_i < (n + 1) / 2)
	{
		if (left[left_i] < right[right_i])
		{
			a[i] = left[left_i];
			left_i++;
		}
		else
		{
			a[i] = right[right_i];
			right_i++;
		}
		i++;
	}
	while (left_i < n / 2)
	{
		a[i] = left[left_i];
		left_i++;
		i++;
	}
	while (right_i < (n + 1) / 2)
	{
		a[i] = right[right_i];
		right_i++;
		i++;
	}
	delete[] left;
	delete[] right;
}

void task7()
{
	const unsigned size_a = 6;
	int array_a[] = { 50, 10, 20, 40, 30, 101 };

	cout << "array a: ";
	print_array(array_a, size_a);

	merge_sort(array_a, size_a);

	cout << "sorted a: ";
	print_array(array_a, size_a);
	cout << endl;
}

void print_array(int a[], unsigned n)
{
	for (unsigned i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int negative_sum(int a[], unsigned n)
{
	int ans = 0;

	for (unsigned i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			ans += a[i];
		}
	}

	return ans;
}

int product_min_max(int a[], unsigned n)
{
	unsigned min_i = 0;
	int min_value = a[0];
	unsigned max_i = 0;
	int max_value = a[0];

	for (unsigned i = 0; i < n; i++)
	{
		if (a[i] < min_value)
		{
			min_value = a[i];
			min_i = i;
		}
		if (a[i] > max_value)
		{
			max_value = a[i];
			max_i = i;
		}
	}

	unsigned i1 = min_i, i2 = max_i;
	int ans = 1;

	if (i1 > i2)
	{
		swap(i1, i2);
	}

	for (unsigned i = i1 + 1; i < i2; i++)
	{
		ans *= a[i];
	}

	return ans;
}

void sort_array(int a[], unsigned n)
{
	for (unsigned i = 0; i < n; i++)
	{
		unsigned min_i = i;
		int min_value = a[i];

		for (unsigned j = i; j < n; j++)
		{
			if (a[j] < min_value)
			{
				min_value = a[j];
				min_i = j;
			}
		}

		swap(a[i], a[min_i]);
	}
}

void task8()
{
	const unsigned size_a = 5;
	double array_a[] = { -5, 1, -2, 3, -4 };

	cout << "array a: ";
	print_array(array_a, size_a);

	cout << "sum of negative: " << negative_sum(array_a, size_a) << endl;

	cout << "product between min and max: "
		<< product_min_max(array_a, size_a) << endl;

	sort_array(array_a, size_a);

	cout << "sorted a: ";
	print_array(array_a, size_a);
	cout << endl;
}

template<typename T>
void print_array(T a[][max_size], unsigned n, unsigned m)
{
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

template<typename T>
unsigned count_no_zero_rows(T a[][max_size], unsigned n, unsigned m)
{
	unsigned ans = 0;

	for (unsigned i = 0; i < n; i++)
	{
		bool has_zero = false;

		for (unsigned j = 0; j < m; j++)
		{
			has_zero |= (a[i][j] == 0);
		}

		ans += !has_zero;
	}

	return ans;
}

void task9()
{
	const unsigned size1_b = 3, size2_b = 3;
	int array_b_int[][max_size] = {
		{1, 8, 4},
		{6, 0, 9},
		{7, 4, 2}
	};

	cout << "array b of type int: " << endl;
	print_array(array_b_int, size1_b, size2_b);
	cout << "count of rows without zeros: "
		<< count_no_zero_rows<int>(array_b_int, size1_b, size2_b) << endl << endl;

	double array_b_double[][max_size] = {
		{1.1, 8.8, 4.4},
		{6.6, 0.0, 9.9},
		{7.7, 4.4, 2.2}
	};

	cout << "array b of type double: " << endl;
	print_array(array_b_double, size1_b, size2_b);
	cout << "count of rows without zeros: "
		<< count_no_zero_rows(array_b_double, size1_b, size2_b) << endl << endl;
}
