#include "ScalarConverter.hpp"

static double set_value(const std::string& literal) {
    double value;
    if (literal == "nan" || literal == "nanf")
        value = std::numeric_limits<double>::quiet_NaN();
    else if (literal == "+inf" || literal == "+inff")
        value = std::numeric_limits<double>::infinity();
    else if (literal == "-inf" || literal == "-inff")
        value = -std::numeric_limits<double>::infinity();
    else if (literal.length() == 1 && !std::isdigit(literal[0]))
        value = static_cast<double>(literal[0]);
    else
        value = std::strtod(literal.c_str(), nullptr);
    return value;
}

void ScalarConverter::convert(const std::string& literal) {
	// 
    const double value = set_value(literal);
    const bool isInt = std::floor(value) == value;
    const uint8_t precision = isInt ? 1 : 6;

    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127) {
        std::cout << "impossible";
    }
    else if (!std::isprint(static_cast<char>(value))) {
        std::cout << "Non displayable";
    }
    else {
        std::cout << "'" << static_cast<char>(value) << "'";
    }
    std::cout << std::endl;


    std::cout << "int: ";
    if (std::isnan(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
        std::cout << "impossible";
    }
    else {
        std::cout << static_cast<int>(value);
    }
    std::cout << std::endl;


    std::cout << "float: ";
    std::cout << std::fixed << std::setprecision(precision);
    std::cout << static_cast<float>(value) << 'f' << std::endl;


    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(precision);
    std::cout << value  << std::endl;
}