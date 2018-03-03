#include<iostream>
#include<Windows.h>
#include<vector>

using namespace std;

int find_dup(int numbers[], int length) {

	for (int i = 0; i<length; i++) {

		int index = numbers[i];

		if (index >= length) {

			index -= length;

		}

		if (numbers[index] >= length) {

			return index;

		}

		numbers[index] = numbers[index] + length;

	}

	return -1;

}

void Test()
{
	int arr[] = { 1, 3, 4, 1, 2 };
	find_dup(arr, 5);

	system("pause");
}