#include "Vector.h"

namespace ownfos
{
    template<size_t dimension>
    Vector<dimension>::Vector(const Elements& elements)
        : elements(elements)
    {}

    template<size_t dimension>
    double& Vector<dimension>::operator[](Index index)
    {
        return elements[index];
    }

    template<size_t dimension>
    double Vector<dimension>::operator[](Index index) const
    {
        return elements[index];
    }

    
    template<size_t _dimension>
    std::ostream& operator<<(std::ostream& os, const Vector<_dimension>& vector)
    {
        for(auto e : vector.elements)
            os << e << " ";
        return os;
    }
}