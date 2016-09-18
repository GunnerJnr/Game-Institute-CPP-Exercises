#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

// defines
#define PI 3.14f
#define DEGREES 180.f

// function prototypes
float MyArcTangent(float y, float x);
void PrintResults();

int main()
{
	// call functions
	PrintResults();

	cin.get();
	cin.ignore();
	return 0;
}

// function declarations

// Work out the arc tangent and inverse arc tangent
float MyArcTangent(float y, float x)
{
	float sum = 0.f;

	if (x > 0.f)
	{
		sum = (atanf(y / x) * DEGREES) / PI;
	}
	else
	{
		sum = ((atanf(y / x) * DEGREES) / PI) + DEGREES;
	}

	return sum;
}

// print the results
void PrintResults()
{
	cout << "MyArcTangent(4, 2) = " << MyArcTangent(4.f, 2.f) << endl;
	cout << "MyArcTangent(5, 1) = " << MyArcTangent(5.f, -1.f) << endl;
	cout << "MyArcTangent(-4, -6) = " << MyArcTangent(-4.f, -6.f) << endl;
	cout << "MyArcTangent(-6, 4) = " << MyArcTangent(-6.f, 4.f) << endl;
}