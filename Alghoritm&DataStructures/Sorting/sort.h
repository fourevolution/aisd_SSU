#pragma once

#include <cstdlib>
#include <array>

const int N = 10000;
void selectionSort(std::array<int, N> &arr, const int n);
void bubbleSort(std::array<int, N> &arr, const int n);
void insertionSort(std::array<int, N>& arr, const int n);
int partition(std::array<int, N>& arr, int low, int high);
void quickSort(std::array<int, N>& arr, int low, int high);
void change(int& a, int& b);
