
#include <iostream>
#include <string>
#include <vector>
#include "inputs.h"
#include "sort.h"
#include "stats.h"

int main(int argc, char* argv[])
{
    std::vector<int> vals;

    if (argv[1] != NULL)
    {
        std::string input_array = argv[1];
        vals = convert_string_to_vector(input_array);
    }
    else
    {
        auto usr_array = get_ints_from_user();
        vals = convert_string_to_vector(usr_array);
    }

    quick_sort(vals, 0, vals.size()-1);
    auto min = get_minimum(vals);
    auto max = get_maximum(vals);
    auto median = get_median(vals);
    auto average = get_average(vals);
    auto variance = get_variance(vals, average);
    auto sd = get_sd(vals, average);
    std::cout << "The minimum value is " << min << std::endl;
    std::cout << "The maximum value is " << max << std::endl;
    std::cout << "The median value is " << median << std::endl;
    std::cout << "The average value is " << average << std::endl;
    std::cout << "The variance is " << variance << std::endl;
    std::cout << "The standard deviation is " << sd << std::endl;
    print_vec(vals);

    return 0;
}
