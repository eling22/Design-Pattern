class Singleton:
    _instance = None

    def __new__(cls, *args, **kwargs):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
        return cls._instance

    def __init__(self, a, b) -> None:
        self.a = a
        self.b = b


obj1 = Singleton(10, 20)
obj2 = Singleton(100, 200)

print("obj1", obj1.a, obj1.b)
print("obj2", obj2.a, obj2.b)
