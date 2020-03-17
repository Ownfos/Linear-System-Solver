#ifndef LINEAR_SYSTEM_H
#define LINEAR_SYSTEM_H

#include "Vector.h"

namespace ownfos
{
    using AugmentedMatrix = std::vector<Vector>;

    // Represents a collection of linear equations
    // You can get the solution for this system by LinearSystem::Solve()
    class LinearSystem
    {
    public:
        LinearSystem() = default;

        LinearSystem(const AugmentedMatrix& matrix);

        LinearSystem(const LinearSystem&) = default;
        LinearSystem(LinearSystem&&) noexcept = default;

        ~LinearSystem() noexcept = default;

        LinearSystem& operator=(const LinearSystem&) = default;
        LinearSystem& operator=(LinearSystem&&) noexcept = default;

        friend std::ostream& operator<<(std::ostream& os, const LinearSystem& system);

        // Calculate the solution for this linear system.
        // This function is non-const (it changes augmented matrix)
        Vector Solve();

    private:
        AugmentedMatrix matrix;
    };
}


#endif