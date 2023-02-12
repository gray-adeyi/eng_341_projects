#include <iostream>
using namespace std;

namespace CruiseControlModule
{
    /// Fancy model name for the cruise control for aesthetics
    const string MODEL_NAME = "\
███████╗███╗░░██╗░██████╗░    ██████╗░░░██╗██╗░░███╗░░  ░█████╗░░█████╗░\n\
██╔════╝████╗░██║██╔════╝░    ╚════██╗░██╔╝██║░████║░░  ██╔══██╗██╔══██╗\n\
█████╗░░██╔██╗██║██║░░██╗░    ░█████╔╝██╔╝░██║██╔██║░░  ██║░░╚═╝██║░░╚═╝\n\
██╔══╝░░██║╚████║██║░░╚██╗    ░╚═══██╗███████║╚═╝██║░░  ██║░░██╗██║░░██╗\n\
███████╗██║░╚███║╚██████╔╝    ██████╔╝╚════██║███████╗  ╚█████╔╝╚█████╔╝\n\
╚══════╝╚═╝░░╚══╝░╚═════╝░    ╚═════╝░░░░░░╚═╝╚══════╝  ░╚════╝░░╚════╝░\n\
        ";

    /// This is the speed in which the vehicle utilizing this cruise control module must attain before before the cruise control can be activated.
    const uint CRUISE_CONTROL_TRIGGER_SPEED = 30;
    uint vehicle_current_speed;

    void accelerate_vehicle(uint desired_speed)
    {
        cout << "[INFO] Accelerating vehicle" << endl;

        while (vehicle_current_speed < desired_speed)
        {
            vehicle_current_speed++;
            cout << "[INFO] Vehicle current speed is " << vehicle_current_speed << "Mph" << endl;
            if (vehicle_current_speed == VehicleInfo::MAX_SPEED)
            {
                cout << "[WARNING] Vehicle cannot go beyond it's max speed of " << VehicleInfo::MAX_SPEED << "Mph" << endl;
                break;
            }
        }
    }
    void decelerate_vehicle(uint desired_speed)
    {
        cout << "[INFO] Decelerating vehicle" << endl;
        while (vehicle_current_speed > desired_speed)
        {
            vehicle_current_speed--;
            cout << "[INFO] Vehicle current speed is " << vehicle_current_speed << "Mph" << endl;
            if (vehicle_current_speed == CRUISE_CONTROL_TRIGGER_SPEED)
            {
                cout << "[WARNING] Vehicle cannot decelerate below the Cruise control speed of " << CRUISE_CONTROL_TRIGGER_SPEED << endl;
            }
        }
    }

    void set_cruise_speed(uint cruise_speed, uint current_speed)
    {
        if (vehicle_current_speed < CRUISE_CONTROL_TRIGGER_SPEED)
        {
            cout << "[WARNING] Vehicle speed is below threshold to activate Cruise Control" << endl;
            vehicle_current_speed = current_speed;
        }
        else if (cruise_speed > vehicle_current_speed)
        {
            accelerate_vehicle(cruise_speed);
        }
        else if (cruise_speed < vehicle_current_speed)
        {
            decelerate_vehicle(cruise_speed);
        }
        else if (cruise_speed == vehicle_current_speed)
        {
            cout << "[INFO] Maintaining Vehicle Cruise Speed at " << cruise_speed << "Mph" << endl;
        }
        cout << "[INFO] Maintaining Vehicle Cruise Speed at " << vehicle_current_speed << "Mph" << endl;
    }

    void
    initiate_cruise_control()
    {
        cout << "[INFO] Cruise control module is active" << endl;
        cout << "[INFO] Cruise control trigger speed is " << CRUISE_CONTROL_TRIGGER_SPEED << "Mph" << endl;
        while (true)
        {
            if (!vehicle_current_speed)
            {
                cout << "Please enter vehicle current speed [Mph] >> ";
                cin >> vehicle_current_speed;
            }

            cout << "Please enter desired cruise speed [Mph] >> ";
            uint desired_cruise_speed;
            cin >> desired_cruise_speed;
            set_cruise_speed(desired_cruise_speed, vehicle_current_speed);
        }
    }

}