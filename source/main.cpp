// Overview:
// - This problem finds a solution for linear system (only if it exists)
//   using Gauss-Jordan elimination
//
// Input:
// - Augmented matrix(2D array [dimension][dimension + 1])
// - Example)
//   1  1  3  0
//   2  3 -1  9
//   3 -2  3 -4
//
// * This input represents these equations:
//    x +  y + 3z =  0
//   2x + 3y -  z =  9
//   3x - 2y + 3z = -4
//
// Output:
// - Solution of this system in sequence (for instance, 1 2 -1 for the example given above)
//
// Limits:
// - LinearSystem's initializer with AugmentedMatrix as parameter will not check if its size is valid
// - Vector's arithmatic operators will not check if other vector's size is equal with itself
// - This program assumes that given linear system has exactly one solution
//   In cases where number of solution is infinite or zero is not handled properly

#include "LinearSystem.h"

using namespace ownfos;

int main()
{
    LinearSystem system({
        {1,  1,  3,  0},
        {2,  3, -1,  9},
        {3, -2,  3, -4}
    });

    std::cout << "Initial state\n";
    std::cout << system << "\n";

    std::cout << "Solution\n";
    std::cout << system.Solve() << "\n\n";

    std::cout << "Resulting state\n";
    std::cout << system << "\n";
}