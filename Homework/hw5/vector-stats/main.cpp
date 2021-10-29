// vector-stats
// Bernard Laughlin 10/29/2021
// HW5 for cs201
// Write a function that finds the smallest and largest elements of a vector argument and also
// computes the mean and median. Return the min, max, mean and median using a struct. Do
// not use global variables. For testing purposes, write a main program that calls this function with
// at least 5 different vectors
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

struct Stats {
    double min;
    double max;
    double median;
    double mean;
};

// Returns min, max, median, and mean of a vector
Stats GetStats(const vector<double> & input){
    Stats results;
    // get min
    results.min = input.at(0);
    for (const auto & i : input){
        if (i < results.min) results.min = i;
    }

    // get max
    results.max = input.at(0);
    for (const auto & i : input){
        if (i > results.max) results.max = i;
    }

    // get mean
    double sum = 0;
    for (const auto & i : input){
        sum += i;
    }
    results.mean = sum / input.size();

    // get median
    results.median = input.at(input.size()/2);

    return results;
}

// prints mean, median, min, and max from vector
void PrintResults(const vector<double> & input){
    Stats x = GetStats(input);
    cout << "Min: " << x.min << endl;
    cout << "Max: " << x.max << endl;
    cout << "Mean: " << x.mean << endl;
    cout << "Median: " << x.median << endl;
}

int main() {
    vector<double> a {1,2,3,4,5,800};
    PrintResults(a);
    return 0;
}
