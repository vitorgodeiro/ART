/****
* @file lambertian.h
* @brief Dieletric material describe
*/

/* Copyright © 2018 Vítor Godeiro. */

#ifndef _DIELECTRIC_H
#define _DIELECTRIC_H _

#include "material.h"
#include "utils.h"

/** 
* @class Color3u
* @brief The class that represents dieletric material
*/ 
class Dielectric : public Material { 
    public:
        
        Dielectric(float ri);
        virtual bool scatter(const Ray& r_in, const Hit& rec, Vec3& attenuation, Ray& scattered) const;

        float ref_idx;
};

#endif