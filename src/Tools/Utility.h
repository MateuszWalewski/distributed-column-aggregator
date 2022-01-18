#pragma once

#include <vector>
#include <iostream>

template <typename T>
void PrintVector(std::vector<T> container, const std::string & label )
{
    for ( auto & x : container )
    {
        std::cout << label << ": " << x << std::endl;
    }


}