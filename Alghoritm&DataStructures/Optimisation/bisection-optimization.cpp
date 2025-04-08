#include <iostream>

float f_c(const float x) {
    return (x + 1) * (x + 1) + (1 - x) * (1 - x) * (1 - x);
}

float bisection(float (*f)(float), const float eps,
                      const float d, float a, float b) {
    float mid = (a + b) / 2;
    while ((b - a) > eps) {
        std::cout << "a: " << a << " | b: " << b << "\n";
        mid = (a + b) / 2;
        float e = fabs(0.131 - mid);
        if (f(mid - d) > f(mid + d)) {
            a = mid - d;
        }
        else {
            b = mid + d;
        }
        std::cout << e << '\n';
        
    }
    float xt = (a + b) / 2;
    return xt;
}

int main() {
    std::cout << "res: " << bisection(f_c, 0.001, 0.0001, -2, 1);
}
