/****
* @file ray.h
* @brief Definition of ray class
*/

/* Copyright © 2018 Vítor Godeiro. */

#ifndef _RAY_H_
#define _RAY_H_

#include "vec3.h" 

/** 
* @class Ray
* @brief The class that describes an ray and your operations
*/
class Ray {

    private:
        Point3 origin; 
        Vec3 direction; 

    public:
        Ray( Point3 origin_ = Point3(), Vec3 direction_ = Vec3() ) : origin( origin_ ), direction( direction_ )  { }

        inline Vec3 get_direction( void ) const { return direction; }
        inline Point3 get_origin( void ) const { return origin; }
        Point3 point_at( float t )  const { return origin + t * direction; }
};

#endif
