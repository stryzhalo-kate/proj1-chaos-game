
#pragma once
#include <compare>
#include <string>

struct Point
{
    double x = 0.0;
    double y = 0.0;

    auto operator<=>(const Point &other) const = default;

    Point operator+(const Point &other) const;
    Point operator/(double value) const;
};

std::string toString(const Point &p);
