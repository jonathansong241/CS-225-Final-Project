#include <string>
#include <limits.h>
#include "../include/airport.h"

using std::string;

Airport::Airport() {
    id_ = -1;
    latitude_ = -1;
    longitude_ = -1;
    code_ = "";
    city_ = "";
}

Airport::Airport(int ids, double lat, double lon, string cd, string ct) {
    id_ = ids;
    latitude_ = lat;
    longitude_ = lon;
    code_ = cd;
    city_ = ct;
}

double Airport::getLatitude() {
    return latitude_;
}

double Airport::getLongitude() {
    return longitude_;
}

string Airport::getCode() {
    return code_;
}

string Airport::getCity() {
    return city_;
}

int Airport::getID() {
    return id_;
}

void Airport::setLatitude(double lat) {
    latitude_ = lat;
}

void Airport::setLongitude(double lon) {
    longitude_ = lon;
}

void Airport::setID(int ids) {
    id_ = ids;
}
void Airport::setCode(string cd) {
    code_ = cd;
}
    