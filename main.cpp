#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include "integration.hpp"
#include "reader.hpp"

double function_prob1(double x_val, double y_val) {
    return y_val*y_val + 1;
}

double function_prob2(double v, double placeholder) {
    double m = 1.67e-27;
    double T = 10000;
    double k = 1.3806e-23;
    double pi = 3.1415926535;
    double factor = m/(2*k*T);
    return std::pow(factor*(1/pi), 1.5)*4*pi*v*exp(-factor*v*v);
}
// This function is all just computing and writing data. It is very long because I grossly underestimated how
// much data I would need. I'm sure there is a much cleaner way to write this in much less lines of code. 
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

    std::tuple<std::vector<double>, std::vector<double>> euler_50_1 = integ.euler(0, 2, 10, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_50_1 = integ.RK4(0, 2, 10, 0);

    std::tuple<std::vector<double>, std::vector<double>> euler_500_1 = integ.euler(0, 2, 500, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_500_1 = integ.RK4(0, 2, 500, 0);

    std::tuple<std::vector<double>, std::vector<double>> euler_500_2 = integ.euler(0, 2, 1000, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_500_2 = integ.RK4(0, 2, 1000, 0);

    write_two_column(euler_50_1, "euler_10_pts.txt");
    write_two_column(RK4_50_1, "RK4_10_pts.txt");
    write_two_column(euler_500_1, "euler_500_pts.txt");
    write_two_column(RK4_500_1, "RK4_500_pts.txt");
    write_two_column(euler_500_2, "euler_1000_pts.txt");
    write_two_column(RK4_500_2, "RK4_1000_pts.txt");


    integrator integ_prob2;
    integ_prob2.func = function_prob2;


    std::tuple<std::vector<double>, std::vector<double>> euler_50_prob2 = integ_prob2.euler(0, 4.5e4, 100, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_50_prob2 = integ_prob2.RK4(0, 4.5e4, 100, 0);

    std::tuple<std::vector<double>, std::vector<double>> euler_75_prob2 = integ_prob2.euler(0, 4.5e4, 150, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_75_prob2 = integ_prob2.RK4(0, 4.5e4, 150, 0);

    std::tuple<std::vector<double>, std::vector<double>> euler_100_prob2 = integ_prob2.euler(0, 4.5e4, 200, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_100_prob2 = integ_prob2.RK4(0, 4.5e4, 200, 0);

    write_two_column(euler_50_prob2, "euler_100_pts_prob2_1.txt");
    write_two_column(RK4_50_prob2, "RK4_100_pts_prob2_1.txt");
    write_two_column(euler_75_prob2, "euler_150_pts_prob2_1.txt");
    write_two_column(RK4_75_prob2, "RK4_150_pts_prob2_1.txt");
    write_two_column(euler_100_prob2, "euler_200_pts_prob2_1.txt");
    write_two_column(RK4_100_prob2, "RK4_200_pts_prob2_1.txt");


     std::tuple<std::vector<double>, std::vector<double>> euler_50_prob2_2 = integ_prob2.euler(0, 6e4, 100, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_50_prob2_2 = integ_prob2.RK4(0, 4.5e4, 100, 0);

    std::tuple<std::vector<double>, std::vector<double>> euler_75_prob2_2 = integ_prob2.euler(0, 6e4, 150, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_75_prob2_2 = integ_prob2.RK4(0, 6e4, 150, 0);

    std::tuple<std::vector<double>, std::vector<double>> euler_100_prob2_2 = integ_prob2.euler(0, 6e4, 200, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_100_prob2_2 = integ_prob2.RK4(0, 6e4, 200, 0);

    write_two_column(euler_50_prob2_2, "euler_100_pts_prob2_2.txt");
    write_two_column(RK4_50_prob2_2, "RK4_100_pts_prob2_2.txt");
    write_two_column(euler_75_prob2_2, "euler_150_pts_prob2_2.txt");
    write_two_column(RK4_75_prob2_2, "RK4_150_pts_prob2_2.txt");
    write_two_column(euler_100_prob2_2, "euler_200_pts_prob2_2.txt");
    write_two_column(RK4_100_prob2_2, "RK4_200_pts_prob2_2.txt");

    std::tuple<std::vector<double>, std::vector<double>> euler_50_prob2_3 = integ_prob2.euler(0, 7.5e4, 100, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_50_prob2_3 = integ_prob2.RK4(0, 7.5e4, 100, 0);

    std::tuple<std::vector<double>, std::vector<double>> euler_75_prob2_3 = integ_prob2.euler(0, 7.5e4, 150, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_75_prob2_3 = integ_prob2.RK4(0, 7.5e4, 150, 0);

    std::tuple<std::vector<double>, std::vector<double>> euler_100_prob2_3 = integ_prob2.euler(0, 7.5e4, 200, 0);
    std::tuple<std::vector<double>, std::vector<double>> RK4_100_prob2_3 = integ_prob2.RK4(0, 7.5e4, 200, 0);

    write_two_column(euler_50_prob2_3, "euler_100_pts_prob2_3.txt");
    write_two_column(RK4_50_prob2_3, "RK4_100_pts_prob2_3.txt");
    write_two_column(euler_75_prob2_3, "euler_150_pts_prob2_3.txt");
    write_two_column(RK4_75_prob2_3, "RK4_150_pts_prob2_3.txt");
    write_two_column(euler_100_prob2_3, "euler_200_pts_prob2_3.txt");
    write_two_column(RK4_100_prob2_3, "RK4_200_pts_prob2_3.txt");


}
