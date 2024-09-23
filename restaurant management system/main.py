from restaurant import *
from coustomer import *



def main():
    resturent = Restaurant("alibaba", "Dhaka", 50000)

    Server(1, "akash", "jhenaidha", 2000).set_work_time({"sun": 4, "mon": 5.4})

    Server(2, "akash2", "jhenaidha", 1500).set_work_time({"sun": 4, "mon": 3.4})
    Server(3, "akash3", "jhenaidha", 3000).set_work_time({"sun": 4, "mon": 5})

    Chef(["barger"], "akash4", "jhenaidha", 2000).set_work_time({"sun": 4, "mon": 4.2})
    Chef(["barger2"], "akash5", "jhenaidha", 1500).set_work_time({"sun": 4, "mon": 4})
    Chef(["barger3"], "akash6", "jhenaidha", 3000).set_work_time({"sun": 4, "mon": 5})

    # resturent.show_employ()
    resturent.assign_menu_items("barger10", 4)
    resturent.assign_menu_items("pizza")
    resturent.show_employ()


if __name__ == "__main__":
    main()
