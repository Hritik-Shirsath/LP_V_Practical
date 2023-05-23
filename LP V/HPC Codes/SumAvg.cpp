#include <iostream>
#include <vector>
#include <omp.h>

double parallelSum(const std::vector<double>& arr) {
    double sum = 0.0;

    #pragma omp parallel for reduction(+: sum)
    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
    }

    return sum;
}

double parallelAverage(const std::vector<double>& arr) {
    double sum = parallelSum(arr);
    return sum / arr.size();
}

int main() {
    std::vector<double> arr = {9.0, 4.0, 2.0, 7.0, 5.0, 1.0, 8.0, 3.0, 6.0};

    double sum = parallelSum(arr);
    double average = parallelAverage(arr);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;

    return 0;
}
