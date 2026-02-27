#include "Matrix.h"
#include <exception>
#include <tuple>

using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {

	this->lines = nrLines;
	this->cols = nrCols;
	this->capacity = 5;
	this->size = 0;
	this->values = new TElem[this->capacity];
	this->rows = new int[this->capacity];
	this->columns = new int[nrCols + 1];

    for (int j = 0; j <= nrCols; j++) {
        this->columns[j] = 0;
    }
}

//Θ(1)
int Matrix::nrLines() const {
	return this->lines;
}

//Θ(1)
int Matrix::nrColumns() const {
	return this->cols;
}


TElem Matrix::element(int i, int j) const {
	//Θ(1)
	if (i < 0 || i >= this->lines || j < 0 || j >= this->cols)
		throw std::exception();

	int colStart = this->columns[j];
	int colEnd = this->columns[j + 1];

    //Best case: Θ(1), Worst Case: Θ(m), unde m=nr de elemente != 0 din coloana, Average Case: Θ(1)
	for (int k = colStart; k < colEnd; k++) {
		if (this->rows[k] == i)
			return this->values[k];
	}

	return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
// Θ(1)
    if (i < 0 || i >= this->lines || j < 0 || j >= this->cols)
        throw std::exception();

    int colStart = this->columns[j];
    int colEnd = this->columns[j + 1];

    //Best case: Θ(1), Worst case: Θ(k), unde k = nr de elemente != 0 din coloana, Average: Θ(1)
    int pos = colStart;
    while (pos < colEnd && this->rows[pos] != i)
        pos++;

    // 1: exista element pe poz i, j
    //Θ(1)
    if (pos < colEnd && this->rows[pos] == i) {
        TElem oldValue = this->values[pos];
        //Θ(1)
        if (e != NULL_TELEM) {
            this->values[pos] = e;
        }
        else {
            //Best Case: Θ(1), daca este ultimul element din array, worst case: Θ(n), daca este primul element din array
            //Average case: O(n)
            for (int k = pos; k < this->size - 1; k++) {
                this->values[k] = this->values[k + 1];
                this->rows[k] = this->rows[k + 1];
            }
            this->size--;
            //Best case: Θ(1), daca e in ultima coloana, Worst case: Θ(nrCols), daca este in prima coloana
            //Average case: O(nrCols)
            for (int col = j + 1; col <= this->cols; col++) {
                this->columns[col]--;
            }
        }
        return oldValue;
    }

    else {
        // Θ(1)
        TElem oldValue = NULL_TELEM;
        if (e == NULL_TELEM) {
            return oldValue;
        }
        //Best case: Θ(1), Worst case: Θ(k), unde k = nr de elemente != 0 din coloana, Average: Θ(1)
        pos = colStart;
        while (pos < colEnd && this->rows[pos] < i)
            pos++;

        // Worst case: Θ(n), n = nr de elem, Best Case: Θ(1)
        if (this->size == this->capacity) {
            int newCapacity = this->capacity * 2;
            TElem* newValues = new TElem[newCapacity];
            int* newRows = new int[newCapacity];
            for (int k = 0; k < this->size; k++) {
                newValues[k] = this->values[k];
                newRows[k] = this->rows[k];
            }
            delete[] this->values;
            delete[] this->rows;
            this->values = newValues;
            this->rows = newRows;
            this->capacity = newCapacity;
        }
        // Worst case: Θ(n), daca este primul element, Best case: Θ(1) daca este ultimul element
        for (int k = this->size; k > pos; k--) {
            this->values[k] = this->values[k - 1];
            this->rows[k] = this->rows[k - 1];
        }
        // Θ(1)
        this->values[pos] = e;
        this->rows[pos] = i;
        this->size++;

        //Worst Case: Θ(nrCols), best case: Θ(1)
        for (int col = j + 1; col <= this->cols; col++) {
            this->columns[col]++;
        }
        return oldValue;
    }
}


Matrix::~Matrix() {
    delete[] this->values;
    delete[] this->rows;
    delete[] this->columns;
}


