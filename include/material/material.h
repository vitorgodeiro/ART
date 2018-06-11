/****
* @file material.h
* @brief Material describe
*/

/* Copyright © 2018 Vítor Godeiro. */

#pragma once
#ifndef _MATERIAL_H_
#define _MATERIAL_H _

#include "../util/hit.h"

/** 
* @class Color3u
* @brief The class that represents material
*/
class Material  {
    public:
        virtual bool scatter(const Ray& r_in, const Hit& rec, Vec3& attenuation, Ray& scattered) const = 0;
};

#endif