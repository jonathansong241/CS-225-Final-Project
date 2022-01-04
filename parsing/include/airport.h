#pragma once
#include <string>
#include <limits.h>
#include <utility>
#include "route.h"

using namespace std;

enum airportCSVMeanings {
    AIRPORT_ID,
    AIRPORT_NAME,
    AIRPORT_CITY,
    AIRPORT_COUNTRY,
    AIRPORT_IATA,
    AIRPORT_ICAO,
    AIRPORT_LATITUDE,
    AIRPORT_LONGITUDE
};

class Airport {
    public:
        Airport();
        Airport(int ids, double lat, double lon, string cd, string ct);

        double getLatitude(); 
        double getLongitude();
        string getCode();
        string getCity();
        int getID();

        void setLatitude(double lat);
        void setLongitude(double lon);
        void setID(int ids);
        void setCode(string cd);
    

    private:
        int id_;
        double latitude_;
        double longitude_;
        string code_;
        string city_;
      
};
