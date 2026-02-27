#include "MatrixIterator.h"
#include "Matrix.h"
#include <exception>
using namespace std;

MatrixIterator::MatrixIterator(const Matrix& m)
    : matrix(m), currentPos(0), currentColumn(0)
{
    while (currentColumn < matrix.nrColumns() && matrix.columns[currentColumn] == matrix.columns[currentColumn+1])
    {
        currentColumn++;
    }
}

void MatrixIterator::first() {
    currentPos = 0;
    currentColumn = 0;
    while (currentColumn < matrix.nrColumns() && matrix.columns[currentColumn] == matrix.columns[currentColumn+1])
    {
        currentColumn++;
    }
}

void MatrixIterator::next() {
    if (currentPos >= matrix.size)
        throw std::exception();

   currentPos++;

}

