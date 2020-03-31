#include "SquareMatrix.h"
#include <cmath>

namespace ownfos
{
    template<size_t dimension>
    SquareMatrix<dimension>::SquareMatrix(const Elements& elements)
        : elements(elements)
    {}

    template<size_t dimension>
    SquareMatrix<dimension> SquareMatrix<dimension>::Identity()
    {
        SquareMatrix matrix;
        for(auto i=0; i<dimension; ++i)
            matrix.elements[i][i] = 1.0;
        return matrix;
    }

    template<size_t dimension>
    SquareMatrix<dimension> SquareMatrix<dimension>::Multiply(size_t row, double factor)
    {
        SquareMatrix matrix;
        for(auto i=0; i<dimension; ++i)
            matrix.elements[i][i] = i == row ? factor : 1.0;
        return matrix;
    }

    template<size_t dimension>
    SquareMatrix<dimension> SquareMatrix<dimension>::Swap(size_t row1, size_t row2)
    {
        SquareMatrix matrix;
        for(auto i=0; i<dimension; ++i)
            matrix.elements[i][i] = (i != row1 && i != row2) ? 1.0 : 0.0;
        matrix.elements[row1][row2] = matrix.elements[row2][row1] = 1.0;
        return matrix;
    }

    template<size_t dimension>
    SquareMatrix<dimension> SquareMatrix<dimension>::Add(size_t row1, size_t row2, double factor)
    {
        SquareMatrix matrix = Identity();
        matrix.elements[row1][row2] = factor;
        return matrix;
    }

    template<size_t dimension>
    SquareMatrix<dimension> SquareMatrix<dimension>::operator*(const SquareMatrix& other) const
    {
        SquareMatrix result;
        for(auto row = 0; row < dimension; ++row)
            for(auto column = 0; column < dimension; ++column)
                for(auto i = 0; i < dimension; ++i)
                    result.elements[row][column] += elements[row][i] * other.elements[i][column];
        return result;
    }

    template<size_t dimension>
    Vector<dimension> SquareMatrix<dimension>::operator*(const Vector<dimension>& other) const
    {
        Vector<dimension> result;
        for(auto i = 0; i < dimension; ++i)
            for(auto j = 0; j < dimension; ++j)
                result[i] += other[j] * At(i, j);
        return result;
    }

    template<size_t dimension>
    std::tuple<SquareMatrix<dimension>, SquareMatrix<dimension>> SquareMatrix<dimension>::RowEchelonForm() const
    {
        auto result = SquareMatrix(elements);
        auto transform = Identity();

        for(auto row = 0; row < dimension; ++row)
        {
            // Make sure the main diagonal is non-zero
            {
                auto swap = Swap(row, NonZeroRow(row, row));
                result = swap * result;
                transform = swap * transform;
            }
            
            // Scale leading value to one
            {
                auto mul = Multiply(row, 1 / result.At(row, row));
                result = mul * result;
                transform = mul * transform;
            }

            // Eliminate lower values below leading one
            for(auto otherRow = row + 1; otherRow < dimension; ++otherRow)
            {
                auto add = Add(otherRow, row, -result.At(otherRow, row));
                result = add * result;
                transform = add * transform;
            }
        }

        return { result, transform };
    }

    template<size_t dimension>
    std::tuple<SquareMatrix<dimension>, SquareMatrix<dimension>> SquareMatrix<dimension>::ReducedRowEchelonForm() const
    {
        auto [result, transform] = RowEchelonForm();

        // Eliminate upper values above leading one
        for(int row = dimension - 1; row >= 0; --row)
        {
            for(int otherRow = row - 1; otherRow >= 0; --otherRow)
            {
                auto add = Add(otherRow, row, -result.At(otherRow, row));
                result = add * result;
                transform = add * transform;
            }
        }

        return { result, transform };
    }

    template<size_t dimension>

    size_t SquareMatrix<dimension>::NonZeroRow(Index column,  Index rowOffset) const
    {
        for(auto row = rowOffset; row < dimension; ++row)
            if(!IsZero(row, column))
                return row;
    }

    template<size_t dimension>
    double& SquareMatrix<dimension>::At(size_t row, size_t column)
    {
        return elements[row][column];
    }

    template<size_t dimension>
    double SquareMatrix<dimension>::At(size_t row, size_t column) const
    {
        return elements[row][column];
    }

    template<size_t dimension>
    bool SquareMatrix<dimension>::IsZero(size_t row, size_t column) const
    {
        return std::fabs(elements[row][column]) < 0.00001;
    }

    template<size_t dimension>
    std::ostream& operator<<(std::ostream& os, const SquareMatrix<dimension>& matrix)
    {
        for(auto row = 0; row < dimension; ++row)
        {
            for(auto column = 0; column < dimension; ++column)
                os << matrix.elements[row][column] << " ";
            os << "\n";
        }
        return os;
    }
}