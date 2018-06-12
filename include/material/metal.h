/****
* @file lambertian.h
* @brief Metal material describe
*/

/* Copyright © 2018 Vítor Godeiro. */

#ifndef _METAL_H_
#define _METAL_H _

#include "material.h"
#include "utils.h"

/** 
* @class Color3u
* @brief The class that represents metal material
*/

class Metal : public Material {
    public:

        Metal(const Vec3& a, float f);
        virtual bool scatter(const Ray& r_in, const Hit& rec, Vec3& attenuation, Ray& scattered) const;

        Vec3 albedo;
        float fuzz;
};

#endif