#include "ofMain.h"
class Quadtree {
    public :
    Quadtree();
    Quadtree(float min_x, float max_x, float min_y, float max_y, int cap);
    ~Quadtree();
    void findMidpoints();
    void draw();
    void add(ofPoint& point);
    bool intersects(float _x, float _y, float _w, float _h);
    bool contains(float _x, float _y, float _w, float _h, ofPoint point);

    vector<ofPoint> query(float _x, float _y, float _w, float _h, vector<ofPoint> & result);
    int capacity;
    float minX, minY, maxX, maxY;
    float midX, midY;
    Boolean hasChildren;
    vector<ofPoint> points;
    Quadtree *northwest;
    Quadtree *northeast;
    Quadtree *southeast;
    Quadtree *southwest;
    
};
