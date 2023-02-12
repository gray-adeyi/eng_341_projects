#include <iostream>
#include "speed_control.h"
using namespace std;

const int GROUP_NUMBER = 6;

int main()
{
    cout << FanSpeedControl::FANCY_NAME;
    cout << "\n---- 5 Speed Fan Regulator Program ----\n"
         << endl;
    cout << "Designed by: Group " << GROUP_NUMBER << endl;
    FanSpeedControl::init();
}