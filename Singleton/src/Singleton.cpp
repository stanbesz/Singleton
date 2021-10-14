/*
 * Singleton.cpp
 *
 *  Created on: Nov 19, 2020
 *      Author: stani
 */

#include "Singleton.h"


/**
 * Static methods should be defined outside the class.
 */

Singleton* Singleton::pinstance_{nullptr};
std::mutex Singleton::mutex_;

Singleton::Singleton():images()
{
}
Singleton::Singleton(std::vector< std::string> images):images(images){

}
Singleton::~Singleton() {}


void Singleton::openImage(std::string val){
	for(unsigned i=0;i<images.size();i++){
		if(images[i].find(val)!=std::string::npos){
			//how to display image with openvs
			cv::Mat img;
			img=cv::imread(images[i]);
			imshow("Display window", img);
			cv::waitKey(0); // Wait for a keystroke in the window
			std::cout<<"It's here!"<<std::endl;
			return;
		}
	}
		std::cout<<"No such image found!"<<std::endl;
}
void Singleton::display(){
	for(unsigned int i = 0;i<images.size();i++){
		std::cout<<images[i]<<std::endl;
	}
}
void Singleton::removeImage( std::string val){
	std::cout<<"Erasing!"<<std::endl;
		for(unsigned int i = 0;i<images.size();i++){
			if(images[i].find(val)!=std::string::npos){
				images[i].erase();
				return;
			}
		}
		std::cout<<"No image to erase!"<<std::endl;
}

void Singleton::insertImage(std::string val){
	images.push_back(val);
}
/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
Singleton *Singleton::GetInstance(std::vector<std::string> images)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Singleton(images);
    }
    return pinstance_;
}


