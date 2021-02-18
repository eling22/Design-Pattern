#include <stdio.h>
#include "remote_control.h"
#include "light.h"
#include "ceiling_fan.h"
void main()
{
    RemoteControl remote_control;
    RemoteControlNew(&remote_control);

    Light living_room_light;
    LightNew(&living_room_light, "living_room");
    CeilingFan kitchen_ceiling_fan;
    CeilingFanNew(&kitchen_ceiling_fan, "kitchen");

    LightOnCommand living_room_light_on;
    LightOnCommandNew(&living_room_light_on, &living_room_light);
    LightOffCommand living_room_light_off;
    LightOffCommandNew(&living_room_light_off, &living_room_light);

    CeilingFanHighCommand kitchen_ceiling_fan_high;
    CeilingFanHighCommandNew(&kitchen_ceiling_fan_high, &kitchen_ceiling_fan);
    CeilingFanMediumCommand kitchen_ceiling_fan_medium;
    CeilingFanMediumCommandNew(&kitchen_ceiling_fan_medium, &kitchen_ceiling_fan);
    CeilingFanOffCommand kitchen_ceiling_fan_off;
    CeilingFanOffCommandNew(&kitchen_ceiling_fan_off, &kitchen_ceiling_fan);

    remote_control.set_command(&remote_control, 0, (Command *)&living_room_light_on, (Command *)&living_room_light_off);
    remote_control.set_command(&remote_control, 1, (Command *)&kitchen_ceiling_fan_high, (Command *)&kitchen_ceiling_fan_off);
    remote_control.set_command(&remote_control, 2, (Command *)&kitchen_ceiling_fan_medium, (Command *)&kitchen_ceiling_fan_off);

    remote_control.print(&remote_control);
}