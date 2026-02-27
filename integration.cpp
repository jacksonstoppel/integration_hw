#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include "integration.hpp"


std::tuple<std::vector<double>, std::vector<double>> integrator::euler(double x_0, double b, double num_points, double initial_y) {
    double step = (x_0 - b)/num_points;
    double x_val = x_0;
    std::vector<double> derv_vals;
    std::vector<double> x_vals;
    double y_old = initial_y;
    derv_vals.push_back(y_old);
     x_vals.push_back(x_0);
    while (x_val <= b) {
        double y_new = y_