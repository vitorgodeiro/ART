/****
* @file surface_list.h
* @brief Definition of SurfaceList class
*/

/* Copyright © 2018 Vítor Godeiro. */

#ifndef _SURFACE_LIST_H_
#define _SURFACE_LIST_H_

#include "surface.h" 
#include <vector>

/** 
* @class SurfaceList
* @brief The class that describe list of shape of the
* world
*/
class SurfaceList: public Surface {
    public:

    	/** @brief The construtor specifies a SurfaceList class.*/
    	SurfaceList ();

    	/** 
		* @brief The construtor specifies a SurfaceList class.
		* @param l is the list of shapes in the world
		*/
        SurfaceList (std::vector<Surface*> l);
        
        /** 
		* @brief Check if ray hit object
		* @param r 
		* @param t_min 
		* @param t_max
		* @param rec
		* @return Boolean (True if ray intersect or False if ray not intersect)
		*/
        inline virtual bool hit (const Ray& r, float t_min, float t_max, Hit& rec) const;

        std::vector<Surface*> list;
};

#endif
