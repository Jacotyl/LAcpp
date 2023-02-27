#include <cstddef>
#include <iostream>
#include <vector>
#include "matrix.h"

using namespace std;

Matrix::Matrix()
{
    size[0] = 0;
    size[1] = 0;
}

Matrix::Matrix(vector<vector<int>> field)
{
    this->field = field;
    this->size[0] = field[0].size(); //set column size
    this->size[1] = field[1].size(); //set row size
}

void Matrix::setField(std::vector<std::vector<int>> field)
{
    this->field = field;
}

void Matrix::setElement(int value, int column, int row)
{
    field[column][row] = value;
}

std::vector<std::vector<int>> Matrix::getField() const
{
    return field;
}

int Matrix::getElement(int column, int row) const
{
    return field[column][row];
}

int Matrix::getColumnSize() const 
{
    return size[0];
}

int Matrix::getRowSize() const
{
    return size[1];
}





int Matrix::trace()
{
    if(size[0] != size[1]) {
        throw "Matrix is not square!";
    }
    else {
        int trace = 0;
        for(int i = 0; i < size[0]; i++) {
            trace += field[i][i];
        }
        return trace;
    }
    
}

void Matrix::transpose()
{
    if(size[0] != size[1]) {
        throw "Matrix is not square!";
    }
    else {
        Matrix result;
        for(int i = 0; i < size[0]; i++) {
            for(int j = 0; j< size[1]; j++) {
                result.field[i][j] = field[j][i];
            }
        }
        field = result.field;
    }
}

void Matrix::printMatrix() const
{
    for (int i = 0; i < size[1]; i++) {     //NOTE: size[x] ranges are swapped here due to how matrcies are col, row and not row, col
        for (int j = 0; j < size[0]; j++) {
            //cout << "printing...\n";
            printf("%3d", field[i][j]);
        }
        cout << "\n";
    }
}

Matrix operator+(const Matrix& left, const Matrix& right) { //adding two matrices together
    if(left.getColumnSize() != right.getColumnSize() || left.getRowSize() != right.getRowSize())
    {
        cout << "Matrices are not of same size, cannot add! Returning left matrix!" << "\n";
        return left;
    }
    else {
        std::vector<std::vector<int>> result(left.getColumnSize(), (std::vector<int>(left.getRowSize())));
        for(int i = 0; i < left.getColumnSize(); i++)
        {
            for(int j = 0; j< left.getRowSize(); j++)
            {
               result[i][j] = right.getElement(i, j) + left.getElement(i, j);
            }
        }
        Matrix* final = new Matrix(result);
        return *final;
    }
}

Matrix operator+(const int left, const Matrix& right) { //adding scalar and matrix
        std::vector<std::vector<int>> result(right.getColumnSize(), (std::vector<int>(right.getRowSize())));
        for(int i = 0; i < right.getColumnSize(); i++)
        {
            for(int j = 0; j< right.getRowSize(); j++)
            {
               result[i][j] = left + right.getElement(i, j);
            }
        }
        Matrix* final = new Matrix(result);
        return *final;
}

Matrix operator+(const Matrix& left, const int right) { //adding matrix and scalar
        std::vector<std::vector<int>> result(left.getColumnSize(), (std::vector<int>(left.getRowSize())));
        for(int i = 0; i < left.getColumnSize(); i++)
        {
            for(int j = 0; j< left.getRowSize(); j++)
            {
               result[i][j] = right + left.getElement(i, j);
            }
        }
        Matrix* final = new Matrix(result);
        return *final;
}




Matrix operator-(const Matrix& left, const Matrix& right) {
    if(left.getColumnSize() != right.getColumnSize() || left.getRowSize() != right.getRowSize())
    {
        cout << "Matrices are not of same size, cannot subtract! Returning left matrix!" << "\n";
        return left;
    }
    else {
        std::vector<std::vector<int>> result(left.getColumnSize(), (std::vector<int>(left.getRowSize())));
        for(int i = 0; i < left.getColumnSize(); i++)
        {
            for(int j = 0; j< left.getRowSize(); j++)
            {
               result[i][j] = left.getElement(i, j) - right.getElement(i, j);
            }
        }
        Matrix* final = new Matrix(result);
        return *final;
    }
}

Matrix operator*(const Matrix& left, const Matrix& right) {
    if(left.getColumnSize() != right.getColumnSize() && left.getRowSize() != right.getRowSize())
    {
        cout << "Matrices are not of same size, cannot multiply! Returning left matrix" << "\n";
        return left;
    }
    else {
        std::vector<std::vector<int>> result(left.getColumnSize(), std::vector<int> (left.getRowSize()));
        for (int i = 0; i < left.getRowSize(); i++) {
            for (int j = 0; j < right.getColumnSize(); j++) {
                result[i][j] = 0;

                for (int k = 0; k < right.getRowSize(); k++) {
                    result[i][j] += left.getElement(i, k) * right.getElement(k, j);
                }

            }
        }
        Matrix* final = new Matrix(result);
        return *final;
    }   
}
Matrix operator*(const int left, const Matrix& right) {
    std::vector<std::vector<int>> result(right.getColumnSize(), std::vector<int> (right.getRowSize()));
    for(int i = 0; i < right.getColumnSize(); i++) {
        for (int j = 0; j < right.getRowSize(); j++) {
            result[i][j] = left * right.getElement(i, j);
        }
    }
    Matrix* final = new Matrix(result);
    return *final;
}   


Matrix operator*(const Matrix& left, const int right) {
    std::vector<std::vector<int>> result(left.getColumnSize(), std::vector<int> (left.getRowSize()));
    for(int i = 0; i < left.getColumnSize(); i++) {
        for (int j = 0; j < left.getRowSize(); j++) {
            result[i][j] *= right;
        }
    }
    Matrix* final = new Matrix(result);
    return *final;
}
