/****
* @file scene.h
* @brief Definition of scene class
*/

#ifndef _SCENE_H
#define _SCENE_H

#include <omp.h>
#include <limits>

#include "../../src/util/image.cpp"
#include "../../src/shape/surface_list.cpp"

#include "camera.h"

class Scene {
	private :

		SurfaceList *world;
		Camera *cam;
		int nx;
		int ny;
		int ns;

		/**
		* @brief Compute the color of the sample at coordinates
		*		 (x,y) with supersampling
		**/
		Vec3 sample (const Ray& r, int depth);
	public:

		/**
		* @brief Pre-process it into a better representation, 
		*        an accelerated representation, to simplify 
		*        the job of render.
		**/
		void accelerate();

		/**
		* @brief Render the scene
		**/
		Image render();

		/**
		* @brief Parsing the file that has the scene
		**/
		void parsing();

		Scene();
};

#endif 