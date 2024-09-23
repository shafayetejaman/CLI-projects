from bank import Bank


class User:
    _type = "User"

    def __init__(self, name, email, address, account_type, password) -> None:
        self._name = name
        self._email = email
        self._address = address
        self._password = password
        self._account_type = "Current" if account_type == "c" else "Savings"

        self.__balance = 0
        self._transaction_history = {}
        self._got_loan = 0

        self._id = Bank.make_id()
        Bank._add_account(self)

    def deposit(self, amount):
        self.__balance += amount
        print(f"Deposit successful! current Balance : {self.__balance}TK\n")

    def increase_balance(self, amount):
        self.__balance += amount

    def withdraw(self, amount):
        if self.__balance < amount:
            print("Insufficient Balance!\n")
            return

        self.__balance -= amount
        print(f"Withdraw successful! current Balance : {self.__balance}TK\n")

    def view_balance(self):
        print(f"Your account has {self.__balance}TK\n")

    @property
    def get_balance(self):
        return self.__balance

    def view_transaction_history(self):
        if not self._transaction_history:
            print("Nothing To Show!")
            return

        for date, person in self._transaction_history.items():
            print(
                f"ON {date}, Balance Transfer Of {person[0]}TK,\nFrom {person[1]}(ID:{person[2]}) To {person[3]}(ID:{person[4]})\n"
            )

    def transfer(self, amount, receiver_id):
        if amount > self.__balance:
            print("Insufficient Balance!\n")
            return

        receiver_account = Bank._get_user(receiver_id)

        if receiver_account:
            receiver_account.increase_balance(amount)
            self.__balance -= amount

            print(f"Transfer Successful!\nYour Balance : {self.__balance}TK\n")

            self._transaction_history[Bank.get_date()] = [
                amount,
                self._name,
                self._id,
                receiver_account._name,
                receiver_account._id,
            ]
            receiver_account._transaction_history[Bank.get_date()] = [
                amount,
                self._name,
                self._id,
                receiver_account._name,
                receiver_account._id,
            ]
        else:
            print("ID Not Found!\n")

    def take_loan(self, amount):
        if amount > Bank.bank_balance():
            print("The Bank Is Bankrupt!\n")
            return

        if (
            self._got_loan == -1
            or self._got_loan == 3
            or (self._got_loan == 1 and self._account_type == "Savings")
        ):
            print("You Are Not Eligible For loan!\n")
            return

        self.__balance += amount
        Bank.increase_loan(amount)
        Bank.decrease_balance(amount)
        self._got_loan += 1

        print(f"Loan Taken Successfully!\nYour Balance : {self.__balance}TK\n")
