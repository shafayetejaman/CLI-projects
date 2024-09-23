class Customer:
    def __init__(self, name) -> None:
        self.name = name

    def order(self):
        pass

    def payment(self):
        pass


class Food:
    def __init__(self, name, category, price, preparing_time) -> None:
        self.category = category
        self.name = name
        self.price = price
        self.preparing_time = preparing_time
        self.rating = 0.0

    def rate(self, stars):
        self.rating += stars
