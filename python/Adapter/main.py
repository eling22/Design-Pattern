
from turkey import Turkey, TurkeyAdapter, WildTurkey
from duck import Duck, MallardDuck


def main():
    duck = MallardDuck()
    turkey = WildTurkey()
    turkey_adapter = TurkeyAdapter(turkey)

    print("The Turkey says...")
    testTurkey(turkey)

    print("\nThe Duck says...")
    testDuck(duck)

    print("\nThe TurkeyAdapter says...")
    testDuck(turkey_adapter)


def testDuck(duck: Duck):
    duck.quack()
    duck.fly()


def testTurkey(turkey: Turkey):
    turkey.gobble()
    turkey.fly()


if __name__ == "__main__":
    main()
