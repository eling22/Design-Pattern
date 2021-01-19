from pizza import Pizza
from pizza_store import ChicagoPizzaStore, NYPizzaStore, PizzaStore


def main():
    ny_store: PizzaStore = NYPizzaStore()
    pizza: Pizza = ny_store.order_pizza("cheese")
    print(f"A ordered a {pizza.name}\n")
    pizza: Pizza = ny_store.order_pizza("clam")
    print(f"B ordered a {pizza.name}\n")

    chicago_store: PizzaStore = ChicagoPizzaStore()
    pizza = chicago_store.order_pizza("cheese")
    print(f"C ordered a {pizza.name}\n")


if __name__ == "__main__":
    main()
