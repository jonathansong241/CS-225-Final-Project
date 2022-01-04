#include <cmath>
#include "../include/great_circle.h"

using namespace std;

GCD::GCD() {}

double GCD::convert_to_rad(double degrees) {
    return degrees * GCD::pi / 180;
}

double GCD::great_circle_distance(double latitude1, double longitude1, double latitude2, double longitude2) {
    // Bounds checking 
    if (abs(latitude1) > 90.0 || abs(latitude2) > 90.0 || abs(longitude1) > 180.0 || abs(longitude2 > 180.0)) {
        return -1;
    }

    double lat1 = convert_to_rad(latitude1);
    double long1 = convert_to_rad(longitude1);
    double lat2 = convert_to_rad(latitude2);
    double long2 = convert_to_rad(longitude2);

    double diff_long = abs(long1 - long2);


    double num1 = pow(cos(lat2)*sin(diff_long),2);
    double num2 = pow((cos(lat1) * sin(lat2)) - (sin(lat1) * cos(lat2) * cos(diff_long)), 2);
    
    double numerator = sqrt(num1 + num2);

    
    double denominator = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(diff_long);


    double delta_sigma = atan2(numerator,denominator);

    return earth_radius * delta_sigma;
}