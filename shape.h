// Talia Meyer
// Noam Lévy

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include "graphic.h"

constexpr double epsil_zero(0.5) ;
constexpr double epsil_1(0.0000000001);

struct S2d{
	double x=0.;
	double y=0.;
};

struct Segment{
	S2d base;
	double angle;
	double longueur;

	// Obligatoire pour pouvoir faire emplace_back
	Segment(const S2d& _base, double _angle, double _longueur);
};

S2d get_end_of_segment(const Segment& seg);
double get_distance(const Sd2& s1, const Sd2& s2);
double dot_product(const S2d& u, const S2d& v);

double ecart_angulaire(Segment segment_1, Segment segment_2);

bool superpo_commun(Segment segment_1, Segment segment_2, bool is_epsil_zero);
bool on_segment(S2d p, S2d q, S2d r, bool is_epsil_zero);
int orientation(S2d p, S2d q, S2d r, bool is_epsil_zero);
bool do_intersect(S2d p1, S2d q1, S2d p2, S2d q2, bool is_epsil_zero);
void square(double x, double y, double d, double r, double g, double b);
void circle(double x, double y, double ray, double r, double g, double b);

#endif
