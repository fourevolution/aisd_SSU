#include <iostream>
#include <vector>
#include <fstream>


float f_c(const float x) {
	return (x + 1) * (x + 1) + (1 - x) * (1 - x) * (1 - x);
}

float linearFind(float(*f)(float), const float a, const float b, const int N) {
	std::vector<float> fs;	
	float x;
	for (int i = 0; i < N; i++) {
		x = a + ((b - a) * i) / (N + 1);
		fs.push_back(f(x));
	}

	int im = 0;
	float min = fs.at(im);

	for (int i = 1; i < N; i++) {
		if (min > fs.at(i)) {
			min = fs.at(i);
			im = i;
		}
	}
	float xt = a + ((b - a) * float(im)) / (N + 1);
	return xt;
}

void calcDiffLinearFind(float(*f)(float),
		float xReal,
		std::string filename,
		int start, int end, int step,
		float a, float b) 
{	
	std::fstream file;
	file.open(filename, std::ios::out);
	if (!file.is_open()) {
		std::cout << "Error. File cant't open\n";
		file.close();
	}
	for (start; start <= end; start += step) {
		file << start << " " << fabs(xReal - linearFind(f, a, b, start)) << '\n';
	}
	std::cout << "Results saved in " << filename << "\n";
	file.close();
}

int main() {
	calcDiffLinearFind(f_c, 0.131, "results.txt", 100, 10000, 100, -2.0, 1.0);
	return 0;
}