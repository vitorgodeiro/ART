/****
* @file image.cpp
*
* Copyright © 2018 Vítor Godeiro LTDA.
****/

#include "../../include/util/image.h"
#include <fstream>

Image::Image(int width, int height) : _width(width), _height(height) {
	this->_data = new Color3f[width*height];
}

Image::~Image(){
	delete[] _data;
}

inline void Image::writePppmAscii(std::string out){
	std::ofstream outfile (out,std::ofstream::out);
	
	outfile << "P3" << std::endl;
	outfile << this->_width << " " << this->_height << std::endl;
	outfile << "255" << std::endl;

	for(int j = 0; j < this->_height; j++){
		for(int i = 0; i < this->_width; i++){
			outfile << int(255.99*color_at(i,j)[0]) << " " << int(255.99*color_at(i,j)[1]) << " " << int(255.99*color_at(i,j)[2]) << std::endl;
		}
	}

  	outfile.close();
}

inline void Image::writePppmBinary(std::string out){
	std::ofstream outfile (out, std::ofstream::binary);
	char* buffer = new char[this->_width*this->_height*3];

	outfile << "P6" << std::endl;
	outfile << this->_width << " " << this->_height << std::endl;
	outfile << "255" << std::endl;

	int r, g,b;
	for(int j = 0; j < this->_height; j++){
		for(int i = 0; i < this->_width; i++){
			buffer[j*this->_width*3 + i*3] = int(255.99*color_at(i,j)[0]);
			buffer[j*this->_width*3 + i*3 + 1] = int(255.99*color_at(i,j)[1]);
			buffer[j*this->_width*3 + i*3 + 2] = int(255.99*color_at(i,j)[2]);
		}
	}

	outfile.write(buffer, this->_width*this->_height*3);	
  	outfile.close();
	delete [] buffer;	
}
