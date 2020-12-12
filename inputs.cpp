#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <algorithm>
#include "inputs.h"
//
// Created by Alex on 7/7/18.
//


void get_list_from_user()
{
    std::cout << "How many values do you want to enter?" << std::endl;
    int usr_val_cnt{};
    std::cin >> usr_val_cnt;

    int input_cntr{1};
    std::vector<int> usr_vals{};
    usr_vals.reserve(usr_val_cnt);

    while (input_cntr <= usr_val_cnt)
    {
        int usr_val{};
        std::cout << "Please enter a value" << std::endl;
        std::cin >> usr_val;
        usr_vals.push_back(usr_val);
        input_cntr += 1;
    }

    for (auto i = usr_vals.begin(); i != usr_vals.end(); ++i)
        std::cout << *i << std::endl;
}

std::string remove_char(std::string input, char remove)
{
    input.erase(std::remove(input.begin(), input.end(), remove), input.end());
    return input;
}

int convert_string_to_int(std::string input)
{
    int cnvt_int{};
    std::stringstream convert(input);
    convert >> cnvt_int;
    return cnvt_int;
}


std::string get_ints_from_user()
{
    std::string usr_array{};
    std::cout << "Please input an array ex: [1, 2, 3, ....]" << std::endl;
    std::getline(std::cin, usr_array);
    return usr_array;
}

std::vector<int> convert_string_to_vector(std::string usr_array)
{
    usr_array = remove_char(usr_array, ' ');
    usr_array = remove_char(usr_array, '[');
    usr_array = remove_char(usr_array, ']');

    std::vector<int> usr_vals{};
    std::string accumulator{};


    for (int i = 0; i <= usr_array.size(); ++i)
    {
        if(usr_array[i] == ',')
        {
            auto cnvt_int = convert_string_to_int(accumulator);
            usr_vals.push_back(cnvt_int);
            accumulator = "";
        }
        else if(i == usr_array.size())
        {
            accumulator += usr_array[i];
            auto cnvt_int = convert_string_to_int(accumulator);
            usr_vals.push_back(cnvt_int);
        }
        else
        {
            accumulator += usr_array[i];
        }
    }

    return usr_vals;
}

