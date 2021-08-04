#pragma once
#include <string>

#define PCTRL() ParameterController::Instance()

class ParameterController
{

    private:
    ParameterController();

    bool mIsHub;

    public:
    static ParameterController & Instance();

    void LoadParameter(std::string parameter);

    bool IsHub();

};