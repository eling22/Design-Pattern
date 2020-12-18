from Duck.Duck import MallardDuck, ModelDuck
from Duck.FlyBehavior import FlyRocketPowered


def main():
    mallard = MallardDuck()
    mallard.performQuack()
    mallard.performFly()

    model = ModelDuck()
    model.performFly()
    model.setFlyBehavior(FlyRocketPowered())
    model.performFly()


if __name__ == "__main__":
    main()
