from bank import Bank


class Admin(Bank):
    _type = "Admin"

    def __init__(self, name, email, address, password) -> None:
        self._name = name
        self._email = email
        self._address = address
        self._password = password

        self._id = Bank.make_id()
        Bank._add_account(self)

    def view_info(self, _id=None):
        print()
        super()._view_info(_id)
        print()

    def delete(self, _id):
        account = Bank._get_user(_id)
        name = account._name

        if account:
            super()._remove_user(account)
            print(f"ID : {_id}, Name : {name} Was Removed Successfully!\n")
            self.view_info()
        else:
            print("ID Not Found!\n")

    def view_total_loan(self):
        print(f"Total loan : {Bank.bank_loan()}TK\n")

    def view_total_balance(self):
        print(f"Total Balance : {Bank.bank_balance()}TK\n")

    def turn_off_loan(self, _id):
        account = super()._get_user(_id)

        if account:
            account._got_loan = -1
            print("Deactivated Successfully!\n")
            self.view_info()
        else:
            print("ID Not Found!\n")
