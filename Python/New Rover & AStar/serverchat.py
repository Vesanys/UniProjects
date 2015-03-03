# -*- coding: iso-8859-15 -*-
from twisted.internet import reactor, protocol
import traceback,sys
def NomiSocketDisponibili(Sockets):
        Lista = []
        for i in Sockets.keys():
            if Sockets[i]:
                Lista.append(i)
        return Lista

def EliminaSocket(Socket, SocketDaEliminare):
    for i in Socket.keys():
        if Socket[i] == SocketDaEliminare:
            Socket[i] = ""

class Echo(protocol.Protocol):
    """This is just about the simplest possible protocol"""
    global NomeController,IndiceRover
    def connectionMade(self):
        print "Got new client!"

    def connectionLost(self, reason):
        print "Lost a client!"
        if self in ControllerClients:
                print "Un Controller si e' disconnesso"
                #print AVAIBLE_ROV
                ControllerClients.remove(self)
                try:
                    #Aggiungo alla lista delle socket disponibili la socket del Rover che era controllato dal Controller disconnesso
                    #lista.append(BUSY_SOCK[NomeRover])
                    #Aggiungo al dizionario delle socket disponibili la socket del Rover che era controllato dal Controller disconnesso
                    for i in RoverClients.keys():
                        if RoverClients[i]== self:
                            NomeRover = i

                    SocketR[NomeRover] = BusySock[NomeRover]
                    print "Nome Socket del rover tornato disponibile ", NomeRover
                    #Elimino dal dizionario delle socket occupate la coppia NomeRover:Socket che ora è divenuta disponibile
                    del BusySock[NomeRover]
                except:
                    exc_type, exc_value, exc_traceback = sys.exc_info()
                    traceback.print_exception(exc_type, exc_value, exc_traceback, limit=2, file=sys.stdout)


        elif self in RoverClients:
            print "Un Rover si e' disconnesso"
            RoverClients.remove(self)
            #Elimino il Socket del Rover disconnesso dalla lista dei Rover disponibili al Controller
            EliminaSocket(SocketR, self)




    
    def dataReceived(self, data):
        #print "Rivevuto: ", data[0:3]

        try:
            if data[13:18] == "Rover":
                print "Si e connesso un rover: ", data
                RoverClients.append(self)
                #Ricavo la posizione dove inserire la socket nel Dizionario preparato per le coppie (NomeRover : SocketRover)
                posizione = 0

                for x in SocketR.keys():
                    if SocketR[x]:
                        posizione += 1

                #Aggiungo la socket al Rover nella posizione corretta
                SocketR["Rov" + str(posizione + 1)] = self
                #Recupero la lista dei Rover disponibili che sarà poi inviata ai controller
                lista = NomiSocketDisponibili(SocketR)
                #Controllo se per caso vi è un Controller libero in attesa di un Rover, in caso affermativo comunico la mia presenza
                """
                for x in self.factory.SocketC.keys():
                    if self.factory.SocketC[x]:
                        Controller = self.factory.SocketC.get(x)
                        #print Controller
                        IndiceController = self.factory.ControllerClients.index(Controller)
                        #print IndiceController
                        #print CONNECTION_CONTROLLER_LIST[IndiceController]
                        self.factory.ControllerClients[IndiceController].transport.write(str(lista))
                 """



            elif data[13:23] == "Controller":
                print "Si e connesso un Controller: ", data
                #Aggiungo la socket del controller alla lista delle socket per i controller
                ControllerClients.append(self)
                #Ricavo la posizione dove inserire la socket nel Dizionario preparato per le coppie (NomeController : SocketController)
                pos = 0

                for x in SocketC.keys():
                    if SocketC[x]:
                        pos += 1

                #Definisco il nome del controller
                Echo.NomeController = "Cont" + str(pos + 1)
                NomeController = Echo.NomeController
                #Inserisco la socket nella posizione corretta
                SocketC[NomeController] = self
                #Ogni volta che si collega un nuovo controller ottengo la lista dei rover disponibili
                lista = NomiSocketDisponibili(SocketR)
                #Invio la lista dei rover disponibili
                self.transport.write("lista: " + str(lista))

            elif data[0:8] == 'Scelta: ':
                print "Rover scelto: "+ data[8:12]
                #Imposto la socket del rover da controllare
                NomeRover = data[8:12]
                RoverDaControllare = SocketR.get(NomeRover)
                #Ricavo l'indice di posizione della socket del rover da controllare nella lista delle socket dei rover connessi
                Echo.IndiceRover = RoverClients.index(RoverDaControllare)
                #Inserisco il socket del rover da governare nella lista dei socket "occupati"
                BusySock[NomeRover] = SocketR.get(NomeRover)
                #Inserisco il socket del Controller associato al Rover da governare nella lista dei socket "occupati"
                BusySock[Echo.NomeController] = SocketC.get(Echo.NomeController)
                #Elimino la socket da SocketR
                EliminaSocket(SocketR, SocketR.get(NomeRover))
                #Elimino la socket del controller da SocketC(il dizionario dei socket dei controlleri disponibili)
                EliminaSocket(SocketC, SocketC.get(Echo.NomeController))
                #Comunico al controller che può iniziare la comunicazione
                self.transport.write("Inizia")
            elif data[0:3] == 'CMD':
                print "Inoltro Comando: " + data
                #print RoverClients[Echo.IndiceRover]
                RoverClients[Echo.IndiceRover].transport.write(data)
        except:
            exc_type, exc_value, exc_traceback = sys.exc_info()
            traceback.print_exception(exc_type, exc_value, exc_traceback, limit=2, file=sys.stdout)



def main():
    """This runs the protocol on port 8000"""
    factory = protocol.ServerFactory()
    global RoverClients, BusySock,ControllerClients,SocketR,SocketC
    RoverClients = []
    BusySock = {}
    ControllerClients = []
    SocketR = {"Rov1": "", "Rov2": "", "Rov3": "", "Rov4": "", "Rov5": "",
           "Rov6": "", "Rov7": "", "Rov8": "", "Rov9": "", "Rov10": ""}
    SocketC = {"Cont1": "", "Cont2": "", "Cont3": "", "Cont4": "", "Cont5": "",
           "Cont6": "", "Cont7": "", "Cont8": "", "Cont9": "", "Cont10": ""}
    factory.protocol = Echo
    reactor.listenTCP(8000,factory)
    reactor.run()



if __name__ == '__main__':
    main()