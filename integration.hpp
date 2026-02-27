#ifndef INTEGRATION_H
#define INTEGRATION_H
#include <functional>
#include <tuple>


class integrator{
    public:

        std::function<double(double, double)> func;

        std::tuple<std::vector<double>, std::vector<double>> euler(double x_0, double b, double num_points, double initial_y);

        std::tuple<std::vector<double>, std::vector<double>> RK4(double x_0, double b, double num_points, double initial_y);

};

#endif