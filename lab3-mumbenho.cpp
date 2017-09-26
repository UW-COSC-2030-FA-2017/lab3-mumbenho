// lab03-mumbenho.cpp
// McKade Umbenhower

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

short sumOneToNShort(int);
long sumOneToNLong(int);

float factorialFloat(int);
double factorialDouble(int);

float ratioSumFloat(int);
double ratioSumDouble(int);

int main()
{
	int n = 0;

	cout << "Enter an integer n for short sum (overflows at 256): ";
	cin >> n;
	cout << "Sum of 1 to " << n << " using short values is: " << sumOneToNShort(n) << endl << endl;

	cout << "Enter an integer n for long sum (overflows at 1000364): ";
	cin >> n;
	cout << "Sum of 1 to " << n << " using long values is: " << sumOneToNLong(n) << endl << endl;
	
	cout << "Enter an integer n for float product (overflows at 35): ";
	cin >> n;
	cout << "Product of 1 to " << n << " using float values is: " << factorialFloat(n) << endl << endl;
	
	cout << "Enter an integer n for double product (overflows at 171): ";
	cin >> n;
	cout << "Product of 1 to " << n << " using double values is: " << factorialDouble(n) << endl << endl;
	
	cout << "Enter an integer n for float ratio sum: ";
	cin >> n;
	cout << "Sum of 1/" << n << " n times - 1 using float values is: " << ratioSumFloat(n) << endl << endl;
	
	cout << "Enter an integer n for double ratio sum: ";
	cin >> n;
	cout << "Sum of 1/" << n << " n times - 1 using double values is: " << ratioSumDouble(n) << endl << endl;

	// The numeric error occurs when i = 4.4
	// It should not loop through again because 4.4 is not less than 4.4,
	// but it does.  This is because of floating point numbers are not exact,
	// so the loop sum might be considered different than the 4.4 in the loop header
	for (float i = 3.4; i < 4.4; i += .2)
	{
		cout << "i = " << i << endl;
	}

	// The loop now works as expected with the index being of type double
	for (double i = 3.4; i < 4.4; i += .2)
	{
		cout << "i = " << i << endl;
	}

	return 0;
}

short sumOneToNShort(int n)
{
	// Sum using short variable type
	short sum = 0;

	// Answer to #2: Overflow occurs when n = 256
	// An overflow is dectectable because the result
	// is a negative number (-32640)
	for (short i = 1; i < n + 1; i++)
	{
		sum += i;
	}

	return sum;
}

long sumOneToNLong(int n)
{
	// Sum using long variable type
	long sum = 0;

	// Answer to #2: Overflow occurs when n = 1,000,364
	// An overflow is dectectable because the result
	// is a negative number (-2146607202)
	for (long i = 1; i < n + 1; i++)
	{
		sum += i;
	}

	return sum;
}

float factorialFloat(int n)
{
	// Product using long variable type
	float product = 1;

	// Answer to #4: Overflow occurs when n = 35
	// An overflow is dectectable because the result
	// is inf
	for (long i = 1; i < n + 1; i++)
	{
		product *= i;
	}

	return product;
}

double factorialDouble(int n)
{
	// Product using long variable type
	double product = 1;

	// Answer to #4: Overflow occurs when n = 171
	// An overflow is dectectable because the result
	// is inf
	for (long i = 1; i < n + 1; i++)
	{
		product *= i;
	}

	return product;
}

float ratioSumFloat(int n)
{
	// Ratio sum using floats
	float sum = 0;
	float ratio = 1.0f / n;

	// The sum is equivalent to 0 if the computations are exact
	// Even at small values, like 10 and above, the output result is not equal to exactly 0
	// This is due to low decimal precision
	for (int i = 1; i < n + 1; i++)
	{
		sum += ratio;
	}
	sum -= 1;
	return sum;
}

double ratioSumDouble(int n)
{
	// Ratio sum using floats
	double sum = 0;
	double ratio = 1.0 / n;

	// The sum should go to 0, but it
	// does not for small values, like 6 with repeating digits.
	// However, some numbers do still work, like 12 until ~20.
	// Then the precision of the double gets off.
	for (int i = 1; i < n + 1; i++)
	{
		sum += ratio;
	}

	sum -= 1;

	return sum;
}
