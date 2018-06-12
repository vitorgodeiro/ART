/****
* @file sphere.h
* @brief Definition of Sphere class
*/

/* Copyright © 2018 Vítor Godeiro. */

#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "surface.h" 
#include "../material/material.h"

/** 
* @class Sphere
* @brief The class that describe one Sphere and 
* its operations
*/
class Sphere: public Surface {
public:
	/** @brief The construtor specifies a Sphere class.*/
	Sphere ();

	/** 
	* @brief The construtor specifies a Sphere class.
	* @param c is one vector with coordinates from the
	* center of the sphere
	* @param r is one float that have radius of the sphere
	*/
    Sphere (Vec3 c, float r, Material *m); 
	
	/** 
	* @brief Check if ray hit sphere
	* @param r 
	* @param t_min 
	* @param t_max
	* @param rec
	* @return Boolean (True if ray intersect or False if ray not intersect)
	*/		
    inline virtual bool hit (const Ray& r, float t_min, float t_max, Hit& rec) const;

    Vec3 center;
    float radius;
    Material *mat_ptr;
    
};

#endif
