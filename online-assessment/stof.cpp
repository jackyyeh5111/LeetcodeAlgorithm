#include <iostream>
#include <cctype> // For isdigit()

#include <iostream>
#include <cctype> // For isdigit()

/* 
    This can handle user invalid input!!!
 */
bool convertToFloat(const std::string& str, double& result) {
    result = 0.0;
    double sign = 1.0;
    bool decimalPointSeen = false;
    double decimalPlace = 0.1;

    // Remove leading/trailing whitespace
    size_t start = 0;
    while (start < str.size() && std::isspace(str[start])) {
        start++;
    }
    size_t end = str.size() - 1;
    while (end > start && std::isspace(str[end])) {
        end--;
    }

    if (start > end) {
        return false; // Input is only whitespace or empty
    }

    // Handle sign
    if (str[start] == '-') {
        sign = -1.0;
        start++;
    } else if (str[start] == '+') {
        start++;
    }

    // Iterate through the string to build the number
    for (size_t i = start; i <= end; ++i) {
        if (str[i] == '.') {
            if (decimalPointSeen) {
                return false; // Multiple decimal points found
            }
            decimalPointSeen = true;
        } else if (std::isdigit(str[i])) {
            if (decimalPointSeen) {
                result += (str[i] - '0') * decimalPlace;
                decimalPlace *= 0.1;
            } else {
                result = result * 10 + (str[i] - '0');
            }
        } else {
            return false; // Non-numeric character found
        }
    }

    result *= sign;
    return true; // Successful conversion
}

int main() {
    double result;
    if (convertToFloat("123.456", result)) {
        std::cout << "Converted value: " << result << std::endl; // 123.456
    } else {
        std::cout << "Invalid input" << std::endl;
    }

    if (convertToFloat("   -789.01   ", result)) {
        std::cout << "Converted value: " << result << std::endl; // -789.01
    } else {
        std::cout << "Invalid input" << std::endl;
    }

    if (convertToFloat("abc", result)) {
        std::cout << "Converted value: " << result << std::endl;
    } else {
        std::cout << "Invalid input" << std::endl; // Invalid input
    }

    return 0;
}


/* 
    This solution cannot handle 
 */
double convertToFloat(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty");
    }

    double result = 0.0;
    double sign = 1.0;
    bool decimalPointSeen = false;
    double decimalPlace = 0.1;

    // Remove leading/trailing whitespace
    size_t start = 0;
    while (start < str.size() && std::isspace(str[start])) {
        start++;
    }
    size_t end = str.size() - 1;
    while (end > start && std::isspace(str[end])) {
        end--;
    }

    // Handle sign
    if (str[start] == '-') {
        sign = -1.0;
        start++;
    } else if (str[start] == '+') {
        start++;
    }

    // Iterate through the string to build the number
    for (size_t i = start; i <= end; ++i) {
        if (str[i] == '.') {
            if (decimalPointSeen) {
                throw std::invalid_argument("Invalid input: multiple decimal points");
            }
            decimalPointSeen = true;
        } else if (std::isdigit(str[i])) {
            if (decimalPointSeen) {
                result += (str[i] - '0') * decimalPlace;
                decimalPlace *= 0.1;
            } else {
                result = result * 10 + (str[i] - '0');
            }
        } else {
            throw std::invalid_argument("Invalid input: non-numeric character found");
        }
    }

    return result * sign;
}

int main() {
    try {
        std::cout << convertToFloat("123.456") << std::endl;    // 123.456
        std::cout << convertToFloat("   -789.01   ") << std::endl; // -789.01
        std::cout << convertToFloat("0.00123") << std::endl;    // 0.00123
        std::cout << convertToFloat("123") << std::endl;        // 123
        std::cout << convertToFloat("-.456") << std::endl;      // -0.456
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
