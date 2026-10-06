// chaos_game.h
#pragma once

#include <cstddef>
#include <random>
#include <vector>

#include "point.h"

// Звичайний вказівник на функцію замість важкого std::function
using Transform = Point (*)(const Point &base, const Point &z);

Transform halfwayTransform();

class ChaosGame
{
public:
    ChaosGame(const Point &start, std::vector<Point> bases, Transform transform = halfwayTransform());
    Point operator()();

private:
    Point current_;
    std::vector<Point> bases_;
    Transform transform_;
    std::mt19937 engine_;
    std::uniform_int_distribution<std::size_t> pick_;
};