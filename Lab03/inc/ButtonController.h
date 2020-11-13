#ifndef BUTTON_CONTROLLER_H
#define BUTTON_CONTROLLER_H

#include "Button.h"
using namespace std;

class ButtonController
{
private:
    
    Button *mybutton;
    
public:
    ButtonController(){
        // Init the button variable
        mybutton = NULL;
    }

    void init(Button *button){
        mybutton = button;
    }

   int buttonPressed(){
       if (mybutton!=NULL)
       {
           if (mybutton->_checkButton()) return 1;
       }
        else
        {
            return -1;
        }
        return 0;
    }

    bool buttonReleased(){
        if (mybutton!=NULL)
       {
           if (!mybutton->_checkButton()) return 1;
       }
        else
        {
            return -1;
        }
        return 0;
    }
};

#endif

