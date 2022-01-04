#pragma once

class GCD {
    public:
        GCD();

        double great_circle_distance(double latitude1, double longitude1, double latitude2, double longitude2);

    private:
        const double earth_radius = 6371.0;
        const double pi = 3.141592653589793;
        
        double convert_to_rad(double degrees);
};