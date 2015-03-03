# A* Shortest Path Algorithm
# http://en.wikipedia.org/wiki/A*
# FB - 201012256
from heapq import heappush, heappop # for priority queue
import math
import time
import random
import serial

class node:
    xPos = 0 # x position
    yPos = 0 # y position
    distance = 0 # total distance already travelled to reach the node
    priority = 0 # priority = distance + remaining distance estimate
    def __init__(self, xPos, yPos, distance, priority):
        self.xPos = xPos
        self.yPos = yPos
        self.distance = distance
        self.priority = priority
    def __lt__(self, other): # comparison method for priority queue
        return self.priority < other.priority
    def updatePriority(self, xDest, yDest):
        self.priority = self.distance + self.estimate(xDest, yDest) * 10 # A*
    # give higher priority to going straight instead of diagonally
    def nextMove(self, dirs, d): # d: direction to move
        if dirs == 8 and d % 2 != 0:
            self.distance += 14
        else:
            self.distance += 10
    # Estimation function for the remaining distance to the goal.
    def estimate(self, xDest, yDest):
        xd = xDest - self.xPos
        yd = yDest - self.yPos
        # Euclidian Distance
        d = math.sqrt(xd * xd + yd * yd)
        # Manhattan distance
        # d = abs(xd) + abs(yd)
        # Chebyshev distance
        # d = max(abs(xd), abs(yd))
        return(d)

# A-star algorithm.
# The path returned will be a string of digits of directions.
def pathFind(the_map, n, m, dirs, dx, dy, xA, yA, xB, yB):
    print "parto da",yA,xA ,"arrivo a ",yB,xB
    closed_nodes_map = [] # map of closed (tried-out) nodes
    open_nodes_map = [] # map of open (not-yet-tried) nodes
    dir_map = [] # map of dirs
    row = [0] * n
    pathFind.ArrayX=[]
    pathFind.ArrayY=[]
    for i in range(m): # create 2d arrays
        closed_nodes_map.append(list(row))
        open_nodes_map.append(list(row))
        dir_map.append(list(row))

    pq = [[], []] # priority queues of open (not-yet-tried) nodes
    pqi = 0 # priority queue index
    # create the start node and push into list of open nodes
    n0 = node(xA, yA, 0, 0)
    n0.updatePriority(xB, yB)
    heappush(pq[pqi], n0)
    open_nodes_map[yA][xA] = n0.priority # mark it on the open nodes map

    # A* search
    while len(pq[pqi]) > 0:
        # get the current node w/ the highest priority
        # from the list of open nodes
        n1 = pq[pqi][0] # top node
        n0 = node(n1.xPos, n1.yPos, n1.distance, n1.priority)
        x = n0.xPos
        y = n0.yPos
        heappop(pq[pqi]) # remove the node from the open list
        open_nodes_map[y][x] = 0
        closed_nodes_map[y][x] = 1 # mark it on the closed nodes map

        # quit searching when the goal is reached
        # if n0.estimate(xB, yB) == 0:
        if x == xB and y == yB:
            # generate the path from finish to start
            # by following the dirs
            path = ''
            while not (x == xA and y == yA):
                print "x:",y,"y:",x
                j = dir_map[y][x]
                c = str((j + dirs / 2) % dirs)
                path = c + path
                x += dx[j]
                y += dy[j]
                pathFind.ArrayY.append(x)
                pathFind.ArrayX.append(y)
            return path

        # generate moves (child nodes) in all possible dirs
        for i in range(dirs):
            xdx = x + dx[i]
            ydy = y + dy[i]
            if not (xdx < 0 or xdx > n-1 or ydy < 0 or ydy > m - 1
                    or the_map[ydy][xdx] == 1 or closed_nodes_map[ydy][xdx] == 1):
                # generate a child node
                m0 = node(xdx, ydy, n0.distance, n0.priority)
                m0.nextMove(dirs, i)
                m0.updatePriority(xB, yB)
                # if it is not in the open list then add into that
                if open_nodes_map[ydy][xdx] == 0:
                    open_nodes_map[ydy][xdx] = m0.priority
                    heappush(pq[pqi], m0)
                    # mark its parent node direction
                    dir_map[ydy][xdx] = (i + dirs / 2) % dirs
                elif open_nodes_map[ydy][xdx] > m0.priority:
                    # update the priority
                    open_nodes_map[ydy][xdx] = m0.priority
                    # update the parent direction
                    dir_map[ydy][xdx] = (i + dirs / 2) % dirs
                    # replace the node
                    # by emptying one pq to the other one
                    # except the node to be replaced will be ignored
                    # and the new node will be pushed in instead
                    while not (pq[pqi][0].xPos == xdx and pq[pqi][0].yPos == ydy):
                        heappush(pq[1 - pqi], pq[pqi][0])
                        heappop(pq[pqi])
                    heappop(pq[pqi]) # remove the target node
                    # empty the larger size priority queue to the smaller one
                    if len(pq[pqi]) > len(pq[1 - pqi]):
                        pqi = 1 - pqi
                    while len(pq[pqi]) > 0:
                        heappush(pq[1-pqi], pq[pqi][0])
                        heappop(pq[pqi])
                    pqi = 1 - pqi
                    heappush(pq[pqi], m0) # add the better node instead
    return '' # if no route found

