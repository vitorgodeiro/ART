/****
* @file sphere.cpp
*
* Copyright © 2018 Vítor Godeiro LTDA.
****/

#include "../../include/shape/sphere.h"

Sphere::Sphere () { };
Sphere::Sphere (Vec3 c, float r) : center (c), radius(r) {};

inline bool Sphere::hit (const Ray& r, float t_min, float t_max, Hit& rec) const {
	Vec3 oc = r.get_origin() - center;
    float a = Vec3::dot(r.get_direction(), r.get_direction());
    float b = Vec3::dot(oc, r.get_direction());
    float c = Vec3::dot(oc, oc) - radius*radius;
    float discriminant = b*b - a*c;
    if (discriminant > 0) {
    	float delta = sqrt(discriminant)/a;
        float temp = (-b - delta);
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.point = r.point_at(rec.t);
            rec.normal = Vec3::unit_vector(rec.point - center);
            return true;
        }
        temp = (-b + delta);
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.point = r.point_at(rec.t);
            rec.normal = Vec3::unit_vector(rec.point - center);
            return true;
        }
    }
	return false;
}

