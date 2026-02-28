#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include "integration.hpp"


std::tuple<std::vector<double>, std::vector<double>> integrator::euler(double x_0, double b, double num_points, double initial_y) {
    double step = std::abs(x_0 - b)/num_points;
    double x_val = x_0;
    std::vector<double> derv_vals;
    std::vector<double> x_vals;
    double y_old = initial_y;
    derv_vals.push_back(y_old);
     x_vals.push_back(x_0);
    while (x_val <= b) {
        double y_new = y_old + step*func(x_val, y_old);
        derv_vals.push_back(y_new);
        y_old = y_new;
        x_val += step;
        x_vals.push_back(x_val);

    }
    return std::make_tuple(std::move(x_vals), std::move(derv_vals));

}

std::tuple<std::vector<double>, std::vector<double>> integrator::RK4(double x_0, double b, double num_points, double initial_y) {
    double step = std::abs(x_0 - b)/num_points;
    double x_val = x_0;
    std::vector<double> derv_vals;
    std::vector<double> x_vals;
    double y_old = initial_y;
    derv_vals.push_back(y_old);
    x_vals.push_back(x_0);
    while (x_val <= b) {
        double k_1 = func(x_val, y_old);
        double k_2 = func(x_val + 0.5*step, y_old + 0.5*step*k_1);
        double k_3 = func(x_val + 0.5*step, y_old + 0.5*step*k_2);
        double k_4 = func(x_val + step, y_old + step*k_3);
        double y_new = y_old + step*(k_1 + 2*k_2 + 2*k_3 + k_4)/6;
        derv_vals.push_back(y_new);
        x_val += step;
        x_vals.push_back(x_val);
        y_old = y_new;
    }
    return std::make_tuple(std::move(x_vals), std::move(derv_vals));

}
