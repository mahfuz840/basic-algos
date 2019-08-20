#include<bits/stdc++.h>
using namespace std;

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int left, int mid, int right);


int main()
{
	int n = 5;
	int arr[] = {5, 4, 3, 2, 1};

	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	mergeSort(arr, 0, n-1);

	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void mergeSort(int arr[], int low, int high)
{
	if(low < high)
	{
		int mid = (low+(high-1))/2;

		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);

		merge(arr, low, mid, high);
	}
}

void merge(int arr[], int left, int mid, int high)
{
	int leftSize = mid-left+1;
	int rightSize = high - mid;

	int leftArray[leftSize], rightArray[rightSize];

	for(int i = 0; i < leftSize; i++)
		leftArray[i] = arr[left+i];
	for(int i = 0; i < rightSize; i++)
		rightArray[i] = arr[mid+1+i];

	int i = 0;
	int j = 0;
	int k = left;
	while(i < leftSize && j < rightSize)
	{
		if(leftArray[i] <= rightArray[j])
		{
			arr[k] = leftArray[i];
			i++;
		}
		else
		{
			arr[k] = rightArray[j];
			j++;
		}

		k++;
	}

	while(i < leftSize)
	{
		arr[k] = leftArray[i];
		i++;
		k++;
	}
	while(j < rightSize)
	{
		arr[k] = rightArray[j];
		j++;
		k++;
	}
}
