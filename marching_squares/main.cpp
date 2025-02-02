#include "./include/marching_squares.hpp"

int main(){
    MarchingSquares ms;
    std::string filename = "Aberdeenshire.tif";
    float downsample_factor = 0.5f;

    result = ms.readfile(filename, downsample_factor);
    
    return 0;
}