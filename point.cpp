
#include "point.h"
#include <format>
#include <functional>

Point Point::operator+(const Point &other) const
{
    std::plus<double> add;
    return {add(x, other.x), add(y, other.y)};
}

Point Point::operator/(double value) const
{
    return {x / value, y / value};
}

std::string toString(const Point &p)
{
    return std::format("{} {}", p.x, p.y);
}
