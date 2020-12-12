//
// Created by Alex on 7/7/18.
//

#include <iostream>
#include "sort.h"


void swap(std::vector<int> &vec, int i, int j)
{
    int lcl = vec[i];
    vec[i] = vec[j];
    vec[j] = lcl;
}

void quick_sort(std::vector<int> &vec, int left, int right)
{

    int index_right{right};
    int index_left{left};
    int mid_point{};
    int pivot{};

    mid_point = left + (right - left) / 2;
    pivot = vec[mid_point];

    while(index_left < right || index_right > left)
    {
        while(vec[index_left] < pivot)
        {
            index_left++;
        }
        while(vec[index_right] > pivot)
        {
            index_right--;
        }
        if(index_left <= index_right)
        {
            swap(vec, index_left, index_right);
            index_left++;
            index_right--;
        }
        else
        {
            if(index_left < right)
                quick_sort(vec, index_left, right);
            if(index_right > left)
                quick_sort(vec, left, index_right);
            return;
        }

    }
}

void print_vec(std::vector<int> &vec)
{
    for (auto i = vec.begin(); i != vec.end(); ++i)
        std::cout << *i << std::endl;
}
