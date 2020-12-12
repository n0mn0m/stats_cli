//
// Created by Alex on 7/7/18.
//
#include <vector>
#include <algorithm>
#include <cmath>
#include "stats.h"

int get_minimum(std::vector<int> &vec)
{
    return vec[0];
}

int get_maximum(std::vector<int> &vec)
{
    int i = vec.size() - 1;
    return vec[i];
}

int get_median(std::vector<int> &vec)
{
    auto vec_size = vec.size();

    if(vec_size % 2 == 0)
    {
       return(vec[(vec_size / 2) - 1] + vec[vec_size / 2]) / 2;
    }
    else
    {
        return vec[vec_size / 2];
    }
}

int get_average(std::vector<int> &vec)
{
    int i{};
    int sum{};

    for(i=0; i < vec.size(); i++)
    {
        sum += vec[i];
    }

    return sum / vec.size();
}

int get_variance(std::vector<int> &vec, int avg)
{
    int variance{0};
    for (int i=0; i <= (vec.size() - 1); i++)
    {
        variance += (vec[i] - avg) * (vec[i] - avg);
    }
    variance /= vec.size();
    return variance;
}

int get_sd(std::vector<int> &vec, int avg)
{
    int sum{};
    for (int i=0; i <= (vec.size() - 1); i++)
    {
        auto inter = (vec[i] - avg);
        sum += pow(inter, 2);
    }
    sum = sum / vec.size();
    return sqrt(sum);
}
