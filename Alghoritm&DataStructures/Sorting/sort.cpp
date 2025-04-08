#include "sort.h"
#include <iostream>

void change(int& a, int& b) {
	int buf = a;
	a = b;
	b = buf;
}

void selectionSort(std::array<int, N>& arr, int n) {
	for (int i = 0; i < n; i++) {
		int min = arr[i];
		int iMin = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < min) {
				min = arr[j];
				iMin = j;
			}
		}
		change(arr[i], arr[iMin]);
	}
	return;
}

void bubbleSort(std::array<int, N> &arr, const int n) {
	int len = n;
	while (len != 0) {
		int maxIndex = 0;
		for (int i = 1; i < len; i++) {
			if (arr[i] < arr[i - 1]) {
				change(arr[i], arr[i - 1]);
				maxIndex = i;
			}
		}
		len = maxIndex;
	}
}

void insertionSort(std::array<int, N>& arr, const int n) {
	for (int i = 1; i < n; i++) {
		int sorted = i - 1;
		while (sorted > -1 && arr[sorted] > arr[sorted + 1]) {
			change(arr[sorted], arr[sorted + 1]);
			sorted--;
		}
	}
}

int partition(std::array<int, N>& arr, int low, int high) {
	int pivot = arr[(low + high) / 2];
	while (low <= high) {
		while (arr[low] < pivot)
			low++;
		while (arr[high] > pivot) 
			high--;
		if (low <= high) {
			change(arr[low], arr[high]);
			low++;
			high--;
		}
	}
	return low;
}

void quickSort(std::array<int, N> &arr, int low, int high) {
	if (low >= high) return;
	int pi = partition(arr, low, high);
	quickSort(arr, low, pi - 1);
	quickSort(arr, pi, high);
}