#ifndef MATRIXITERATOR_H
#define MATRIXITERATOR_H

typedef int TElem;

class Matrix;

class MatrixIterator {
    friend class Matrix;
private:
    const Matrix& matrix;
    int currentPos;

    int currentColumn;

    MatrixIterator(const Matrix& m);


public:
    void first();
    void next();

};




#endif //MATRIXITERATOR_H
