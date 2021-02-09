
# TODO : macro


from remote_control import RemoteControl
from package.light import Light, LightOffCommand, LightOnCommand
from package.ceiling_fan import CeilingFan, CeilingFanHighCommand, CeilingFanMediumCommand, CeilingFanOffCommand
from package.macro_command import MacroCommand


def main():
    remote_control = RemoteControl()
    living_room_light = Light("living_room")
    kitchen_ceiling_fan = CeilingFan("kitchen")
    living_room_light_on = LightOnCommand(living_room_light)
    living_room_light_off = LightOffCommand(living_room_light)
    kitchen_ceiling_fan_high = CeilingFanHighCommand(kitchen_ceiling_fan)
    kitchen_ceiling_fan_medium = CeilingFanMediumCommand(kitchen_ceiling_fan)
    kitchen_ceiling_fan_off = CeilingFanOffCommand(kitchen_ceiling_fan)

    party_on_commands = [living_room_light_on, kitchen_ceiling_fan_high]
    party_off_commands = [living_room_light_off, kitchen_ceiling_fan_off]

    party_on = MacroCommand(party_on_commands)
    party_off = MacroCommand(party_off_commands)

    remote_control.set_command(0, living_room_light_on, living_room_light_off)
    remote_control.set_command(
        1, kitchen_ceiling_fan_high, kitchen_ceiling_fan_off)
    remote_control.set_command(
        2, kitchen_ceiling_fan_medium, kitchen_ceiling_fan_off)
    remote_control.set_command(3, party_on, party_off)
    print(remote_control)

    remote_control.on_button_was_pushed(0)
    remote_control.off_button_was_pushed(0)
    remote_control.on_button_was_pushed(1)
    remote_control.off_button_was_pushed(1)
    remote_control.on_button_was_pushed(2)
    remote_control.off_button_was_pushed(2)
    remote_control.on_button_was_pushed(3)
    remote_control.off_button_was_pushed(3)
    print("\nstart undo :")
    remote_control.undo_button_was_pushed()
    remote_control.undo_button_was_pushed()
    remote_control.undo_button_was_pushed()
    remote_control.undo_button_was_pushed()
    remote_control.undo_button_was_pushed()
    remote_control.undo_button_was_pushed()
    remote_control.undo_button_was_pushed()
    remote_control.undo_button_was_pushed()


if __name__ == "__main__":
    main()
