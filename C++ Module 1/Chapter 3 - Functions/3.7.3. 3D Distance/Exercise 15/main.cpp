#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

// globals

// function prototypes
float Dist3(float ux, float uy, float uz, float vx, float vy, float vz);
void PrintPoint(float *pointA, float *pointB);
void PrintDist3(float distance);

int main()
{
	// local
	float m_pointA[3];
	float m_pointB[3];
	float m_dist3 = 0;

	// call methods
	PrintPoint(m_pointA, m_pointB);
	m_dist3 = Dist3(m_pointA[0], m_pointA[1], m_pointA[2], m_pointB[0], m_pointB[1], m_pointB[2]);
	PrintDist3(m_dist3);

	cout << "press any key to exit the program..." << endl;

	cin.get();
	cin.ignore();
	return 0;
}

// function declarations

// Return Distance between the 2 3D points
float Dist3(float ux, float uy, float uz, float vx, float vy, float vz)
{
	// do the sum 
	float distance = sqrtf(powf((vx - ux), 2) + powf((vy - uy), 2) + powf((uz - vz), 2));

	return distance;
}

// Print the two 3D points
void PrintPoint(float *pointA, float *pointB)
{
	for (int i = 0; i < 3; ++i)
	{
		cout << "Enter the first set of 3D points [" << i + 1 << "] = ";
		cin >> pointA[i];
	}
	cout << endl;
	for (int i = 0; i < 3; ++i)
	{
		cout << "Enter the second set of 3D points [" << i + 1 << "] = ";
		cin >> pointB[i];
	}
}

// Print the distance between the two 3D points
void PrintDist3(float distance)
{
	float dist3 = distance;
	cout << endl;
	cout << "The distance between the two 3D points is : " << dist3;
	cout << endl << endl;
}