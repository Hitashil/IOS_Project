//
//  main.cpp
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-03-19.
//
//

#include "App.h"


int main ( int argc, char** argv )
{
    App *application = new App();
    
    if (application)
    {
        application->run();
    }
    
    delete application;
    
    return 0;
}