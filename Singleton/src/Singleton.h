/*
 * Singleton.h
 *
 *  Created on: Nov 19, 2020
 *      Author: stani
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <set>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class Singleton
{


private:
    static Singleton * pinstance_;
    static std::mutex mutex_;

protected:
    Singleton();
    Singleton(std::vector<std::string> images);
    ~Singleton();
    std::vector<std::string> images;

public:

    static Singleton *GetInstance(std::vector<std::string> images);

    void openImage( std::string val);

    void removeImage( std::string val);

    void display();

    void insertImage(std::string val);

    std::string value() const;
};



#endif /* SINGLETON_H_ */
