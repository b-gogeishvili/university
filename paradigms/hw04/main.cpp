#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <algorithm>

void inputNumbers(std::promise<std::vector<int>> p) {
    std::vector<int> numbers;
    std::cout << "Input 10 Numbers:\n";
    for (int i = 0; i < 10; ++i) {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }
    p.set_value(numbers);
}

int findMaxInRange(const std::vector<int>& numbers, int start, int end) {
    return *std::max_element(numbers.begin() + start, numbers.begin() + end);
}

void findMaxNumber(std::vector<int> numbers, std::promise<int> resultPromise) {
    int mid = numbers.size() / 2;

    auto future1 = std::async(std::launch::async, findMaxInRange, std::cref(numbers), 0, mid);
    auto future2 = std::async(std::launch::async, findMaxInRange, std::cref(numbers), mid, numbers.size());

    int max1 = future1.get();
    int max2 = future2.get();
    int finalMax = std::max(max1, max2);

    resultPromise.set_value(finalMax);
}

int main() {
    // 1. Input thread
    std::promise<std::vector<int>> inputPromise;
    std::future<std::vector<int>> inputFuture = inputPromise.get_future();
    std::thread inputThread(inputNumbers, std::move(inputPromise));

    std::vector<int> numbers = inputFuture.get();
    inputThread.join();

    // 2. Max-finding thread
    std::promise<int> maxPromise;
    std::future<int> maxFuture = maxPromise.get_future();
    std::thread maxThread(findMaxNumber, numbers, std::move(maxPromise));

    std::packaged_task<void()> task([&maxFuture]() {
        int max = maxFuture.get();
        std::cout << "Biggest Number is: " << max << std::endl;
    });

    task();

    maxThread.join();
    return 0;
}