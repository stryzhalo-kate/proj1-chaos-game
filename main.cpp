// Програмний проєкт 1, задача 1.
// Компілятор: GCC 13 (g++ -std=c++23). Precompiled header не використовується.

#include <iostream>
#include <string>
#include <vector>
#include "chaos_game.h"
#include "io.h"

int main(int argc, char *argv[])
{
    const std::string inPath = argc > 1 ? argv[1] : "input.txt";
    const std::string outPath = argc > 2 ? argv[2] : "output.txt";

    try
    {
        const Input input = readInput(inPath);
        ChaosGame game(input.start, input.bases);

        std::vector<Point> points;
        points.reserve(input.n);
        for (std::size_t i = 0; i < input.n; ++i)
            points.push_back(game());

        writeOutput(outPath, points);
    }

    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}