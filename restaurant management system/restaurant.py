from datetime import date

class Restaurant:
    _employ_list = []
    __restaurant_fund = 0

    def __init__(self, name, address, fund) -> None:
        self.restaurant_name = name
        self.restaurant_address = address
        Restaurant.__restaurant_fund = fund
        self.menu = {}

    @staticmethod
    def show_employ(id=None):
        if id:
            for i in Restaurant._employ_list:
                if i.id == id:
                    print(
                        f"Name : {i.name}\nID : {i.id}\nAddress : {i.address}\nWork Day : {i.workday}\nTitle : ",
                        end="",
                    )

                    if isinstance(i, Server):
                        print("Server")
                    else:
                        print(f"Chef {i.items}")

                    print()
                    return
        else:
            for i in Restaurant._employ_list:
                print(
                    f"Name : {i.name}\nID : {i.id}\nAddress : {i.address}\nWork Day : {i.workday}\nTitle : ",
                    end="",
                )

                if isinstance(i, Server):
                    print("Server")
                else:
                    print(f"Chef {i.items}")

                print()

    def update_fund(self, bill):
        Restaurant.__restaurant_fund += bill

    def update_menu(self, item):
        self.menu.append(item)

    def assign_menu_items(self, item, id=None):
        if id:
            employee = [
                i for i in Restaurant._employ_list if i.id == id and isinstance(i, Chef)
            ]

            if len(employee) == 0:
                print("Not Found!")
                return

            employee[0].items.append(item)
        else:
            temp = [i for i in Restaurant._employ_list if isinstance(i, Chef)]

            employee = min(temp, key=lambda x: sum(x.workday.values()))
            employee.items.append(item)

            min_day = min(employee.workday, key=employee.workday.get)
            employee.workday[min_day] += 0.5
            employee.salary += 100

    def show_menu(self):
        category = input("What kind of Food you are looking for (appetizers, salads, chicken dishes, fish dishes, beef dishes, vegetables, fruits, desserts, drinks): ")
        
        if category in self.menu:
            print(self.menu[category])
        else:
            print("Invalid Category")


class Employee(Restaurant):
    def __init__(self, name, address, salary) -> None:
        self.name = name
        self.address = address
        self.salary = salary
        self.workday = {}
        self.salaryHsitory = {}

        current_date = date.today()

        self.id = current_date.strftime("%d%m%Y") + str(len(Restaurant._employ_list) + 1)

    def set_work_time(self, days):
        self.workday = days

    def pay_salary(self, id, date, amount):
        if id:
            employee = [i for i in Restaurant._employ_list if i.id == id]

            if not employee:
                print("Not Found!")
                return
        
            employee[0].salaryHsitory[date] = amount
            print(f"Name : {employee[0].name}\nSalary : {employee[0].salary}\nPaid : {amount}\nDue : {employee[0].salary-amount}")

    def update_salary(self, id, balance):
        employee = [i for i in Restaurant._employ_list if i.id == id]

        if not employee:
            print("Not Found!")
            return
    
        employee[0].salary = balance


class Server(Employee):
    def __init__(self, post, name, address, salary) -> None:
        self.post = post
        super().__init__(name, address, salary)

        Restaurant._employ_list.append(self)


class Chef(Employee):
    def __init__(self, items, name, address, salary) -> None:
        self.items = items
        super().__init__(name, address, salary)

        Restaurant._employ_list.append(self)

