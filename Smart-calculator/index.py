class History:
    undoStack = []
    redoStack = []

    def undo(self):
        if not self.undoStack:
            print("Empty!")
            return

        curr = self.undoStack.pop()
        print(*curr, sep="\n")
        History.redoStack.append(curr)

    def redo(self):
        if not self.redoStack:
            print("Empty!")
            return

        curr = self.redoStack.pop()
        print(*curr, sep="\n")
        History.undoStack.append(curr)

    def addToMemory(self, question, ans):
        History.undoStack.append((question, ans))

    def clearMemory(self):
        History.redoStack.clear()


class Calculator(History):

    def cal(self, inputStr):
        n = None

        try:
            n = eval(inputStr)
        except Exception as e:
            print("Error: ", e)

        if n:
            print(n)
            super().addToMemory(inputStr, n)
            super().clearMemory()

    def undo(self):
        return super().undo()

    def redo(self):
        return super().redo()


INPUT_PROMT = """
1) Input the equation.
2) Undo
3) Redo
4) Exit
-> """

calculator = Calculator()

while True:
    option = input(INPUT_PROMT)

    if option == "1":
        calculator.cal(input())
    elif option == "2":
        calculator.undo()
    elif option == "3":
        calculator.redo()
    elif option == "4":
        break
    else:
        print("Invalid input!")

