#include <stdio.h>
#include "remote_control.h"
void main()
{
    RemoteControl remote_control;
    RemoteControlNew(&remote_control);
    remote_control.print(&remote_control);
}