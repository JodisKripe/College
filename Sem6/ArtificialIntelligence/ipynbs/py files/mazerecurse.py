import os
import random

n = 9
end = [7, 8]
path = [[0, 0]]
maze = [[0 for i in range(n)] for j in range(n)]
maze[0] = ["0", "0", "1", "1", "1", "1", "1", "1", "1"]
maze[1] = ["1", "0", "0", "0", "0", "1", "0", "0", "1"]
maze[2] = ["1", "0", "1", "1", "1", "0", "1", "0", "1"]
maze[3] = ["1", "0", "0", "1", "0", "0", "0", "0", "1"]
maze[4] = ["1", "0", "1", "1", "1", "1", "1", "0", "1"]
maze[5] = ["1", "0", "0", "0", "0", "0", "0", "0", "1"]
maze[6] = ["1", "0", "1", "1", "1", "1", "1", "0", "1"]
maze[7] = ["1", "0", "0", "1", "0", "0", "0", "0", "X"]
maze[8] = ["1", "1", "1", "1", "1", "1", "1", "1", "1"]

solved = False


def solve(maze, player, last_move):
    global solved
    if solved:
        return
    if player == end:
        print("Solved")
        raise SystemExit
        solved = True
        return
    else:
        # print(player)
        tmp = path
        if player[1] < n - 1 and (
            maze[player[0]][player[1] + 1] == "0"
            or maze[player[0]][player[1] + 1] == "X"
        ):
            player[1] += 1
            # print(player)
            if last_move != "LEFT":
                print("RIGHT")
                solve(maze, player, "RIGHT")
            else:
                player[1] -= 1
        else:
            pass
        if player[0] < n - 1 and (
            maze[player[0] + 1][player[1]] == "0"
            or maze[player[0] + 1][player[1]] == "X"
        ):
            player[0] += 1
            # print(player)
            if last_move != "UP":
                print("DOWN")
                solve(maze, player, "DOWN")
            else:
                player[0] -= 1
                pass
        if player[0] > 0 and (
            maze[player[0] - 1][player[1]] == "0"
            or maze[player[0] - 1][player[1]] == "X"
        ):
            player[0] -= 1
            # print(player)
            if last_move != "DOWN":
                print("UP")
                solve(maze, player, "UP")
            else:
                player[0] += 1
                pass
        if player[1] > 0 and (
            maze[player[0]][player[1] - 1] == "0"
            or maze[player[0]][player[1] - 1] == "X"
        ):
            player[1] -= 1
            # print(player)
            if last_move != "RIGHT":
                print("LEFT")
                solve(maze, player, "LEFT")
            else:
                player[1] += 1


start = [0, 0]
player = start
gloplayer = player
print(solve(maze, player, "None"))
