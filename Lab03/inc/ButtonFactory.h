#ifndef BUTTON_FACTORY_H
#define BUTTON_FACTORY_H
#include "Button.h"
#include "ButtonController.h"
#include <iostream>

class ButtonFactory
{
private:
    Button *_fButton;
    ButtonController *_fCtrlButton;

public:
    ButtonFactory(){
        _fButton = nullptr;
        _fCtrlButton = nullptr;
    }
    ~ButtonFactory(){
        delete _fButton;
        delete _fCtrlButton;
    }
    Button* getButton(){
        if(!_fButton) _fButton = new Button();
        return _fButton;
    }
    ButtonController* getCtrlButton(){
        if(!_fCtrlButton) _fCtrlButton = new ButtonController();
        return _fCtrlButton;
    }

    void buildBoundle(){
        cout << "Create a new Button" << endl;
        getButton()->init();
        cout << "Create a new Button" << endl;
        getCtrlButton()->init(_fButton);

    }
};



#endif