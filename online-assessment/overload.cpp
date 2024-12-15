#include <iostream>
#include <vector>
#include <stdexcept>  // For standard exceptions
using namespace std;
struct Data {
    int x, y;
    static int n_init;
    Data(int x, int y) : x(x), y(y) {
        n_init++;
    }
    Data operator+(const Data& other) const{
        return {x + other.x, y + other.y};
    }
    int operator+(int num) {
        return num;
    }
};
std::ostream& operator<<(std::ostream& stream, const Data& other) {
    stream << "(" << other.x  << ", "  << other.y << ")";
    return stream;
}

int Data::n_init = 0;

int main() {
    Data d1{1, 2};
    Data d2{3, 4};
    cout << d1 << '\n'; // 100
    cout << (d1 + 100) << '\n'; // 100
    cout << (d1 + d2).x << '\n'; // 4
    cout << "n_copy: " << Data::n_init << '\n';
}
