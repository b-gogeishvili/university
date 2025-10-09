#include "ParFunc.hh"
#include <iostream>
#include <cmath>
#include <iomanip>

double gaussian_function(double x, double* parameters) {
    double A = parameters[0];
    double mu = parameters[1];
    double sigma = parameters[2];
    
    double exponent = -0.5 * pow((x - mu) / sigma, 2);
    return A * exp(exponent);
}

int main() {
    std::cout << std::fixed << std::setprecision(6);
    
    ParFunc gauss_func(gaussian_function, 3);
    
    double parameters[3] = {1.0, 0.0, 1.0};
    gauss_func.SetParameters(parameters);
    
    std::cout << "=== Gaussian Function Testing ===" << std::endl;
    
    std::cout << "Function values:" << std::endl;
    double test_points[] = {-3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0};
    int num_points = sizeof(test_points) / sizeof(test_points[0]);
    
    for (int i = 0; i < num_points; i++) {
        double x = test_points[i];
        double value = gauss_func(x);
        std::cout << "f(" << x << ") = " << value << std::endl;
    }
    
    std::cout << std::endl;
    
    std::cout << "=== Integration Calculation ===" << std::endl;
    std::cout << "Interval: [-10, 10]" << std::endl;
    
    double epsilons[] = {1e-4, 1e-5, 1e-6};
    int num_epsilons = sizeof(epsilons) / sizeof(epsilons[0]);
    
    for (int i = 0; i < num_epsilons; i++) {
        double eps = epsilons[i];
        std::cout << "\nepsilon = " << eps << std::endl;
        
        double integral = gauss_func.Integrate(-10.0, 10.0, eps);        
        
        std::cout << "Integral = " << integral << std::endl;
    }
    
    return 0;
}