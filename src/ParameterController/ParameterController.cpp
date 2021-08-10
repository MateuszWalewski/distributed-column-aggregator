#include "ParameterController.h"

#include <iostream>

ParameterController::ParameterController()
{
}

ParameterController & ParameterController::Instance()
{
    static ParameterController instance;
    return instance;
}

void ParameterController::LoadParameter( std::string parameter )
{
    mIsHub = parameter == "hub";
}

bool ParameterController::IsHub()
{
    return mIsHub;
}