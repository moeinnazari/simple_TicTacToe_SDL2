#include <iostream>
#include "App.h"

int main(int argc,char* args[])
{
    App app;
    if(!app.init()){
        return -1;
    }
    else
    {
        app.run();
    }

    return 0;
}
