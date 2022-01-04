#include <string>
#include <limits.h>
#include "../include/route.h"

using std::string;

//  Constructor without given dist
Route::Route(string o, string de) {
    origin = o;
    dest = de;
    dist = -1;
}


//  Constructor with given dist
Route::Route(string o, string de, double di) {
    origin = o;
    dest = de;
    dist = di;
}

//  origin getter
string Route::getOrigin() {
    return origin;
}

//  destination getter
string Route::getDest() {
    return dest;
}

//  dist getter
double Route::getDist() {
    return dist;
}

//  dist setter
void Route::setDist(double di) {
    dist = di;
}

//  compares dist of 2 edges
bool Route::operator<<(const Route& other) const {
    return dist < other.dist;
}

bool Route::operator==(Route& other) const {
    if (origin != other.origin)
        return false;
    if (dest != other.dest)
        return false;
    return true;
}
