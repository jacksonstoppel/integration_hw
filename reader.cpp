#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <stdexcept>
#include <algorithm>

// Define a container for x and y
struct xy_data {
    std::vector<double> x;
    std::vector<double> y;
};

// Define a function that will read data
xy_data read_data(const std::string& filename, 
                bool strict=false,
                char comment_char = '#',
                bool allow_inline_comment = true,
                bool allow_comment_as_seperators = true) 
{
    //Check file can be opened
    std::ifstream in(filename);
    if (!in) {
        throw std::runtime_error("Could not open file" + filename);
    };
    //Create variables for line and line number
    xy_data data;
    std::string line;
    std::size_t line_no=0;

    //Iterate through lines
    while (std::getline(in, line)) {
        ++line_no;

        // The following if statements clean the text file up and prevent unecessary error with special characters/comments
        if (allow_comment_as_seperators) {
            std::replace(line.begin(), line.end(), ',', ' ');
        };

        if (allow_inline_comment) {
            auto pos = line.find(comment_char);
            if (pos != std::string::npos) line.erase();
        };

        if (line.find_first_not_of(" \t\r\n") == std::string::npos) continue; 
        
        {
            auto first = line.find_first_not_of(" \t\r\n");
            if (first != std::string::npos && line[first] == comment_char) continue;
        }

        // Print the data to the vectors
        std::istringstream iss(line);
        double xv, yv;

        if (iss >> xv >> yv) {
            data.x.push_back(xv);
            data.y.push_back(yv);
        } else if (strict) {
            throw std::runtime_error(
                "Parse error in " + filename + " at line " + std::to_string(line_no) +
                ": expected at least two numeric columns.");
        }
    }

    return data;
}

// This function will write data to a text file. 
// Note: This function writes the data in one column, seperated by a title, not in two columns as the function name eludes to. 
void write_two_column(
        const std::tuple<std::vector<double>, std::vector<double>>& t, 
        const std::string& filename) {

    const auto& a = std::get<0>(t);
    const auto& b = std::get<1>(t);

    std::ofstream out(filename);
    if (!out) throw std::runtime_error("Could not open file: " + filename);
    
    out << "# vector x\n";
    for (double v : a) out << v << '\n';

    out << "\n# vector y\n";
    for (double v : b) out << v << '\n';
}