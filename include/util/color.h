/****
* @file color.h
* @brief Definition of color class
*/

/* Copyright © 2018 Vítor Godeiro. */

#ifndef COLOR_H
#define COLOR_H

/** 
* @class Color3u
* @brief The class that represents an color
*/
class Color3f
{

public:
    
	/** @brief The construtor specifies a color class.*/
    Color3f() : component{0, 0, 0} {} ;
	
	/** 
	* @brief The construtor specifies a color class.
	* @param r is the component red
	* @param g is the component green
	* @param b is the component blue
	*/
    Color3f(float r, float g, float b) : component{r, g, b} {};

    inline float operator[] (size_t i) const { return this->component[i]; }
    inline float& operator[] (size_t i) { return this->component[i]; }
  	
	float component[3];
};
#endif 
