#ifndef INTEGRATION_H
#define INTEGRATION_H
#include <functional>
#include <tuple>


class integrator{
    public:

        std::function<double(double, double)> func;

        std::tuple<std::vector<double>, std::vector<double>> euler(double x_0, dou