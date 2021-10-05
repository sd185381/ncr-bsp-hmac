// Auth3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "exampleGET.h"
#include "examplePOST.h"
#include <iostream>


int main()
{
    std::cout << "Example Get Results" << std::endl;
    exampleGET("INSERT_SECRET", "INSERT_SHARED","INSERT_ORGANIZATION");
    std::cout << "\n" << std::endl;
    std::cout << "Example Post Results" << std::endl;
    examplePOST("INSERT_SECRET", "INSERT_SHARED", "INSERT_ORGANIZATION");
    return 0;
}

