#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

#include "Vector.h"
#include <array>
#include <tuple>
#include <iostream>

namespace ownfos
{
    template<size_t dimension>
    class SquareMatrix
    {
    public:
        using Elements = std::array<std::array<double, dimension>, dimension>;
        using Index = size_t;

        SquareMatrix(const Elements& elements = {});

        // Creates elementary matrices
        static SquareMatrix Identity();
        static SquareMatrix Multiply(Index row, double scale); // row *= scale
        static SquareMatrix Swap(Index row1, Index row2); // swap(row1, row2)
        static SquareMatrix Add(Index row1, Index row2, double scale); // row1 += row2 * factor

        SquareMatrix operator*(const SquareMatrix& other) const;
        Vector<dimension> operator*(const Vector<dimension>& other) const;
        
        // Returns the resulting matrix and transform matrix for this operation.
        // The transform matrix of ReducedRowEchelonForm() is an inverse matrix!
        // * auto [result, transform] = matrix.ReducedRowEchelonForm();
        //   means that result == transform * matrix == identity matrix
        std::tuple<SquareMatrix, SquareMatrix> RowEchelonForm() const;
        std::tuple<SquareMatrix, SquareMatrix> ReducedRowEchelonForm() const;

        // Alternative for index operator
        double& At(size_t row, size_t column);
        double At(size_t row, size_t column) const;

        bool IsZero(size_t row, size_t column) const;

        template<size_t _dimension>
        friend std::ostream& operator<<(std::ostream& os, const SquareMatrix<_dimension>& matrix);

    private:
        // Return the index of a row where row >= rowOffset and elements[row][column] != 0
        Index NonZeroRow(Index column, Index rowOffset) const;

        Elements elements;
    };
}

#include "SquareMatrix.hpp"

#endif