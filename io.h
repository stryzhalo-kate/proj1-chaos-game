// io.h
#pragma once

#include <cstddef>
#include <string>
#include <vector>

#include "point.h"

struct Input
{
    std::size_t n = 0;
    Point start;
    std::vector<Point> bases;
};

Input readInput(const std::string &path);
void writeOutput(const std::string &path, const std::vector<Point> &points);