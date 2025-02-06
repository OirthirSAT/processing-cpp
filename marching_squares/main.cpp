#include "./include/marching_squares.hpp"

int main(){
    MarchingSquares ms;
    std::string filename = "Aberdeenshire.tif";
    float downsample_factor = 0.5f;
    
    cv::Mat result = ms.readfile(filename, downsample_factor);
    std::tuple<float, cv::Mat> otsu = ms._otsu_segmentation(result);
    std::tuple<std::map<_POINT, bool>, int, int> tup = ms._point_array(std::get<1>(otsu))
    
    return 0;
}