#include<iostream>
#include <vector>
#include"matrix.h"


int main()
{
    std::cout << "starting test run" << "\n";

    std::vector<std::vector<int>> values1 = {{1,2}, {3,4}};
    std::vector<std::vector<int>> values2 = {{5,6}, {7,8}};

    std::cout << "Creating matrices..." << "\n";
    Matrix* first = new Matrix(values1);
    Matrix* second = new Matrix(values2);


    std::cout << first->getColumnSize() << "\n";
    std::cout << first->getRowSize() << "\n";
    std::cout << second->getColumnSize() << "\n";
    std::cout << second->getRowSize() << "\n";

    Matrix third = *first * *second;
    third.printMatrix();
    
    third = *first + *second;
    third.printMatrix();

    third = *first - *second;
    third.printMatrix();

    third = 2 + *first;
    third.printMatrix();

    third = 2 * *first;
    third.printMatrix();

    /*
    std::cout << "Inverse Testing: " << "\n";
    first->transpose();
    first->printMatrix();
    */
    return 0;
}