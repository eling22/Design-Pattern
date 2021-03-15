from abc import abstractmethod


class CaffeineBeverageWithHook:
    def __init__(self) -> None:
        pass

    def prepareRecipe(self):
        self.boilWater()
        self.brew()
        self.PourInCup()
        if self.CustomerWantsCondiments():
            self.addCondiments()

    def boilWater(self):
        print("Boiling water")

    def PourInCup(self):
        print("Pouring into cup")

    def CustomerWantsCondiments(self) -> bool:
        return True

    @abstractmethod
    def brew(self):
        pass

    @abstractmethod
    def addCondiments(self):
        pass


class CoffeeWithHook(CaffeineBeverageWithHook):
    def __init__(self) -> None:
        super().__init__()

    def brew(self):
        print("Dripping Coffee through filter")

    def addCondiments(self):
        print("Adding Sugar and Milk")

    def CustomerWantsCondiments(self) -> bool:
        answer = self.getUserInput()
        if answer.lower().startswith("y"):
            return True
        else:
            return False

    def getUserInput(self) -> str:
        print("Would you like sugar and milk with your coffee (y/n)? ", end="")
        answer = input()
        if not answer:
            return "no"
        return answer


class TeaWithHook(CaffeineBeverageWithHook):
    def __init__(self) -> None:
        super().__init__()

    def brew(self):
        print("Steeping the tea")

    def addCondiments(self):
        print("Adding Lemon")

    def CustomerWantsCondiments(self) -> bool:
        answer = self.getUserInput()
        if answer.lower().startswith("y"):
            return True
        else:
            return False

    def getUserInput(self) -> str:
        print("Would you like lemon with your tea (y/n)? ", end="")
        answer = input()
        if not answer:
            return "no"
        return answer
