#include <iostream>
#include <vector>
#include <algorithm>

long long int MaxPairwiseProduct(std::vector<long long int>& numbers) {
    long long int max_product = 0;
    long long int n = numbers.size();

    std::sort(numbers.begin(), numbers.end());
    max_product = numbers[numbers.size() - 1] * numbers[numbers.size() - 2];

    return max_product;
}

int main() {
    long long int n;
    std::cin >> n;
    std::vector<long long int> numbers(n);
    for (long long int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
