#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>

namespace ownfos
{
    class Vector
    {
    public:
        Vector() = default;

        Vector(const std::vector<double>& data);
        Vector(const std::initializer_list<double>& data);

        Vector(const Vector&) = default;
        Vector(Vector&&) noexcept = default;
        
        ~Vector() = default;

        Vector& operator=(const Vector&) = default;
        Vector& operator=(Vector&&) noexcept = default;

        Vector& operator/=(double factor);
        Vector& operator-=(const Vector& other);

        Vector operator*(double factor) const;
        Vector operator/(double factor) const;
        Vector operator-(const Vector& other) const;

        double& operator[](size_t index);
        double operator[](size_t index) const;

        friend std::ostream& operator<<(std::ostream& os, const Vector& vector);

        void Resize(size_t length);

    private:
        std::vector<double> data;
    };
}

#endif