def ShowMap(m,n,the_map):
    print 'Map:'
    for y in range(m):
        for x in range(n):
            xy = the_map[y][x]
            if xy == 0:
                print '.', # space
            elif xy == 1:
                print 'O', # obstacle
            elif xy == 2:
                print 'S', # start
            elif xy == 3:
                print 'R', # route
            elif xy == 4:
                print 'F', # finish
        print





def FindObstacles(the_Obstacles_map, xB, yB):
    #apro la seriale di arduino
    lettura=1
    ostacolo=0
    if lettura < 30:
        the_Obstacles_map[xB][yB]=1
        ostacolo=1
    return ostacolo








# MAIN
dirs = 8
# number of possible directions to move on the map
if dirs == 4:
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
elif dirs == 8:
    dx = [1, 1, 0, -1, -1, -1, 0, 1]
    dy = [0, 1, 1, 1, 0, -1, -1, -1]

n = 30 # horizontal size of the map
m = 30 # vertical size of the map
the_map = []

#dichiaro una seconda mappa che conterra gli ostacoli incontrati
the_Obstacles_map = []

#creo le mappe vuote
row = [0] * n
for i in range(m):
    the_map.append(list(row))
    the_Obstacles_map.append(list(row))

# fillout the map with a '+' pattern
"""
for x in range(n / 8, n * 7 / 8):
    the_map[m /2][x] = 1
for y in range(m/8, m * 7 / 8):
    the_map[y][n / 2] = 1
"""

# randomly select start and finish locations from a list
sf = []
sf.append((0, 0, n - 1, m - 1))
sf.append((0, m - 1, n - 1, 0))
sf.append((n / 2 - 1, m / 2 - 1, n / 2 + 1, m / 2 + 1))
sf.append((n / 2 - 1, m / 2 + 1, n / 2 + 1, m / 2 - 1))
sf.append((n / 2 - 1, 0, n / 2 + 1, m - 1))
sf.append((n / 2 + 1, m - 1, n / 2 - 1, 0))
sf.append((0, m / 2 - 1, n - 1, m / 2 + 1))
sf.append((n - 1, m / 2 + 1, 0, m / 2 - 1))
#(xA, yA, xB, yB) = random.choice(sf)
xA=16
yA=29
xB=14
yB=0

print 'Map size (X,Y): ', n, m
print 'Start: ', yA, xA
print 'Finish: ', yB, xB
t = time.time()
route = pathFind(the_map, n, m, dirs, dx, dy, xA, yA, xB, yB)
print 'Tempo trascorso per effettuare la stima in secondi: ', time.time() - t
print 'Percorso ottimale stimato:'
print route

# mark the route on the map
if len(route) > 0:
    x = xA
    y = yA
    the_map[y][x] = 2
    for i in range(len(route)):
        j = int(route[i])
        x += dx[j]
        y += dy[j]
        the_map[y][x] = 3
    the_map[y][x] = 4

# display the map with the route added
ShowMap(m,n,the_map)

