#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include "integration.hpp"
#include "reader.hpp"

double function_prob1(double x_val, double y_val) {
    return y_val*y_val + 1;
}

int main() {
    integrator integ;

    integ.func = function_prob1;

    std::tuple<std::vector<double>, std::vector<double>> euler_50 = integ.euler(0, 2, 50, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_50 = integ.RK4(0, 2, 50, 0);

    std::tuple<std::vector<double>, std::vector<double>> euler_75 = integ.euler(0, 2, 75, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_75 = integ.RK4(0, 2, 75, 0);

    std::tuple<std::vector<double>, std::vector<double>> euler_100 = integ.euler(0, 2, 100, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_100 = integ.RK4(0, 2, 100, 0);

    write_two_column(euler_50, "euler_50_pts.txt");
    write_two_column(RK4_50, "RK4_50_pts.txt");
    write_two_column(euler_75, "euler_75_pts.txt");
    write_two_column(RK4_75, "RK4_75_pts.txt");
    write_two_column(euler_100, "euler_100_pts.txt");
    write_two_column(RK4_100, "RK4_100_pts.txt");
}
