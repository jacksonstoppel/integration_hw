#pragma once
#include <string>
#include <vector>

// Simple container for (x, y) data
struct xy_data {
    std::vector<double> x;
    std::vector<double> y;
};

// Reads a text file
xy_data read_data(const std::string& filename, 
                bool strict=false,
                char comment_char = '#',
                bool allow_inline_comment = true,
                bool allow_comment_as_seperators = true);

void write_two_column(
        const std::tuple<std::vector<double>, std::vector<double>>& t, 
        const std::string& filename);