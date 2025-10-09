#include <iostream>
#include <vector>
#include <thread>
#include <future>

void inputNumbers(std::promise<std::vector<int>> p) {
    std::vector<int> numbers;
    int n;

    std::cout << "Enter 10 whole numbers:\n";
    for (int i = 0; i < 10; ++i) {
        std::cin >> n;
        numbers.push_back(n);
    }

    p.set_value(numbers);
}

int findMaxParallel(const std::vector<int>& numbers) {
    auto mid = numbers.begin() + numbers.size() / 2;

    auto future1 = std::async(std::launch::async, [&numbers, mid]() {
        int maxVal = *numbers.begin();
        for (auto it = numbers.begin() + 1; it != mid; ++it) {
            if (*it > maxVal) maxVal = *it;
        }
        return maxVal;
    });

    auto future2 = std::async(std::launch::async, [&numbers, mid]() {
        int maxVal = *mid;
        for (auto it = mid + 1; it != numbers.end(); ++it) {
            if (*it > maxVal) maxVal = *it;
        }
        return maxVal;
    });

    int max1 = future1.get();
    int max2 = future2.get();

    return (max1 > max2) ? max1 : max2;
}

void processNumbers(std::future<std::vector<int>> f, std::promise<int> resultPromise) {
    std::vector<int> numbers = f.get();
    int maxVal = findMaxParallel(numbers);
    resultPromise.set_value(maxVal);
}

int main() {
    std::promise<std::vector<int>> inputPromise;
    std::future<std::vector<int>> inputFuture = inputPromise.get_future();

    std::promise<int> resultPromise;
    std::future<int> resultFuture = resultPromise.get_future();

    std::thread inputThread(inputNumbers, std::move(inputPromise));

    std::thread processThread(processNumbers, std::move(inputFuture), std::move(resultPromise));

    std::packaged_task<void()> task([&]() {
        int finalResult = resultFuture.get();
        std::cout << "Biggest number: " << finalResult << std::endl;
    });

    task();

    inputThread.join();
    processThread.join();

    return 0;
}
