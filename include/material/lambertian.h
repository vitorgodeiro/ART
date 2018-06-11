/****
* @file lambertian.h
* @brief Lambertian material describe
*/

/* Copyright © 2018 Vítor Godeiro. */

#ifndef _LAMBERTIAN_H_
#define _LAMBERTIAN_H _

#include "material.h"
#include "utils.h"

/** 
* @class Color3u
* @brief The class that represents lambertian material
*/
class Lambertian : public Material {
    public:
        
        Lambertian(const Vec3& a);
        virtual bool scatter(const Ray& r_in, const Hit& rec, Vec3& attenuation, Ray& scattered) const;

        Vec3 albedo;
};

#endif