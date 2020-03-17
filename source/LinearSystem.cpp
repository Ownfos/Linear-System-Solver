#include "LinearSystem.h"
#include "Utility.h"

namespace ownfos
{
    LinearSystem::LinearSystem(const AugmentedMatrix& matrix)
        : matrix(matrix)
    {}

    std::ostream& operator<<(std::ostream& os, const LinearSystem& system)
    {
        for(const auto& row : system.matrix)
            os << row << std::endl;

        return os;
    }

    Vector LinearSystem::Solve()
    {
        auto dimension = matrix.size();

        for(auto row = 0; row < dimension; ++row)
        {
            // Make the element on the main diagonal of the augmented matrix
            // non-zero by swapping rows, then scale it to 1.0
            for(auto lookupRow = row + 1; lookupRow < dimension && IsZero(matrix[row][row]); ++lookupRow)
            {
                if(!IsZero(matrix[lookupRow][row]))
                    std::swap(matrix[row], matrix[lookupRow]);
            }
            matrix[row] /= matrix[row][row];
            
            // Subtract current row from all other rows below it
            // to make reduced row echelon form
            for(auto otherRow = row + 1; otherRow < dimension; ++otherRow)
                matrix[otherRow] -= matrix[row] * matrix[otherRow][row];
        }

        // Subtract current row from all other rows above it (from bottom to top)
        // to make all elements become 0 above the main diagonal
        // (except the last column of the matrix, which is the solution)
        for(int row = dimension - 1; row >= 0; --row)
        {
            for(int otherRow = row - 1; otherRow >= 0; --otherRow)
                matrix[otherRow] -= matrix[row] * matrix[otherRow][row];
        }

        // Return solution of each variable (last element in each row)
        std::vector<double> result;

        for(const auto& row : matrix)
            result.push_back(row[dimension]);

        return result;
    }
}