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
    _2D_Array image(2,std::vector<float>(4,0.0f));
    std::vector<_POINT> black_list;
    std::vector<_POINT> white_list;

    auto shape = getShape(image);
    size_t x = shape.first - 1;
    size_t y = shape.second - 1;

    std::cout << "Shape of array is (" << x << "," << y << ")" << std::endl; 
    return 0;
}