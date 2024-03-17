class JUG:
    volume = 0
    current = 0

    def __init__(self, water):
        self.volume = water

    def complete(self):
        self.current = self.volume

    def fill(self, water):
        if (self.current == self.volume) or (water > self.volume):
            print("Already Full or cannot fill it up completely")
            return "error"
        else:
            self.current += water
            print(f"Moved {water}L water to JUG{self.volume}")
            return "success"

    def empty(self, water):
        if self.current < water:
            print("Cannot empty more than there is.")
            return "error"
        else:
            self.current -= water
            return "success"


GoalState1 = {"Jug3": 0, "Jug4": 2}
GoalState2 = {"Jug3": 2, "Jug4": 0}


def updateState():
    CurrentState["Jug3"] = JUG3.current
    CurrentState["Jug4"] = JUG4.current


def completelyTransfer(JUGsrc, JUGdst, wat):
    err1 = JUGsrc.empty(wat)
    err2 = JUGdst.fill(wat)
    if err1 == "error" or err2 == "error":
        return "error"
    else:
        updateState()
        return


def topple(JUG):
    JUG.empty(JUG.current)
    updateState()
    return "OK"


Path = []
solved = False


def solve(JUG3, JUG4, Path):
    # print(Path)
    global solved
    if solved == True:
        return
    if CurrentState == GoalState1:
        print(f"Solved:\n{Path}")
        solved = True
        return
    if JUG3.current == 2:
        Path.append(f"JUG4 --> ground -- {JUG4.current}")
        topple(JUG4)
        Path.append(f"JUG3 --> JUG4 -- {JUG3.current}")
        JUG4.fill(JUG3.current)
        JUG3.empty(JUG3.current)
        updateState()
        solve(JUG3, JUG4, Path)
        return
    try:
        if Path[-1] == Path[-2]:
            return
        elif Path[-1] == Path[-3] and Path[-2] == Path[-4]:
            return
    except:
        pass
    JUG3.complete()
    wat = JUG3.current
    trans = JUG4.volume - JUG4.current if (JUG4.volume - JUG4.current) < wat else wat
    if trans == 0:
        Path.append(f"JUG4 --> ground -- {JUG4.current}")
        JUG4.empty(JUG4.current)
        trans = wat
    err = completelyTransfer(JUG3, JUG4, trans)
    if err != "error":
        Path.append(f"JUG3 -> JUG4 -- {wat}")
        solve(JUG3, JUG4, Path)
        Path.pop()

    stat = topple(JUG4)
    if stat == "OK":
        Path.append(f"JUG4 -> Throw -- {JUG4.current}")
        solve(JUG3, JUG4, Path)
        Path.pop()


JUG3 = JUG(3)
JUG4 = JUG(4)
CurrentState = {"Jug3": 0, "Jug4": 0}
solve(JUG3, JUG4, Path)
