/****
* @file lambertian.cpp
*
* Copyright © 2018 Vítor Godeiro LTDA.
****/

#include "../../include/material/lambertian.h"

Lambertian::Lambertian(const Vec3& a) : albedo(a) {}

bool Lambertian::scatter(const Ray& r_in, const Hit& rec, Vec3& attenuation, Ray& scattered) const  {
	Vec3 target = rec.point + rec.normal + random_in_unit_sphere();
	scattered = Ray(rec.point, target-rec.point);
	attenuation = albedo;
	return true;
}