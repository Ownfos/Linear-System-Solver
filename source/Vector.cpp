#include "Vector.h"

namespace ownfos
{
    Vector::Vector(const std::vector<double>& data)
        : data(data)
    {}
    
    Vector::Vector(const std::initializer_list<double>& data)
        : data(data)
    {}

    Vector& Vector::operator/=(double factor)
    {
        for(auto& element : data)
            element /= factor;

        return *this;
    }

    Vector& Vector::operator-=(const Vector& other)
    {
        for(auto i = 0; i < data.size(); ++i)
            data[i] -= other.data[i];

        return *this;
    }

    Vector Vector::operator*(double factor) const
    {
        std::vector<double> result;

        for(auto element : data)
            result.push_back(element * factor);

        return result;
    }

    Vector Vector::operator/(double factor) const
    {
        std::vector<double> result;

        for(auto element : data)
            result.push_back(element / factor);

        return result;
    }

    Vector Vector::operator-(const Vector& other) const
    {
        std::vector<double> result;

        for(auto i = 0; i < data.size(); ++i)
            result.push_back(data[i] - other.data[i]);

        return result;
    }

    double& Vector::operator[](size_t index)
    {
        return data[index];
    }

    double Vector::operator[](size_t index) const
    {
        return data[index];
    }

    std::ostream& operator<<(std::ostream& os, const Vector& vector)
    {
        for(auto element : vector.data)
            os << element << " ";
        
        return os;
    }

    void Vector::Resize(size_t length)
    {
        data.resize(length);
    }
}