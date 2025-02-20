#include <vector>
#include <variant>
#include <iostream>
#include <tuple>

typedef std::tuple<int,int> _POINT;
typedef std::vector<std::vector<float>> _2D_Array;

std::pair<size_t,size_t> getShape(const _2D_Array& array) {
    size_t rows = array.size();
    size_t cols = rows > 0 ? array[0].size() : 0;
    return {rows,cols};
}
int main() {

    std::cout << "Shape of array is 2" << std::endl; 
    return 0;
}