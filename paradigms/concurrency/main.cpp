#include <iostream>
#include <future>
#include <thread>
#include <string>

void out(std::future<std::string> &f) {
    std::string value = f.get();

    std::cout << value << "\n";
}

void in(std::promise<std::string> &p) {
    std::cout << "Enter value: ";
    std::string input;
    std::cin >> input;

    p.set_value(input);
}

int main() {
    std::promise<std::string> prom;
    std::future<std::string> fut = prom.get_future();

    std::thread th1(out, ref(fut));
    std::thread th2(in, ref(prom));

    th1.join();
    th2.join();
}