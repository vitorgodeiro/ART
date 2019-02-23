/****
* @file barProfress.cpp
*
* Copyright © 2018 Vítor Godeiro LTDA.
****/

#include "../../include/util/barProgress.h"

BarProgress::BarProgress(int barWidth, int height) {
	this->barWidth = barWidth;
	this->porcentagem = 100.0/height/100;
	this->contUpgrade = 0;
}

void BarProgress::generateBarProgress(){
	int pos;

	float val = this->porcentagem*this->contUpgrade;
	if (val > 1) {val = 1;}
	pos = val*barWidth;
	std::cout << "[";
	for (int i = 0; i < barWidth; ++i) {
       	if (i < pos) {std::cout << "=";}
       	else if (i == pos) std::cout << ">";
       	else std::cout << " ";
    }
    
    std::cout << "] " << int(val * 100.0) << " %\r";
	std::cout.flush();
}

void BarProgress::updateContUpgrade(){
	this->contUpgrade++;
	this->generateBarProgress();
}