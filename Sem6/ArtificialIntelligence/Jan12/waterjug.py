import time

class JUG:
    volume = 0
    current = 0
    def __init__(self,water):
        self.volume = water
    def complete(self):
        self.current = self.volume
    def fill(self,water):
        if(self.current == self.volume or water > self.volume or (self.volume - self.current > water)):
            print("Already Full or cannot fill it up completely")
            return "error"
        else:
            current += water
            print(f'Moved {water}L water to JUG{self.volume}')
            return "success"
    def empty(self,water):
        if(self.current < water):
            print("Cannot empty more than there is.")
            return "error"
        else:
            current-=water
            return "success"

JUG3 = JUG(3)
JUG4 = JUG(4)
InitialState = {"Jug3":0,"Jug4":0}

def updateState():
    InitialState["Jug3"] = JUG3.current
    InitialState["Jug4"] = JUG4.current

def completelyTransfer(JUGsrc,JUGdst):
    vol = JUGsrc.current
    err1 = JUGsrc.empty(vol)
    err2 = JUGdst.fill(vol)
    if (err1 == "error" or err2 == "error"):
        return "error"
    else:
        updateState()
        return

def partialTransfer(JUGsrc, JUGdst,water):
    err1 = JUGsrc.empty(water)
    err2 = JUGdst.fill(water)
    if (err1 == "error" or err2 == "error"):
        return "error"
    else:
        updateState()
        return

