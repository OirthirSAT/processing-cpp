#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace cv;

#define NDSI_THRESHOLD 0.3 // NDSI is a float ranging from -1 to 1
#define BRIGHTNESS_THRESHOLD 0.4 // Brightness ranges from 0 to 1
#define MAX_VAL 65565
#define EPSILON 0.00001

class CloudMask {
    public:
        static cv::Mat createCloudMask(std::vector<cv::Mat> channels) {
            // Mask selects pixels to remove

            // Assuming channels are in the order R, G, B, NIR
            cv::Mat brightness = (channels[0] + channels[1] + channels[2] + channels[3]) / 4; // Load brightness into channel[0]
            int brightnessThreshold = BRIGHTNESS_THRESHOLD * 65565;
            threshold(brightness, brightness, brightnessThreshold, MAX_VAL, cv::THRESH_BINARY); // Convert brightness to mask (select brightnesses above threshold: pixels that could be cloud or snow) and store to channels[0]
            
            // Normalised Difference Snow Index (NDSI)
            cv::Mat1f green = channels[1];
            cv::Mat1f nir = channels[3];

            cv::Mat1f ndsi_float = (green-nir)/(green+nir+EPSILON);

            cv::Mat ndsi;
            ndsi_float += 1; // Add one to offset to 0-2
            ndsi_float.convertTo(ndsi, CV_16U, 32768); // Scale to 0-65535

            int ndsiThreshold = (NDSI_THRESHOLD + 1.0) * 32768.0; // Scale to 0-65535
            
            cv::threshold(ndsi, ndsi, ndsiThreshold, MAX_VAL, cv::THRESH_BINARY_INV); // Convert NDSI to mask (select NDSIs below a certain value: pixels that are not snow)

            cv::Mat result;
            cv::Mat mask;
            result = brightness & ndsi; // Store mask into channel[2]: select bright pixels that aren't snow
            
            result.convertTo(mask, CV_16U);

            return mask;
        }

        static cv::Mat applyCloudMask(std::vector<cv::Mat> channels, cv::Mat mask) {
            // Takes a mask which selects pixels to remove.
            for (int i=0; i<4; i++) {
                channels[i] &= ~mask;
            }
            cv::Mat maskedImg;
            cv::merge(channels, maskedImg);

            cv::imwrite("mask.tiff", mask);
            return maskedImg;
        }

        static void main(const std::string& imagePath, const std::string& outputPath) {
            std::cout << "Performing Cloud Mask\n";

            std::cout << "Reading image:\n";
            cv::Mat img = cv::imread(imagePath, cv::IMREAD_UNCHANGED);
            std::cout << "Read image with "+std::to_string(img.channels())+" channels." << "\n";
            std::vector<cv::Mat> channels;
            cv::split(img, channels);
            
            std::cout << "Creating Cloud Mask\n";
            cv::Mat cloudMask = createCloudMask(channels);

            std::cout << "Applying Cloud Mask\n";
            cv::Mat maskedImage = CloudMask::applyCloudMask(channels, cloudMask);

            std::cout << "Writing to "+outputPath+"\n";
            cv::imwrite(outputPath, maskedImage);

            std::cout << "Done Cloud Mask.\n";
        }
};

// Testing code - should generate a file, CarlisleMasked.tiff
// int main() {
//     CloudMask::main("Carlisle.tiff", "CarlisleMasked.tiff");
// }