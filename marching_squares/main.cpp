#include "./include/marching_squares.hpp"

int main(){
    MarchingSquares ms;
    std::string filename = "Aberdeenshire.tif";
    float downsample_factor = 0.5f;
    
    cv::Mat result = ms.readfile(filename, downsample_factor);
    std::tuple<float, cv::Mat> otsu = ms._otsu_segmentation(result);
    
    return 0;
}