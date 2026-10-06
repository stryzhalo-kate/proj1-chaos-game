#include "chaos_game.h"

#include <stdexcept>
#include <utility>

Transform halfwayTransform()
{

    return [](const Point &base, const Point &z)
    {
        return (base + z) / 2.0;
    };
}

namespace
{
    std::uniform_int_distribution<std::size_t> makePicker(const std::vector<Point> &bases)
    {
        if (bases.empty())
            throw std::invalid_argument("there are no basic point");
        return std::uniform_int_distribution<std::size_t>(0, bases.size() - 1);
    }
}

ChaosGame::ChaosGame(const Point &start, std::vector<Point> bases, Transform transform)
    : current_(start),
      bases_(std::move(bases)),
      transform_(transform),
      engine_(std::random_device{}()),
      pick_(makePicker(bases_))
{
}

Point ChaosGame::operator()()
{
    const std::size_t i = pick_(engine_);
    current_ = transform_(bases_.at(i), current_);
    return current_;
}