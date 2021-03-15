from beverage import CoffeeWithHook, TeaWithHook


def main():
    tea = TeaWithHook()
    coffee = CoffeeWithHook()

    print("Making tea...")
    tea.prepareRecipe()

    print("\nMaking coffee...")
    coffee.prepareRecipe()


if __name__ == "__main__":
    main()
