#include "include/marching_squares.hpp"
#include <iostream>
#include <optional>
#include <opencv2/opencv.hpp>

int main(){
    std::cout << "Program started" << std::endl;
    MarchingSquares ms;
    std::string filename = "Aberdeenshire.tif";
    float downsample_factor = 0.5f;
    
    cv::Mat image = ms._readfile(filename, downsample_factor);
    if (image.empty()) {
        std::cerr << "Failed to read the image" <<  std::endl;
        return 1;
    }
    
    _2D_Array segmented = ms._otsu_segmentation(image);
    
    auto [state_dict , x , y] = ms._point_array(segmented);
    
    auto vectors = ms._list_vectors(state_dict , x , y);    
    
    auto shapes = ms._vector_shapes(vectors);
    
    ms._show_coastline(image,shapes);
    std::cout<< "worked?" << std::endl;
    return 0;
}