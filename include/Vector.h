#ifndef VECTOR_H
#define VECTOR_H

#include <array>
#include <iostream>

namespace ownfos
{
    template<size_t dimension>
    class Vector
    {
    public:
        using Elements = std::array<double, dimension>;
        using Index = size_t;
        
        Vector(const Elements& elements = {});

        double& operator[](Index index);
        double operator[](Index index) const;

        template<size_t _dimension>
        friend std::ostream& operator<<(std::ostream& os, const Vector<_dimension>& vector);

    private:
        Elements elements;
    };
}

#include "Vector.hpp"

#endif