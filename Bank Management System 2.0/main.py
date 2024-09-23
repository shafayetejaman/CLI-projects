from user import User
from admin import Admin
from bank import Bank


def is_valid(amount):
    if not amount.isdigit():
        print("Invalid Number!\nExiting...")
        exit(-1)

    return int(amount)


def main():
    bank = Bank("Boshundora Bank")
    current_user = None
    new_user = True

    while True:
        if not current_user:
            log_option = input("Login Or Register (L/R): ").lower()

            if log_option == "r":
                account_type = input(
                    "What Kind Of Account User Or Admin (U/A): "
                ).lower()

                if account_type == "a":
                    name = input("Name : ")
                    email = input("Email : ")
                    password = input("Password : ")
                    address = input("Address : ")
                    current_user = Admin(name, email, address, password)

                elif account_type == "u":
                    name = input("Name : ")
                    email = input("Email : ")
                    password = input("Password : ")
                    address = input("Address : ")
                    account_type = input(
                        "Account Type Savings Or Current (S/C): "
                    ).lower()

                    if account_type != "c" and account_type != "s":
                        print("Invalid Input!")
                        exit(-1)

                    current_user = User(name, email, address, account_type, password)

                else:
                    print("Invalid Option!\n")

            elif log_option == "l":
                print("Available Accounts :-\n")
                bank.view_available_account()
                _id = input("ID : ")
                password = input("password : ")
                current_user = bank.login(_id, password)
                if not current_user:
                    print("Incorrect ID/Password\n")

            else:
                print("Invalid Option!\n")

        else:
            if new_user:
                print(f"Welcome {current_user._name}\n")
                new_user = False

            if isinstance(current_user, User):
                option = input(
                    "1) Deposit\n2) Withdraw\n3) View Balance\n4) View Transaction History\n5) Transfer Balance\n6) Take A loan\n7) Exit\n8) logout\nOption : "
                )

                print()

                if option == "1":
                    current_user.deposit(is_valid(input("Amount : ")))
                elif option == "2":
                    current_user.withdraw(is_valid(input("Amount : ")))
                elif option == "3":
                    current_user.view_balance()
                elif option == "4":
                    current_user.view_transaction_history()
                elif option == "5":
                    receiver_id = input("Receiver ID : ")
                    amount = is_valid(input("Amount : "))

                    current_user.transfer(amount, receiver_id)

                elif option == "6":
                    current_user.take_loan(is_valid(input("Amount : ")))
                elif option == "7":
                    return
                elif option == "8":
                    current_user = None
                    new_user = True
                else:
                    print("Invalid Option!\n")

            else:
                option = input(
                    "1) View Information\n2) Delete An Account\n3) View Total loan\n4) View Total Balance\n5) Turn Off loan Of An User\n6) Exit\n7) logout\nOption : "
                )

                print()

                if option == "1":
                    if input("Do You Want To View All The Accounts? (Y/N): ").lower() == "y":
                        current_user.view_info()
                    else:
                        current_user.view_info(input("ID : "))

                elif option == "2":
                    current_user.delete(input("ID : "))
                elif option == "3":
                    current_user.view_total_loan()
                elif option == "4":
                    current_user.view_total_balance()
                elif option == "5":
                    current_user.turn_off_loan(input("ID : "))
                elif option == "6":
                    return
                elif option == "7":
                    current_user = None
                    new_user = True
                else:
                    print("Invalid Option!\n")


main()