raw_input("Percorso minimo calcolato")
x= pathFind.ArrayX[len(pathFind.ArrayX)-1]
y= pathFind.ArrayY[len(pathFind.ArrayY)-1]
percorso = ""
print "provo a raggiungere ",xB,yB,"seguendo il percorso"
j=1
#seriale = serial.Serial("COM5", 57600, 8, "N", 1, timeout=1)
#arduino = serial.Serial("COM6", 9600, 8, "N", 1, timeout=1)
while j<len(route):
    if route[j-1:j] == '0':
        print "provo ad andare a destra ",route[j-1:j]
        #posizione attuale
        x = pathFind.ArrayX[len(pathFind.ArrayX)-j]
        y = pathFind.ArrayY[len(pathFind.ArrayY)-j]
        print "j:",j

        #quadratino di arrivo
        xP = x
        yP = y+1

        #cerco eventuali ostacoli tra il punto di partenza e quello di arrivo
        #ostacolo=FindObstacles(the_Obstacles_map, xP, yP)
        ostacolo=0
        #Muovo il sensore nelle tre direzioni, avro tre valori
        #Obstacles conterra le posizioni frontale, sinistra e destra rispetto
        #alla mia posizione attuale
        if ostacolo !=1:
            #se nella direzione che devo andare non ho ostacoli proseguo
            #m muovo, write sulla seriale Rotazione di 60 gradi circa a destra, e avanti
            #questo if serve a controllare se e la prima volta che si effettua la rotazione
            #altrimenti il rover ruoterebbe ad ogni comando di 60 gradi per andare in basso a destra
            if route[j-2:j-1]!=1:
                #seriale.write("\x7b\x01\x52\x20\xf6\xa0\xf6\xa0\x00\x00\x21\x72\x7d")
                time.sleep(0.3)
                #seriale.write("\x7b\x01\x52\x20\xf6\xa0\xf6\xa0\x00\x00\x21\x72\x7d")

            #Avanti di 28 cm
            #seriale.write("\x7b\x01\x52\x20\x09\x60\xf6\xa0\x00\x00\x21\x72\x7d")
            #memorizzo il percorso, cioe faccio un append
            percorso = percorso + route[j-1:j]
            #aggiorno l indice
            j = j + 1
        else:
            #mostro la mappa con l'ostacolo
            print "Mostro la mappa con gli ostacoli: "
            ShowMap(30,30,the_Obstacles_map)
            raw_input("Ricalcolo ed evito l'ostacolo....")
            #Ricalcolo
            route2 = pathFind(the_Obstacles_map, n, m, dirs, dx, dy, y, x, xB, yB)
            print "percorso attuale:", route2
            j = j + 1


    elif route[j-1:j] == '1':
        print "provo ad andare in diagonale in basso a destra", route[j-1:j]
        #posizione attuale
        x = pathFind.ArrayX[len(pathFind.ArrayX)-j]
        y = pathFind.ArrayY[len(pathFind.ArrayY)-j]
        print "j:",j

        #quadratino di arrivo
        xP = x+1
        yP = y+1

        #cerco eventuali ostacoli tra il punto di partenza e quello di arrivo
        #ostacolo=FindObstacles(the_Obstacles_map, xP, yP)
        ostacolo=0
        #Muovo il sensore nelle tre direzioni, avro tre valori
        #Obstacles conterra le posizioni frontale, sinistra e destra rispetto
        #alla mia posizione attuale
        if ostacolo !=1:
            #se nella direzione che devo andare non ho ostacoli proseguo
            #m muovo, write sulla seriale Rotazione di 60 gradi circa a destra, e avanti
            #questo if serve a controllare se e la prima volta che si effettua la rotazione
            #altrimenti il rover ruoterebbe ad ogni comando di 60 gradi per andare in basso a destra
            if route[j-2:j-1]!=1:
                #seriale.write("\x7b\x01\x52\x20\xf6\xa0\xf6\xa0\x00\x00\x21\x72\x7d")
                time.sleep(0.3)
                #seriale.write("\x7b\x01\x52\x20\xf6\xa0\xf6\xa0\x00\x00\x21\x72\x7d")

            #Avanti di 28 cm
            #seriale.write("\x7b\x01\x52\x20\x09\x60\xf6\xa0\x00\x00\x21\x72\x7d")
            #memorizzo il percorso, cioe faccio un append
            percorso = percorso + route[j-1:j]
            #aggiorno l indice
            j = j + 1
        else:
            #mostro la mappa con l'ostacolo
            print "Mostro la mappa con gli ostacoli: "
            ShowMap(30,30,the_Obstacles_map)
            raw_input("Ricalcolo ed evito l'ostacolo....")
            #Ricalcolo
            route2 = pathFind(the_Obstacles_map, n, m, dirs, dx, dy, y, x, xB, yB)
            print "percorso attuale:", route2
            j = j + 1


    elif route[j-1:j] == '2':
        print "provo ad andare in basso",route[j-1:j]
        #posizione attuale
        x = pathFind.ArrayX[len(pathFind.ArrayX)-j]
        y = pathFind.ArrayY[len(pathFind.ArrayY)-j]
        print "j:",j

        #quadratino di arrivo
        xP = x+1
        yP = y

        #cerco eventuali ostacoli tra il punto di partenza e quello di arrivo
        #ostacolo=FindObstacles(the_Obstacles_map, xP, yP)
        ostacolo=0
        #Muovo il sensore nelle tre direzioni, avro tre valori
        #Obstacles conterra le posizioni frontale, sinistra e destra rispetto
        #alla mia posizione attuale
        if ostacolo !=1:
            #se nella direzione che devo andare non ho ostacoli proseguo
            #m muovo, write sulla seriale Rotazione di 60 gradi circa a destra, e avanti
            #questo if serve a controllare se e' la prima volta che si effettua la rotazione
            #altrimenti il rover ruoterebbe ad ogni comando di 90 gradi per andare in basso a destra
            if route[j-2:j-1]!=2:
                #seriale.write("\x7b\x01\x52\x20\xf6\xa0\xf6\xa0\x00\x00\x21\x72\x7d")
                time.sleep(0.3)
                #seriale.write("\x7b\x01\x52\x20\xf6\xa0\xf6\xa0\x00\x00\x21\x72\x7d")
                time.sleep(0.3)
                #seriale.write("\x7b\x01\x52\x20\xf6\xa0\xf6\xa0\x00\x00\x21\x72\x7d")

            #Avanti di 28 cm
            #seriale.write("\x7b\x01\x52\x20\x09\x60\xf6\xa0\x00\x00\x21\x72\x7d")
            #memorizzo il percorso, cioe faccio un append
            percorso = percorso + route[j-1:j]
            #aggiorno l indice
            j = j + 1
        else:
            #mostro la mappa con l'ostacolo
            print "Mostro la mappa con gli ostacoli: "
            ShowMap(30,30,the_Obstacles_map)
            raw_input("Ricalcolo ed evito l'ostacolo....")
            #Ricalcolo
            route2 = pathFind(the_Obstacles_map, n, m, dirs, dx, dy, y, x, xB, yB)
            print "percorso attuale:", route2
            j = j + 1

    elif route[j-1:j] == '3':
        print "provo ad andare in diagonale in basso a sinistra",route[j-1:j]
        #posizione attuale
        x = pathFind.ArrayX[len(pathFind.ArrayX)-j]
        y = pathFind.ArrayY[len(pathFind.ArrayY)-j]
        print "j:",j

        #quadratino di arrivo
        xP = x+1
        yP = y-1

        #cerco eventuali ostacoli tra il punto di partenza e quello di arrivo
        #ostacolo=FindObstacles(the_Obstacles_map, xP, yP)
        ostacolo=0
        #Muovo il sensore nelle tre direzioni, avro tre valori
        #Obstacles conterra le posizioni frontale, sinistra e destra rispetto
        #alla mia posizione attuale
        if ostacolo !=1:
            #se nella direzione che devo andare non ho ostacoli proseguo
            #m muovo, write sulla seriale Rotazione di 60 gradi circa a destra, e avanti
            #questo if serve a controllare se e la prima volta che si effettua la rotazione
            #altrimenti il rover ruoterebbe ad ogni comando di 60 gradi per andare in basso a sinistra
            if route[j-2:j-1]!=3:
                #seriale.write("\x7b\x01\x52\x20\x09\x60\x09\x60\x00\x00\x21\x72\x7d")
                time.sleep(0.3)
                #seriale.write("\x7b\x01\x52\x20\x09\x60\x09\x60\x00\x00\x21\x72\x7d")

            #Avanti di 28 cm
            #seriale.write("\x7b\x01\x52\x20\x09\x60\xf6\xa0\x00\x00\x21\x72\x7d")
            #memorizzo il percorso, cioe faccio un append
            percorso = percorso + route[j-1:j]
            #aggiorno l indice
            j = j + 1
        else:
            #mostro la mappa con l'ostacolo
            print "Mostro la mappa con gli ostacoli: "
            ShowMap(30,30,the_Obstacles_map)
            raw_input("Ricalcolo ed evito l'ostacolo....")
            #Ricalcolo
            route2 = pathFind(the_Obstacles_map, n, m, dirs, dx, dy, y, x, xB, yB)
            print "percorso attuale:", route2
            j = j + 1

    elif route[j-1:j]== '4':
        print "provo ad andare a sinistra",route[j-1:j]
        #posizione attuale
        x = pathFind.ArrayX[len(pathFind.ArrayX)-j]
        y = pathFind.ArrayY[len(pathFind.ArrayY)-j]
        print "j:",j

        #quadratino di arrivo
        xP = x
        yP = y-1

        #cerco eventuali ostacoli tra il punto di partenza e quello di arrivo
        #ostacolo=FindObstacles(the_Obstacles_map, xP, yP)
        ostacolo=0
        #Muovo il sensore nelle tre direzioni, avro tre valori
        #Obstacles conterra le posizioni frontale, sinistra e destra rispetto
        #alla mia posizione attuale
        if ostacolo !=1:
            #se nella direzione che devo andare non ho ostacoli proseguo
            #m muovo, write sulla seriale Rotazione di 60 gradi circa a destra, e avanti
            #questo if serve a controllare se e la prima volta che si effettua la rotazione
            #altrimenti il rover ruoterebbe ad ogni comando di 45 gradi per andare a sinistra
            if route[j-2:j-1]!=4:
                #seriale.write("\x7b\x01\x52\x20\x09\x60\x09\x60\x00\x00\x21\x72\x7d")
                time.sleep(0.3)
                #seriale.write("\x7b\x01\x52\x20\x09\x60\x09\x60\x00\x00\x21\x72\x7d")

            #Avanti di 28 cm
            #seriale.write("\x7b\x01\x52\x20\x09\x60\xf6\xa0\x00\x00\x21\x72\x7d")
            #memorizzo il percorso, cioe faccio un append
            percorso = percorso + route[j-1:j]
            #aggiorno l indice
            j = j + 1
        else:
            #mostro la mappa con l'ostacolo
            print "Mostro la mappa con gli ostacoli: "
            ShowMap(30,30,the_Obstacles_map)
            raw_input("Ricalcolo ed evito l'ostacolo....")
            #Ricalcolo
            route2 = pathFind(the_Obstacles_map, n, m, dirs, dx, dy, y, x, xB, yB)
            print "percorso attuale:", route2
            j = j + 1

    elif route[j-1:j] == '5':
        print "provo ad andare in diagonale in alto a sinistra",route[j-1:j]
        #posizione attuale
        x = pathFind.ArrayX[len(pathFind.ArrayX)-j]
        y = pathFind.ArrayY[len(pathFind.ArrayY)-j]
        print "j:",j

        #quadratino di arrivo
        xP = x-1
        yP = y-1

        #cerco eventuali ostacoli tra il punto di partenza e quello di arrivo
        ostacolo=FindObstacles(the_Obstacles_map, xP, yP)

        #Muovo il sensore nelle tre direzioni, avro tre valori
        #Obstacles conterra le posizioni frontale, sinistra e destra rispetto
        #alla mia posizione attuale
        if ostacolo !=1:
            #se nella direzione che devo andare non ho ostacoli proseguo
            #m muovo, write sulla seriale Rotazione di 60 gradi circa a destra, e avanti
            #questo if serve a controllare se e la prima volta che si effettua la rotazione
            #altrimenti il rover ruoterebbe ad ogni comando di 45 gradi per andare in alto a sinistra
            if route[j-2:j-1]!=5:
                #seriale.write("\x7b\x01\x52\x20\x09\x60\x09\x60\x00\x00\x21\x72\x7d")
                time.sleep(0.3)
                #seriale.write("\x7b\x01\x52\x20\x09\x60\x09\x60\x00\x00\x21\x72\x7d")

            #Avanti di 28 cm
            #seriale.write("\x7b\x01\x52\x20\x09\x60\xf6\xa0\x00\x00\x21\x72\x7d")
            #memorizzo il percorso, cioe faccio un append
            percorso = percorso + route[j-1:j]
            #aggiorno l indice
            j = j + 1
        else:
            #mostro la mappa con l'ostacolo
            print "Mostro la mappa con gli ostacoli: "
            ShowMap(30,30,the_Obstacles_map)
            raw_input("Ricalcolo ed evito l'ostacolo....")
            #Ricalcolo
            route2 = pathFind(the_Obstacles_map, n, m, dirs, dx, dy, y, x, xB, yB)
            print "percorso attuale:", route2
            j = j + 1
            break

    elif route[j-1:j]== '6':
        print "provo ad andare in avanti",route[j-1:j]
        #posizione attuale

        x = pathFind.ArrayX[len(pathFind.ArrayX)-j]
        y = pathFind.ArrayY[len(pathFind.ArrayY)-j]
        print "j:",j


        #quadratino di arrivo
        xP = x-1
        yP = y

        #cerco eventuali ostacoli tra il punto di partenza e quello di arrivo
        #ostacolo=FindObstacles(the_Obstacles_map, xP, yP)
        ostacolo=0

        #Muovo il sensore nelle tre direzioni, avro tre valori
        #Obstacles conterra le posizioni frontale, sinistra e destra rispetto
        #alla mia posizione attuale
        if ostacolo !=1:
            #se nella direzione che devo andare non ho ostacoli proseguo
            j = j + 1
            #m muovo, write sulla seriale Avanti 40 (circa 28 cm)
            #seriale.write("\x7b\x01\x52\x20\x09\x60\xf6\xa0\x00\x00\x21\x72\x7d")
            #memorizzo il percorso, cioe faccio un append
            percorso = percorso + route[j-1:j]
        else:
            #ricalcolo
            #Determino le mie coordinate
            #x= ArrayX[len(ArrayX)-j]
            #y= ArrayY[len(ArrayY)-j]
            #Obstacles = CheckObstacles(the_Obstacles_map,x,y)

            #mostro la mappa con l'ostacolo
            print "Mostro la mappa con gli ostacoli: "
            ShowMap(30,30,the_Obstacles_map)
            raw_input("Ricalcolo ed evito l'ostacolo....")
            #Ricalcolo
            print "x:",y,"y:",x
            route2 = pathFind(the_Obstacles_map, n, m, dirs, dx, dy, y, x, xB, yB)
            print "percorso attuale:", route2
            j = j + 1





    elif route[j-1:j] == '7':
        print "provo ad andare in diagonale in alto a destra",route[j-1:j]
         #posizione attuale
        x = pathFind.ArrayX[len(pathFind.ArrayX)-j]
        y = pathFind.ArrayY[len(pathFind.ArrayY)-j]
        print "j:",j

        #quadratino di arrivo
        xP = x-1
        yP = y+1

        #cerco eventuali ostacoli tra il punto di partenza e quello di arrivo
        #ostacolo=FindObstacles(the_Obstacles_map, xP, yP)
        ostacolo=0
        #Muovo il sensore nelle tre direzioni, avro tre valori
        #Obstacles conterra le posizioni frontale, sinistra e destra rispetto
        #alla mia posizione attuale
        if ostacolo !=1:
            #se nella direzione che devo andare non ho ostacoli proseguo
            #m muovo, write sulla seriale Rotazione di 60 gradi circa a destra, e avanti
            #questo if serve a controllare se e la prima volta che si effettua la rotazione
            #altrimenti il rover ruoterebbe ad ogni comando di 45 gradi per andare in alto a sinistra
            if route[j-2:j-1]!=7:
                #seriale.write("\x7b\x01\x52\x20\xf6\xa0\xf6\xa0\x00\x00\x21\x72\x7d")
                time.sleep(0.3)
                #seriale.write("\x7b\x01\x52\x20\xf6\xa0\xf6\xa0\x00\x00\x21\x72\x7d")

            #Avanti di 28 cm
            #seriale.write("\x7b\x01\x52\x20\x09\x60\xf6\xa0\x00\x00\x21\x72\x7d")
            #memorizzo il percorso, cioe faccio un append
            percorso = percorso + route[j-1:j]
            #aggiorno l indice
            j = j + 1
        else:
            #mostro la mappa con l'ostacolo
            print "Mostro la mappa con gli ostacoli: "
            ShowMap(30,30,the_Obstacles_map)
            raw_input("Ricalcolo ed evito l'ostacolo....")
            #Ricalcolo
            route2 = pathFind(the_Obstacles_map, n, m, dirs, dx, dy, y, x, xB, yB)
            print "percorso attuale:", route2
            j = j + 1
print "Goal"


# mark the route on the map
if len(percorso) > 0:
    x = xA
    y = yA
    the_Obstacles_map[y][x] = 2
    for i in range(len(percorso)):
        j = int(percorso[i])
        x += dx[j]
        y += dy[j]
        the_Obstacles_map[y][x] = 3
    the_Obstacles_map[y][x] = 4


print "partiva da :",y,x, "goal: ",yB,xB
print 'percorso:'
print percorso
# display the map with the route added
ShowMap(m, n, the_Obstacles_map)

