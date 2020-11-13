#ifndef BUTTON_H
#define BUTTON_H

class Button
{
    friend class ButtonController;

private:

    bool _buttonStatus;

    bool _checkButton(){
        return _buttonStatus;
    }

public:

    Button(){
    }
    
    void init(){
        _buttonStatus=false;
    }
};

#endif
