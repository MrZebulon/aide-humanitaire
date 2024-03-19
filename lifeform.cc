#include <iostream>
#include <cmath>
#include <string>
#include "lifeform.h"

using namespace std;

bool lifeform_in(S2d position){
	if (position.x >=1 and position.x <= dmax-1 and 
	position.y > 0 and position.y < dmax){
		return true;
	}
	cout << message::lifeform_center_outside(position.x, position.y);
	exit(EXIT_FAILURE);
}

bool positive_age(double age){
	if (age>0){
		return true;
	}
	cout << message::lifeform_age(age);
	exit(EXIT_FAILURE);
}

bool corail::corail_in(vector<Segment> seg){
	for (int i(0); i<= this->nb_segment-1; ++i){
		if (seg[i].base.x < 1 or seg[i].base.x > dmax-1 or 
		seg[i].base.y < 1 or seg[i].base.y > dmax-1){
			cout << 
			message::lifeform_computed_outside(this->id, seg[i].base.x, seg[i].base.y);
			exit(EXIT_FAILURE);
		}
		S2d fin;
		fin.x = seg[i].base.x + seg[i].longueur * cos(seg[i].angle);
		fin.y = seg[i].base.y + seg[i].longueur * sin(seg[i].angle);
		if (fin.x < 1 or fin.x > dmax-1 or fin.y < 1 or fin.y > dmax-1){
			cout << 
			message::lifeform_computed_outside(this->id, seg[i].base.x, seg[i].base.y);
			exit(EXIT_FAILURE);
		}
	}
	return true;
}

bool corail::segment_length_in(vector<Segment> seg){
	for (int i(0); i<= this->nb_segment-1; ++i){
		if (seg[i].longueur >= l_repro or seg[i].longueur < l_repro - l_seg_interne){
			message::segment_length_outside(this->id, seg[i].longueur);
			exit(EXIT_FAILURE);
		}
	}
	return true;
}

bool corail::segment_angle_in(vector<Segment> seg){
	for (int i(0); i<= this->nb_segment-1; ++i){
		if (seg[i].angle > M_PI or seg[i].longueur < -M_PI){
			message::segment_angle_outside(this->id, seg[i].angle);
			exit(EXIT_FAILURE);
		}
	}
	return true;
}

bool corail::segment_not_superpo(vector<Segment> seg){
	for (int i(0); i<= this->nb_segment-1; ++i){
		if (superpo_commun(seg[i],seg[i+1])){
			message::segment_superposition(this->id, i, i+1);
			exit(EXIT_FAILURE);
		}
	}
	return true;
}

bool corail::segment_not_coll_him(vector<Segment> seg){
	if (this->nb_segment < 2){return true;}
	for (int i(0); i<= this->nb_segment-3; ++i){
		for (int j(i+2); j<= this->nb_segment-1; ++j){
			S2d fin_i;
			fin_i.x = seg[i].base.x + seg[i].longueur * cos(seg[i].angle);
			fin_i.y = seg[i].base.y + seg[i].longueur * sin(seg[i].angle);
			S2d fin_j;
			fin_j.x = seg[j].base.x + seg[j].longueur * cos(seg[j].angle);
			fin_j.y = seg[j].base.y + seg[j].longueur * sin(seg[j].angle);
			if (doIntersect(seg[i].base, fin_i, seg[j].base, fin_j)){
				message::segment_collision(this->id, i, this->id, j);;
				exit(EXIT_FAILURE);
			}
		}
	}
	return true;
}

bool ray_in(double ray){
	if (ray>=r_sca and ray<r_sca_repro){
		return true;
	}
	cout << message::scavenger_radius_outside(ray);
	exit(EXIT_FAILURE);
}