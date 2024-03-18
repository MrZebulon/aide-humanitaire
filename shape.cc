#include <iostream>
#include <cmath>
#include <string>
#include "shape.h"

using namespace std;

double ecart_angulaire(segment segment_1, segment segment_2){
	double ecart(segment_1.angle + (M_PI - segment_2.angle));
	if (ecart < -M_PI){
		ecart+= 2*M_PI;
	} else if (ecart > M_PI){
		ecart -= 2*M_PI;
	}
	return ecart;
}


bool superpo_commun(segment segment_1, segment segment_2){
	if (ecart_angulaire(segment_1, segment_2) == 0) {
		return true;
	}
	return false;
}

// point q lies on line segment 'pr'
bool onSegment(S2d p, S2d q, S2d r) { 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 

// 0 --> p, q and r are collinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(S2d p, S2d q, S2d r) { 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;
  
    return (val > 0)? 1: 2;
} 

bool doIntersect(S2d p1, S2d q1, S2d p2, S2d q2) { 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    if (o1 != o2 && o3 != o4) 
        return true; 
 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false;
} 