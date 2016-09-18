#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	// create a 2D Matrix
	int m_MatrixA[2][3] =
	{
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};

	// create another 2D Matrix
	int m_MatrixB[2][3] =
	{
		{ 10, 50, -2 },
		{ -3, 11, 92 }
	};

	// create a third 2D Matrix
	int m_MatrixC[2][3];	// sum

	// output the result of Matrix C = Matrix A + Matrix B
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// assign the value of matrix a + matrix b to matrix c
			m_MatrixC[i][j] = m_MatrixA[i][j] + m_MatrixB[i][j];
		}
		cout << endl;
	}

	// output the results of each matrix singularly, then the sum of C = both A + B
	cout << "========" << endl;
	cout << "Matrix A" << endl;
	cout << "========" << endl << endl;
	cout << "m_MatrixA[2][3] = [ " << m_MatrixA[0][0] << ", " << m_MatrixA[0][1] << ", " << m_MatrixA[0][2] << "]" << endl;
	cout << "                  [ " << m_MatrixA[1][0] << ", " << m_MatrixA[1][1] << ", " << m_MatrixA[1][2] << "]" << endl << endl;
	
	cout << "========" << endl;
	cout << "Matrix B" << endl;
	cout << "========" << endl << endl;
	cout << "m_MatrixB[2][3] = [ " << m_MatrixB[0][0] << ", " << m_MatrixB[0][1] << ", " << m_MatrixB[0][2] << "]" << endl;
	cout << "                  [ " << m_MatrixB[1][0] << ", " << m_MatrixB[1][1] << ", " << m_MatrixB[1][2] << "]" << endl << endl;

	cout << "==============================" << endl;
	cout << "Matrix C = Matrix A + Matrix B" << endl;
	cout << "==============================" << endl << endl;
	cout << "m_MatrixC[2][3] = [ " << m_MatrixC[0][0] << ", " << m_MatrixC[0][1] << ", " << m_MatrixC[0][2] << "]" << endl;
	cout << "                  [ " << m_MatrixC[1][0] << ", " << m_MatrixC[1][1] << ", " << m_MatrixC[1][2] << "]" << endl << endl;

	cin.ignore();
	cin.get();
	return 0;
}