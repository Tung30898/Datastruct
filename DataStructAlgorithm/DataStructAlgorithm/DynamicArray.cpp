#include<iostream>
#include<algorithm>

using namespace std;

void changevalue(int*& arr, int* n)
{
	int m;
	cout << "Nhap so phan tu can them vao: ";
	cin >> m;
	int* temArr = new int[*n];
	for (int i = 0; i < *n; i++)
	{
		temArr[i] = arr[i];
	}
	delete[] arr;
	*n += m;
	arr = new int[*n];
	for (int i = 0; i < *n; i++)
	{
		if (i < *n - m)
			arr[i] = temArr[i];
		else {
			cout << "Nhap vao phan tu Arr[" << i << "]: ";
			cin >> arr[i];
		}

	}
	delete[] temArr;
}
int main()
{
	int n = 0;
	cout << "Nhap vao so phan tu cua mang: ";
	cin >> n;
	int* Arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap vao phan tu Arr[" << i << "]: ";
		cin >> Arr[i];
	}
	changevalue(Arr, &n);
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << " ";
	}
	delete[] Arr;
	return 0;
}