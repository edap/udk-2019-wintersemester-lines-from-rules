#include "Quadtree.h"

Quadtree::Quadtree() {
    capacity = 1;
    hasChildren = false;
    minX = 0;
    maxX = 0;
    minY = 0;
    maxY = 0;
}

Quadtree::Quadtree(float min_x, float max_x, float min_y, float max_y, int _capacity){
    capacity = _capacity;
    hasChildren = false;
    minX = min_x;
    maxX = max_x;
    minY = min_y;
    maxY = max_y;
    findMidpoints();
}

Quadtree::~Quadtree() {
    if (hasChildren) {
        delete northwest;
        delete northeast;
        delete southwest;
        delete southeast;
    }
}

void Quadtree::findMidpoints() {
    midX = (minX + maxX)/2;
    midY = (minY + maxY)/2;
}

void Quadtree::add(ofPoint& point) {
    if (hasChildren) {
        if (point.x < midX) {
            if (point.y < midY) {
                northwest->add(point);
            } else {
                southwest->add(point);
            }
        } else {
            if (point.y < midY) {
                northeast->add(point);
            } else {
                southeast->add(point);
            }
        }
    } else {
        if (points.size() < capacity) {
            points.push_back(point);
        } else {
            northwest = new Quadtree(minX, midX, minY, midY, capacity);
            northeast = new Quadtree(midX, maxX, minY, midY, capacity);
            southwest = new Quadtree(minX, midX, midY, maxY, capacity);
            southeast = new Quadtree(midX, maxX, midY, maxY, capacity);
            hasChildren = true;
            for (int i = 0 ; i < points.size(); i++) {
                add(points[i]);
            }
            points.clear();
            add(point);
        }
    }
}

bool Quadtree::intersects(float _x, float _y, float _w, float _h){
    return !(
         _x - _w > minX + maxX ||
         _x + _w < minX - maxX ||
         _y - _h > minY + maxY ||
         _y + _h < minY - maxY
    );
};

bool Quadtree::contains(float _x, float _y, float _w, float _h, ofPoint point){
    return (
        point.x >= _x &&
        point.x <= _x + _w &&
        point.y >= _y &&
        point.y <= _y + _h
    );
}

void Quadtree::draw() {
    ofNoFill();
    for (int i = 0; i < points.size(); i++) {
        ofDrawCircle(points[i].x, points[i].y, 2);
    }

    ofDrawRectangle(minX, minY, maxX - minX, maxY - minY);
    if(hasChildren) {
        northwest->draw();
        northeast->draw();
        southwest->draw();
        southeast->draw();
    }
}

vector<ofPoint> Quadtree::query(float _x, float _y, float _w, float _h, vector<ofPoint> & found) {

    if (!intersects(_x, _y, _w, _h)) {
        return found;
    } else {
        for (auto p:points) {
            if (contains(_x, _y, _w, _h, p)) {
                found.push_back(p);
            }
        }
        if (hasChildren) {
            northwest->query(_x, _y, _w, _h, found);
            northeast->query(_x, _y, _w, _h, found);
            southwest->query(_x, _y, _w, _h, found);
            southeast->query(_x, _y, _w, _h, found);
        }
    }
    return found;
}
