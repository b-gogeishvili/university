#ifndef PARFUNC_HH
#define PARFUNC_HH

#include <functional>

class ParFunc {
private:
    std::function<double(double, double*)> function_;
    int param_count_;
    double* parameters_;

public:
    ParFunc(std::function<double(double, double*)> func, int param_count);
    ParFunc(const ParFunc& other);
    ParFunc& operator=(const ParFunc& other);
    ~ParFunc();
    double operator()(double x);
    void SetParameters(const double* params);
    double Integrate(double min, double max, double epsilon = 1e-8);
    
private:
    double IntegratePartial(double min, double max, double epsilon);
};

#endif