
import time
import random

#Need to hide cursor
# cursor = curses.initscr()
# curses.curs_set(0)
# #restores default settings
# curses.curs_set(1)
# curses.endwin()

#Here we clean the screen
def clear():
    print("\033[2J\033[;H")
    # os.system('clear||cls')
#Makes delay before next command
def delay(sec):
    time.sleep(sec)

#Just draws a string
def draw(content, delayTime):
    clear()
    print(content)
    delay(delayTime)

#Draws thw whole field
def drawField(content, delayTime):
    clear()
    for y in range(len(content)):
        for x in range(len(content[y])):
            print(content[y][x], end='')
        print(' ')
    delay(delayTime)

#Return empty field
def getEmptyField(height, widht, char):
    field = []
    for y in range(height):
        field.append([])
        for x in range(widht):
            if y == 0 or x == 0 or y == height-1 or x == widht-1:
                field[y].append('#')
            else:
                field[y].append(char)
    return field

#Here we define size of our field and create it
print("Input zero for default values")
height = int(input('Enter height of field: '))
widht = int(input('Enter widht of field: '))

if height == 0 or widht == 0:
    height = 20
    widht = 35

field = getEmptyField(height, widht, ' ')

#Two classes to make it easier to store data
class Vector:
    def __init__(self, x,y):
        self.y = y
        self.x = x
class Ball:
    def defaultColor(self):
        return '\033[37m'
    def __init__(self, x, y, vector, char, color):
        self.x = x
        self.y = y
        self.vector = vector
        self.__char = char
        self.__color = color

    def char(self):
        return self.__color+self.__char+self.defaultColor()

balls = []
colours = [
    '\033[30m',
    '\033[31m',
    '\033[32m',
    '\033[33m',
    '\033[34m',
    '\033[35m',
    '\033[36m',
    '\033[37m',
]

#Here we need to get chars
ballsChar = input('Enter chars for balls to draw: ').split()
if len(ballsChar) < 1:
    ballsChar = ['@', '0', 'o', 'O']

balls_amount = int(input('Enter amount of balls: '))
if balls_amount == 0:
    balls_amount = 15
speed = float(input('Enter speed of each step in seconds. default=0.05 : '))
if speed == 0:
    speed = 0.05

for i in range(balls_amount):
    balls.append(Ball(
        random.randint(1, widht-2),
        random.randint(1, height-2),
        Vector(random.randint(-1, 1), random.randint(-1, 1)),
        ballsChar[random.randint(0, len(ballsChar) - 1)],
        colours[random.randint(0, len(colours) - 1)]
    ))
for i in range(1000):
    for ball in balls:
        ball.x += ball.vector.x * random.randint(0,1)
        ball.y += ball.vector.y * random.randint(0,1)

        if ball.y == height-1 or ball.y < 1:
            ball.vector.y *= -1
            ball.y += ball.vector.y
        if ball.x == widht-1 or ball.x < 1:
            ball.vector.x *= -1
            ball.x += ball.vector.x
        field[ball.y][ball.x] = ball.char()

    #delay in second before new frame
    drawField(field, speed)
    field = getEmptyField(height, widht, ' ')
