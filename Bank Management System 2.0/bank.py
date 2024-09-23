from datetime import date
import shelve
from pathlib import Path


class Bank:
    __balance = 0
    __loan = 0
    __number_of_account = 0
    _log = []
    __user_account_list = []
    __admin_account_list = []

    def __init__(self, name: str, address=None, balance=None) -> None:
        self._name = name
        root_dir = Path(__file__).parent

        with shelve.open(str(root_dir / "bank.db")) as DB:
            instance_data = DB.get(name)
            bank_data = DB.get("data")

            if bank_data:
                print("Loading data.........................")
                Bank.__balance = bank_data["balance"]
                Bank.__loan = bank_data["loan"]
                Bank.__number_of_account = bank_data["number_of_account"]
                Bank._log = bank_data["log"]
                Bank.__user_account_list = bank_data["user_account_list"]
                Bank.__admin_account_list = bank_data["admin_account_list"]

            if instance_data:
                self._address = instance_data["address"]
            else:
                self._address = address

            if balance:
                Bank.__balance = balance

    def __del__(self) -> None:
        print("saving to database............")

        root_dir = Path(__file__).parent

        with shelve.open(str(root_dir / "bank.db")) as DB:
            DB.update({self._name: {"address": self._address}})
            DB.update(
                {
                    "data": {
                        "balance": Bank.__balance,
                        "loan": Bank.__loan,
                        "number_of_account": Bank.__number_of_account,
                        "log": Bank._log,
                        "user_account_list": Bank.__user_account_list,
                        "admin_account_list": Bank.__admin_account_list,
                    }
                }
            )

    @staticmethod
    def _add_account(new_account):
        if new_account._type == "Admin":
            Bank.__admin_account_list.append(new_account)
        elif new_account._type == "User":
            Bank.__user_account_list.append(new_account)

        Bank.__number_of_account += 1

    @staticmethod
    def _get_user(_id):
        for i in Bank.__user_account_list:
            if i._id == _id:
                return i

        return None

    @staticmethod
    def _remove_user(account):
        Bank.__user_account_list.remove(account)

    @staticmethod
    def make_id():
        return Bank.get_date("%d%m%Y") + str(Bank.__number_of_account + 1)

    @staticmethod
    def get_date(s="%d/%m/%Y"):
        current_date = date.today()
        return current_date.strftime(s)

    @staticmethod
    def bank_loan():
        return Bank.__loan

    @staticmethod
    def bank_balance():
        return Bank.__balance

    @staticmethod
    def increase_loan(amount):
        Bank._log.append(
            f"ON {Bank.get_date()}, Total Lone Was Updated From {Bank.__loan} To {Bank.__loan + amount}"
        )
        Bank.__loan += amount

    @staticmethod
    def decrease_balance(amount):
        Bank._log.append(
            f"ON {Bank.get_date()}, Total Balance Was Updated From {Bank.__balance} To {Bank.__balance - amount}"
        )
        Bank.__balance -= amount

    def view_available_account(self):
        for i in Bank.__admin_account_list:
            print(f"Name : {i._name} (Admin)")
            print(f"ID : {i._id}")

            print()
        for i in Bank.__user_account_list:
            print(f"Name : {i._name} (User)")
            print(f"ID : {i._id}")

        print()

    def login(self, _id, password):
        for i in Bank.__admin_account_list:
            if i._id == _id and i._password == password:
                return i

        for i in Bank.__user_account_list:
            if i._id == _id and i._password == password:
                return i

        return None

    def _view_info(self, _id=None):
        if not _id:
            for i in Bank.__user_account_list:
                print(
                    f"Name : {i._name}\nEmail : {i._email}\nAccount : {i._account_type}\nID : {i._id}\nBalance : {i.get_balance}\nAddress : {i._address}\nGot loan : {'Deactivated' if i._got_loan == -1 else i._got_loan}\n"
                )
        else:
            for i in Bank.__user_account_list:
                if i._id == _id:
                    print(
                        f"Name : {i._name}\nEmail : {i._email}\nAccount : {i._account_type}\nID : {i._id}\nBalance : {i.get_balance}\nAddress : {i._address}\nGot loan : {'Deactivated' if i._got_loan == -1 else i._got_loan}\n"
                    )
                    return

            print("ID Not Found!\n")
