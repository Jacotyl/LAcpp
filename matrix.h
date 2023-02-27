#ifndef MATRIX_H
#define MATRIX_H
#include <string>
#include <vector>
#include <iostream>

class Matrix
{
public:
    Matrix(); //default constructor

    Matrix(std::vector<std::vector<int>> field); //constructor

    void setField(std::vector<std::vector<int>> field);

    void setElement(int value, int column, int row);

    std::vector<std::vector<int>> getField() const;

    int getElement(int column, int row) const;

    int getColumnSize() const; //get size of column

    int getRowSize() const; //get size of row

    int trace();

    void transpose();

    void printMatrix() const;



private:
    
    std::vector<std::vector<int>> field;
    int size[2];

};

Matrix operator+(const Matrix& left, const Matrix& right);
Matrix operator+(const int left, const Matrix& right);
Matrix operator+(const Matrix& left, const int right);

Matrix operator*(const Matrix& left, const Matrix& right);
Matrix operator*(const int left, const Matrix& right);
Matrix operator*(const Matrix& left, const int right);

Matrix operator-(const Matrix& left, const Matrix& right);

#endif

