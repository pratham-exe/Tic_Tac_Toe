import tkinter as tk
import random
from tkinter.font import Font


def new_game():
    global player
    player = random.choice(players)
    label.config(text=player + " TURN")
    for row in range(3):
        for col in range(3):
            buttons[row][col].config(text="", bg="grey")


def check_free_space():
    free = 9
    for row in range(3):
        for col in range(3):
            if buttons[row][col]['text'] != "":
                free -= 1
    if free == 0:
        return False
    else:
        return True


def quit_xox():
    root.destroy()


def winner():
    for row in range(3):
        if buttons[row][0]['text'] == buttons[row][1]['text'] == buttons[row][2]['text'] != "":
            buttons[row][0].config(bg="green")
            buttons[row][1].config(bg="green")
            buttons[row][2].config(bg="green")
            return True
    for col in range(3):
        if buttons[0][col]['text'] == buttons[1][col]['text'] == buttons[2][col]['text'] != "":
            buttons[0][col].config(bg="green")
            buttons[1][col].config(bg="green")
            buttons[2][col].config(bg="green")
            return True
    if buttons[0][0]['text'] == buttons[1][1]['text'] == buttons[2][2]['text'] != "":
        buttons[0][0].config(bg="green")
        buttons[1][1].config(bg="green")
        buttons[2][2].config(bg="green")
        return True
    elif buttons[0][2]['text'] == buttons[1][1]['text'] == buttons[2][0]['text'] != "":
        buttons[0][2].config(bg="green")
        buttons[1][1].config(bg="green")
        buttons[2][0].config(bg="green")
        return True
    elif check_free_space() is False:
        for row in range(3):
            for col in range(3):
                buttons[row][col].config(bg="yellow")
        return "DRAW !"
    else:
        return False


def next_turn(row, col):
    global player
    if buttons[row][col]['text'] == "" and winner() is False:
        if player == players[0]:
            buttons[row][col]['text'] = player
            if winner() is True:
                label.config(text=players[0] + " CONGRATS YOU WON !")
            elif winner() is False:
                player = players[1]
                label.config(text=players[1] + " TURN")
            elif winner() == "DRAW !":
                label.config(text="DRAW !")
        else:
            buttons[row][col]['text'] = player
            if winner() is True:
                label.config(text=players[1] + " CONGRATS YOU WON !")
            elif winner() is False:
                player = players[0]
                label.config(text=players[0] + " TURN")
            elif winner() == "DRAW !":
                label.config(text="DRAW !")


root = tk.Tk()
root.title("Tic Tac Toe")
players = ['X', 'O']
player = random.choice(players)
my_font = Font(
    family='Times',
    size=50,
    weight='bold',
    slant='roman'
)
label = tk.Label(root, text=player + " TURN", font=my_font)
label.pack()
buttons = [[0, 0, 0],
           [0, 0, 0],
           [0, 0, 0]]
border = tk.Frame(root)
border.pack()
for row in range(3):
    for col in range(3):
        buttons[row][col] = tk.Button(border, text="", font=my_font, width=4, height=2, bg="grey", command=lambda row=row, col=col: next_turn(row, col))
        buttons[row][col].grid(row=row, column=col)
restart = tk.Button(root, text="RESTART", font=my_font, command=new_game)
restart.pack()
quit_game = tk.Button(root, text="QUIT", font=my_font, command=quit_xox)
quit_game.pack()
root.mainloop()
