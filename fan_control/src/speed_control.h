#include <iostream>

using namespace std;

namespace FanSpeedControl
{
    const string FANCY_NAME = "\
███████     ███████ ██████  ███████ ███████ ██████      ███████  █████  ███    ██     ██████  ███████  ██████  ██    ██ ██       █████  ████████  ██████  ██████  \n\
██          ██      ██   ██ ██      ██      ██   ██     ██      ██   ██ ████   ██     ██   ██ ██      ██       ██    ██ ██      ██   ██    ██    ██    ██ ██   ██ \n\
███████     ███████ ██████  █████   █████   ██   ██     █████   ███████ ██ ██  ██     ██████  █████   ██   ███ ██    ██ ██      ███████    ██    ██    ██ ██████  \n\
     ██          ██ ██      ██      ██      ██   ██     ██      ██   ██ ██  ██ ██     ██   ██ ██      ██    ██ ██    ██ ██      ██   ██    ██    ██    ██ ██   ██ \n\
███████     ███████ ██      ███████ ███████ ██████      ██      ██   ██ ██   ████     ██   ██ ███████  ██████   ██████  ███████ ██   ██    ██     ██████  ██   ██ \n\
";
    int fan_speed = 0;

    void set_desired_speed()
    {
        int input_speed;
        cout << "Please enter desired fan speed level from [0-5] :>> ";
        cin >> input_speed;
        if (input_speed >= 0 && input_speed <= 5)
        {
            cout << "[INFO] Setting Fan speed to " << input_speed << " speed level" << endl;
            fan_speed = input_speed;
        }
        else
        {
            cout << "[WARNING] " << input_speed << " is an invalid fan speed level, maintaining current fan speed of " << fan_speed << endl;
        }
    }

    void init()
    {
        cout << "[INFO] Fan Speed Regulator is active" << endl;
        cout << "[INFO] Please press [CTRL + C] to terminate program" << endl;
        while (true)
        {
            set_desired_speed();
            cout << "\n"
                 << endl;
        }
    }

}