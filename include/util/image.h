/****
* @file image.h
* @brief Definition of image class
*/

/* Copyright © 2018 Vítor Godeiro. */


#ifndef IMAGE_H
#define IMAGE_H

#include "color.h"

/** 
* @class Image
* @brief The class that describes an image and your operations
*/
class Image {
public:
    /** @brief The construtor specifies a image class.*/
    Image(int width, int height);

	/** @brief The image class destructor. Destroys the image data structures.*/
    ~Image();
	
	/**
	*	@brief Get the width of the image
	*	@return width of the image
	*/
    inline int width() const  { return this->_width; }

	/**
	*	@brief Get the height of the image
	*	@return height of the image
	*/
    inline int height() const { return this->_height; }

	/**
	*	@brief Get color at one position by operator ()
	*	@param (i,j) : Position x,y in image
	*	@return Color at position i,j
	*/
    inline Color3f operator()  (size_t i, size_t j) const {return this->_data[this->_width*j + i];}

	/**
	*	@brief Get color at one position by operator ()
	*	@param (i,j) : Position x,y in image
	*	@return Color at position i,j
	*/
    inline Color3f& operator() (size_t i, size_t j) {return this->_data[this->_width*j + i];}

    /**
    *	@brief Save image at file in Ascii format
    *	@param out: Name of out file
    */
    void writePppmAscii(std::string out);

    /**
    *	@brief Save image at file in Binary format
    *	@param out: Name of out file
    */
    void writePppmBinary(std::string out);
    
private:

	/**
	*	@brief Get color at one position
	*	@param (i,j) : Position x,y in image
	*	@return Color at position i,j
	*/
    inline Color3f color_at (size_t i, size_t j) const {return this->_data[this->_width*j + i];}


	Color3f *_data;	
	int _width, _height;
};

#endif 
