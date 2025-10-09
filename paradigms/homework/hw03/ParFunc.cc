#include "ParFunc.hh"
#include <thread>
#include <mutex>
#include <vector>

ParFunc::ParFunc(std::function<double(double, double*)> func, int param_count) 
    : function_(func), param_count_(param_count) {
    parameters_ = new double[param_count_];
    for (int i = 0; i < param_count_; i++) {
        parameters_[i] = 0.0;
    }
}

ParFunc::ParFunc(const ParFunc& other) 
    : function_(other.function_), param_count_(other.param_count_) {
    parameters_ = new double[param_count_];
    for (int i = 0; i < param_count_; i++) {
        parameters_[i] = other.parameters_[i];
    }
}

ParFunc& ParFunc::operator=(const ParFunc& other) {
    if (this != &other) {
        delete[] parameters_;
        
        function_ = other.function_;
        param_count_ = other.param_count_;
        parameters_ = new double[param_count_];
        for (int i = 0; i < param_count_; i++) {
            parameters_[i] = other.parameters_[i];
        }
    }
    return *this;
}

ParFunc::~ParFunc() {
    delete[] parameters_;
}

double ParFunc::operator()(double x) {
    return function_(x, parameters_);
}

void ParFunc::SetParameters(const double* params) {
    for (int i = 0; i < param_count_; i++) {
        parameters_[i] = params[i];
    }
}

double ParFunc::IntegratePartial(double min, double max, double epsilon) {
    double integral = 0.0;
    for (double x = min; x < max; x += epsilon) {
        integral += function_(x, parameters_) * epsilon;
    }
    return integral;
}

double ParFunc::Integrate(double min, double max, double epsilon) {
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) {
        num_threads = 4;
    }
    
    double interval_size = (max - min) / num_threads;
    
    std::vector<double> results(num_threads, 0.0);
    std::vector<std::thread> threads;
    std::mutex result_mutex;
    
    for (unsigned int i = 0; i < num_threads; i++) {
        double start = min + i * interval_size;
        double end = (i == num_threads - 1) ? max : start + interval_size;
        
        threads.emplace_back([this, i, start, end, epsilon, &results, &result_mutex]() {
            double partial_result = this->IntegratePartial(start, end, epsilon);
            
            std::lock_guard<std::mutex> lock(result_mutex);
            results[i] = partial_result;
        });
    }
    
    for (auto& thread : threads) {
        thread.join();
    }
    
    double total_integral = 0.0;
    for (const double& result : results) {
        total_integral += result;
    }
    
    return total_integral;
}