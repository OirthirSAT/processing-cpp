#include <vector>
#include <tuple>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class MarchingSquares {
    private: 
        typedef std::vector<std::vector<std::tuple<int,int,int>>> _NUMERICAL_ARRAY;   
        typedef std::tuple<int,int> _POINT;
    public:
        MarchingSquares();

        std::pair<size_t, size_t> getShape(const _NUMERICAL_ARRAY& array);

        _NUMERICAL_ARRAY readfile(const std::string& filename, float downsample_factor);

}


