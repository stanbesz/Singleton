//============================================================================
// Name        : Singleton.cpp
// Author      : Stanimir Aleksandrov
// Version     :
// Copyright   : Stanimir Aleksandrov
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "Singleton.h"




using namespace cv;

void ThreadFoo(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::vector< std::string> images1;
    std::string img1="C:/Users/stani/OneDrive/Desktop/Images/clouds.jpg";
    std::string img2="C:/Users/stani/OneDrive/Desktop/Images/man.jpg";
    images1.push_back(img1);
    images1.push_back(img2);
    Singleton* singleton = Singleton::GetInstance(images1);
    singleton->display();
    singleton->openImage("clouds");
    std::cout<<"Opened clouds?"<<std::endl;
    singleton->insertImage("C:/Users/stani/OneDrive/Desktop/Images/birds.jpg");
    singleton->display();

}

void ThreadBar(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::vector<std::string> images2;
    std::string img1="C:/Users/stani/OneDrive/Desktop/Images/birds.jpg";
    std::string img2="C:/Users/stani/OneDrive/Desktop/Images/book.jpg";
    images2.push_back(img1);
    images2.push_back(img2);
    Singleton* singleton = Singleton::GetInstance(images2);
    singleton->display();
    singleton->openImage("birds");
    std::cout<<"Opened birds?"<<std::endl;
    singleton->display();
    singleton->removeImage("birds");
    singleton->display();
}

int main()
{
    std::cout <<"If you see the same value, then singleton was reused (yay!\n" <<
                "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
                "RESULT:\n";

//    std::string image_path = samples::findFile("starry_night.jpg");
//            Mat img = cv::imread(image_path, IMREAD_COLOR);
//            if(img.empty())
//            {
//                std::cout << "Could not read the image: " << image_path << std::endl;
//                return 1;
//            }
//            imshow("Display window", img);
//            int k = waitKey(0); // Wait for a keystroke in the window
//            if(k == 's')
//            {
//                imwrite("starry_night.png", img);
//            }


    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();


    return 0;
}
