#pragma once
/* DESCRIPTION:
This class offers method to find lines in an image, using different image processing methods.
However, all are based on the hough line transform, but the images are preprocessed differently.
At the end, the algorithm should return only two lines.
*/
#include <cv.h>
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include <vector>

using namespace cv;

class LineDetector
{
  public:
  // PUBLIC MEMBER METHODS.
  // DONE: Standard constructor.
  LineDetector();
  // DONE: Standard destructor.
  ~LineDetector();
  // DONE: Set a new original image.
  void setImage(Mat &new_image);
  // DONE: Define all parameters: ROI-Cropping corners, two default lines (original coordinates),...
  void setParams(Point2f roi_left_top, Point2f roi_right_bottom, Vec2f default_left, Vec2f default_right);
  // DONE: Does the Hough-Transform and draws the lines.
  void houghTransform(Mat &contours, Mat &draw_to, vector<Vec2f> &lines_hT, int threshold);
  // Function which returns ALL lines in the original coordinate system.
  vector<Vec2f> getAllLinesOrig();
  // Function which returns ALL lines in the cropped coordinate system.
  vector<Vec2f> getAllLinesCrop();
  // DONE: Method which deletes the lines vectors.
  void clearLines();
  
  // PUBLIC MEMBER VARIABLES.


  private:
  // PRIVATE MEMBER METHODS.
  // Line finding methods:
  // DONE: ???
  vector<Vec2f> HoughClassic (Mat &src_HC);
  // DONE: ???
  vector<Vec2f> InRange (Mat src_IR);
  // DONE: ???
  vector<Vec2f> GrayProperty (Mat src_GP);
  // DONE: ???
  vector<Vec2f> CompareGray (Mat src_CG);

  // Helper methods:
  // DONE: ???
  Mat showChannel(Mat RGB, bool B, bool G, bool R);
  // DONE: ???
  Mat RoadThreshold(Mat src_RT);
  // DONE: ???
  Vec3b IntensityOfArea(Mat &src_IOA, int x_gray, int y_gray, int width_gray, int height_gray);
  // DONE: ???
  Mat FindGray(Mat src_FG);
  // Method which transforms rho and theta from cropped image (ROI) to original image.
  Vec2f polarParamCrop2Orig(Vec2f polar_param_crop);
  // Method which transforms rho and theta from original image to cropped image (ROI).
  Vec2f polarParamOrig2Crop(Vec2f polar_param_orig);
  // Method which transforms a point coordinate from original to cropped image.
  Point2f coordinateOrig2Crop(Point2f coord_orig);
  // Method which transforms a point coordinate from cropped to original image.
  Point2f coordinateCrop2Orig(Point2f coord_crop);
  // Function which does all kind of line detections for a given image and returns the lines.
  vector<Vec2f> getAllLines(Mat &color_image);
  // Draws lines to an image (both have to have the same coordinate system!) by getting a vector with (rho, theta).
  void drawLines2Image(Mat &draw_to, vector<Vec2f> lines_to_draw);

  // PRIVATE MEMBER VARIABLES.
  // Store parameters of two default lines left/right (original coordinates) --> Needed for resetting.
  vector<Vec2f> default_lines_;
  // Store coordinates of cropped image (top left and bottom right corner) in original coordinates.
  vector<Point2f> cropping_corners_;
  // Store original color image.
  cv::Mat original_; 
  // Store cropped color image (from original).
  cv::Mat cropped_;

  // Store all of the detected lines in the original coordinate system.
  vector<Vec2f> all_lines_orig_;
  // Store all of the detected lines in the cropped coordinate system.
  vector<Vec2f> all_lines_cropped_;

};