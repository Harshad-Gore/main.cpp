// CPP program to find mean and median
// of sorted square matrix.
#include <bits/stdc++.h>
using namespace std;

const int N = 4;

// Returns mean of a given matrix of
// size n x n.
double findMean(int a[][N])
{
	int sum = 0;

	// total sum calculation of matrix
	for (int i=0; i<N; i++)
	for (int j=0; j<N; j++)
		sum += a[i][j];

	return (double)sum/(N*N);
}

// Function for calculating median
double findMedian(int a[][N])
{
	if (N % 2 != 0)
	return a[N/2][N/2];

	if (N%2 == 0)
	return (a[(N-2)/2][N-1] +
					a[N/2][0])/2.0;
}

// Driver program
int main()
{
	int a[N][N]= {{1, 2, 3, 4},
				{5, 6, 7, 8},
				{9, 10, 11, 12},
				{13, 14, 15, 16}};
	cout << "Mean : " << findMean(a) << endl
		<< "Median : "<< findMedian(a) << endl;
	return 0;
}
