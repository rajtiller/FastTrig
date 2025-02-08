#include "trig_tester.h"
#include <cmath>
#include <random>

bool checkDifference(double x, double y, double offset)
{
    return abs(x - y) < offset;
}

int main(int argc, char **argv)
{

    Approximations a;

    // std::cout << std::atan2(1, -0.9) << "\n";
    // std::cout << a.atan2(1, -0.9) << "\n";

    double maxDifference = 0;
    double maxDiffX = 0;
    double maxDiffY = 0;

    for (double i = -1; i < 1; i += 0.01)
    {
        for (double j = -1; j < 1; j += 0.01)
        {

            if (!checkDifference(std::atan2(i, j), a.atan2(i, j), 0.01) && abs(i-0) > 0.0000001 && abs(j-0) > 0.000001)
            {
                //     std::cout << "WRONG TIME\n";
                //     std::cout << i << " " << j << "\n";

                if (abs(std::atan2(i, j) - a.atan2(i, j)) > maxDifference)
                {
                    maxDifference = abs(std::atan2(i, j) - a.atan2(i, j));
                    maxDiffX = i;
                    maxDiffY = j;
                }
            }
        }
    }

    std::cout << "X: " << maxDiffX << ", Y: " << maxDiffY << "\n";
    std::cout << std::atan2(maxDiffX, maxDiffY) << " " << a.atan2(maxDiffX, maxDiffY) << "\n";
    std::cout << maxDifference << "\n";

    // std::cout << "start\n";
    // int for_loop = 100000000000;
    // std::random_device rd;
    // std::mt19937 gen(rd());

    // // Create a distribution (uniform real numbers between 0.0 and 1.0)
    // std::uniform_real_distribution<> dist(-1.0, 1.0);
    // if (std::atoi(argv[1]) == 0)
    // {
    //     std::cout << "XXX0";
    //     for (int i = 0; i < for_loop; i++)
    //     {
    //         double x = dist(gen);
    //         double y = dist(gen);
    //         if (x != 0 && y != 0)
    //         {
    //             double z = std::atan2(x, y); // does the fact that these are doubles cause issues?
    //         }
    //     }
    // }
    // else if (std::atoi(argv[1]) == 1)
    // {
    //     std::cout << "XXX1";
    //     Approximations a;
    //     for (int i = 0; i < for_loop; i++)
    //     {
    //         double x = dist(gen);
    //         double y = dist(gen);
    //         if (x != 0 && y != 0)
    //         {
    //             double z = a.atan2(x, y); // does the fact that these are doubles cause issues?
    //         }
    //     }
    // }
}