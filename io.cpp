#include "io.h"

#include <cmath>
#include <fstream>
#include <stdexcept>

namespace
{
    void checkFinite(const Point &p, const char *what)
    {
        if (!std::isfinite(p.x) || !std::isfinite(p.y))
            throw std::runtime_error(std::string(what) + ": coordinates must be finite numbers");
    }
}

Input readInput(const std::string &path)
{
    std::ifstream in(path);
    if (!in)
        throw std::runtime_error("failed to open input file \"" + path + "\"");

    Input result;

    long long n = 0;
    if (!(in >> n) || n <= 0)
        throw std::runtime_error("n must be a natural number");
    result.n = static_cast<std::size_t>(n);

    if (!(in >> result.start.x >> result.start.y))
        throw std::runtime_error("failed to read the starting point");
    checkFinite(result.start, "starting point");

    Point b;
    while (in >> b.x)
    {
        if (!(in >> b.y))
            throw std::runtime_error("base point is incomplete (missing y-coordinate)");
        checkFinite(b, "base point");
        result.bases.push_back(b);
    }

    if (result.bases.empty())
        throw std::runtime_error("the file has no base points");

    if (!in.eof())
        throw std::runtime_error("invalid data after the base points");

    return result;
}

void writeOutput(const std::string &path, const std::vector<Point> &points)
{
    std::ofstream out(path);
    if (!out)
        throw std::runtime_error("failed to create output file \"" + path + "\"");

    for (const Point &p : points)
        out << toString(p) << '\n';

    if (!out)
        throw std::runtime_error("failed to write to file \"" + path + "\"");
}