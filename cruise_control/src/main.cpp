#include <iostream>
#include "vehicle_info.h"
#include "cruise_control.h"

using namespace std;

const uint GROUP_NUMBER = 6;

int main()
{
    cout << "\n\n";
    cout << CruiseControlModule::MODEL_NAME << endl;
    cout << "\n----- ENG 341 Cruise Control Program -----\n\n";
    cout << "Vehicle Company: " << VehicleInfo::COMPANY << endl;
    cout << "Brand Name: " << VehicleInfo::BRAND_NAME << endl;
    cout << "Design Year: " << VehicleInfo::BRAND_YEAR << endl;
    CruiseControlModule::initiate_cruise_control();
}