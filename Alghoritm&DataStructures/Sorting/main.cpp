#include <iostream>

#include <ctime>
#include "sort.h"

// GEN 10k els, work with mini-diap (100, 200, 5000)

int main()
{
	srand(10);
	const int n = 10000;
	//const int n = N;
	std::array<int, N> a;
		
	// FILL ARRAY
	for (int i = 0; i < a.size(); i++) {
		a[i] = rand();
	}

	// SHOW FILLED ARRAY
	/*std::cout << "\t - - - - - - - - FILLED - - - - - - - - - \n";
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}*/
	
	//selectionSort(a, n);

	//bubbleSort(a, n);

	//insertionSort(a, n);
	
	for (int i = 0; i <= a.size(); i += 100) {
		std::clock_t tStart = clock();
		quickSort(a, 0, i-1);
		std::cout << "" << i << " " << (clock() - tStart) << "\n";
	}
	
	// SHOW SORTED ARRAY
	/*std::cout << "\n\t - - - - - - - - SORTED - - - - - - - - - \n";
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}*/
}
