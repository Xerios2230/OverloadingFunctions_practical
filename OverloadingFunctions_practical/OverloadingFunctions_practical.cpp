#include <iostream>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void sortArray(int[], int, bool desc = false);
void sortHalfArray(int[], int);
void sortBetweenNegatives(int[], int);
int powRec(int, int);
void printStars(int);
int sumRangeRec(int, int);
int minSumPosRec(int[], int, int);
int max(int[], int);
int max(int[3][3]);
int max(int[3][3][3]);
int max(int, int);
int max(int, int, int);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(static_cast<unsigned int>(time(0)));

	// 1
	int a1[10] = { 5, -3, 8, 0, 2, -7, 4, 1, -1, 6 };
	sortArray(a1, 10, false);
	cout << "// 1: ";
	for (int i = 0; i < 10; i++) cout << a1[i] << " ";
	cout << endl;

	// 2
	int a2[10] = { 5, 3, 8, 1, 2, 7, 4, 9, 0, 6 };
	sortHalfArray(a2, 10);
	cout << "// 2: ";
	for (int i = 0; i < 10; i++) cout << a2[i] << " ";
	cout << endl;

	// 3
	int a3[10];
	for (int i = 0; i < 10; i++) a3[i] = rand() % 41 - 20;
	sortBetweenNegatives(a3, 10);
	cout << "// 3: ";
	for (int i = 0; i < 10; i++) cout << a3[i] << " ";
	cout << endl;

	// 4
	cout << "// 4: " << powRec(2, 5) << endl;

	// 5
	cout << "// 5: ";
	printStars(7);
	cout << endl;

	// 6
	cout << "// 6: " << sumRangeRec(3, 7) << endl;

	// 7
	int a4[100];
	for (int i = 0; i < 100; i++) a4[i] = rand() % 101 - 50;
	cout << "// 7: " << minSumPosRec(a4, 100, 10) << endl;

	// 8
	int a5[5] = { 1, 4, 7, 2, 9 };
	int a6[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int a7[3][3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				a7[i][j][k] = i + j + k;

	cout << "// 8a: " << max(a5, 5) << endl;
	cout << "// 8b: " << max(a6) << endl;
	cout << "// 8c: " << max(a7) << endl;
	cout << "// 8d: " << max(5, 9) << endl;
	cout << "// 8e: " << max(3, 7, 2) << endl;

	return 0;
}



void sortArray(int arr[], int size, bool desc)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if ((!desc && arr[i] > arr[j]) || (desc && arr[i] < arr[j]))
				swap(arr[i], arr[j]);
}

void sortHalfArray(int arr[], int size)
{
	for (int i = 1; i < size / 2; i++)
	{
		int key = arr[i], j = i - 1;
		while (j >= 0 && arr[j] < key) { arr[j + 1] = arr[j]; j--; }
		arr[j + 1] = key;
	}
	for (int i = size / 2; i < size; i++)
	{
		int key = arr[i], j = i - 1;
		while (j >= size / 2 && arr[j] > key) { arr[j + 1] = arr[j]; j--; }
		arr[j + 1] = key;
	}
}

void sortBetweenNegatives(int arr[], int size)
{
	int left = -1, right = -1;
	for (int i = 0; i < size; i++) if (arr[i] < 0) { left = i; break; }
	for (int i = size - 1; i >= 0; i--) if (arr[i] < 0) { right = i; break; }
	if (left < 0 || right < 0 || right - left <= 1) return;

	for (int i = left + 1; i < right; i++)
		for (int j = i + 1; j < right; j++)
			if (arr[i] > arr[j]) swap(arr[i], arr[j]);
}

int powRec(int base, int exp)
{
	if (exp == 0) return 1;
	return base * powRec(base, exp - 1);
}

void printStars(int n)
{
	if (n <= 0) return;
	cout << "*";
	printStars(n - 1);
}

int sumRangeRec(int a, int b)
{
	if (a > b) return 0;
	return a + sumRangeRec(a + 1, b);
}

int minSumPosRec(int arr[], int size, int seqLen)
{
	if (seqLen > size) return -1;
	int minSum = 0, minPos = 0;
	for (int i = 0; i < seqLen; i++) minSum += arr[i];
	for (int i = 1; i + seqLen <= size; i++)
	{
		int s = 0;
		for (int j = 0; j < seqLen; j++) s += arr[i + j];
		if (s < minSum) { minSum = s; minPos = i; }
	}
	return minPos;
}

int max(int arr[], int size)
{
	int m = arr[0];
	for (int i = 1; i < size; i++) if (arr[i] > m) m = arr[i];
	return m;
}

int max(int arr[3][3])
{
	int m = arr[0][0];
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (arr[i][j] > m) m = arr[i][j];
	return m;
}

int max(int arr[3][3][3])
{
	int m = arr[0][0][0];
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) if (arr[i][j][k] > m) m = arr[i][j][k];
	return m;
}

int max(int a, int b) { return (a > b) ? a : b; }
int max(int a, int b, int c) { return max(max(a, b), c); }
