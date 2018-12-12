#include "LMUserInput.h"

LMUserInput::LMUserInput()
{



}

void LMUserInput::get()
{
    while(1)
    {
        fgets(_buf,sizeof(_buf),stdin);
        if(strlen(_buf)>1)
            break;
    }
    _buf[strlen(_buf)-1]=0;
}

