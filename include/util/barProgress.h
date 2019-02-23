/****
* @file scene.h
* @brief Definition of bar Progress
*/

#ifndef _BAR_PROGRESS_H
#define _BAR_PROGRESS_H

class BarProgress {
	private:
		int barWidth;
		int contUpgrade;
		float porcentagem;
	public:
		BarProgress(int barWidth, int height);

		/**
		* @brief Print the bar progress
		**/
		void generateBarProgress();

		/**
		* @brief Plus one in the contUpgrade 
		*/
		void updateContUpgrade();
};
#endif 