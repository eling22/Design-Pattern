from gumball_machine import GumballMachine


gumball_machine: GumballMachine = GumballMachine()

print("i:insert_quarter")
print("e:eject_quarter")
print("t:turn_crank")
print("d:dispense")
print("f:fill_ball")
print("q:quit")
print("===========================")


while 1:
    c = input()
    if c == "i":
        gumball_machine.insert_quarter()
    elif c == "e":
        gumball_machine.eject_quarter()
    elif c == "t":
        gumball_machine.turn_crank()
    elif c == "d":
        gumball_machine.dispense()
    elif c == "f":
        print("the num of fill ball:")
        num = int(input())
        gumball_machine.fill_ball(num)
    elif c == "q":
        break