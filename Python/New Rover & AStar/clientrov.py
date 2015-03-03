# -*- coding: iso-8859-15 -*-
__author__ = 'josef.vitanostra'
from twisted.internet.protocol import ClientFactory
from twisted.protocols.basic import LineReceiver
from twisted.internet import reactor
import sys
import Comandi
import serial
import traceback
import time

# creo la seriale
def ComunicationSerial():
    try:
        ser = serial.Serial("/dev/ttyUSB0", 57600, 8, "N", 1, timeout=1)  # Seleziona la porta seriale COM4
    except serial.serialutil.SerialException:
        print("Porta seriale non disponibile")
    return ser




print "Rover 1.0 Client"


class EchoClient(LineReceiver):
    end = "Bye-bye!"
    flag=False
    ser=""


    def connectionMade(self):
        print"Connesso al server"
        self.sendLine("Hello,I am a Rover")
        #self.sendLine(self.end)


    def dataReceived(self, data):
        #print "receive:", data

        if data == self.end:
            self.transport.loseConnection()
        elif data[0:3] == "CMD":
            print "Ricevuto:", data[4:]
            if EchoClient.flag == False:
                EchoClient.ser = ComunicationSerial()
                if EchoClient.ser.isOpen():
                    com_num = EchoClient.ser.portstr
                    print ("Porta " + com_num + " aperta")
                    EchoClient.flag = True
            """
            Ciclo infinito di ricezione dei comandi inviati dal server
            dalla stringa ricevuta ricavo due informazioni:
            - Comando da eseguire (Avanti,Indietro,Sinistra,Destra)
            - Velocità
            Interrogo il dizionario attraverso l'indice ricavato dalla stringa ricevuta che indica la velocità
            ricavo la stringa esadecimale che converto in binario tramite binascii.unhexlify() e la
            invio al Rover attraverso la procedura write_om_serial
            """
            try:
               #print reply
               Velocita = int(data[11:])
               #print indice
               #print "Comando " + data[4:10] + " velocita : ", Velocita
               #print Comandi.ComandiAvanti[Velocita]
               if data[4:10] == "AVANTI":
                   #print "Ricevuto Avanti"
                   EchoClient.ser.write(Comandi.ComandiIndietro[Velocita])
               elif data[4:10] == "INDIET":
                   #print"Ricevuto Indietro"
                  EchoClient.ser.write(Comandi.ComandiIndietro[Velocita])
               elif data[4:10] == "SINIST":
                   #print"Ricevuto Sinistra"
                    EchoClient.ser.write(Comandi.ComandiIndietro[Velocita])
               elif data[4:10] == "DESTRA":
                   #print"Ricevuto Destra"
                    EchoClient.ser.write(Comandi.ComandiIndietro[Velocita])
            except:
               exc_type, exc_value, exc_traceback = sys.exc_info()
               traceback.print_exception(exc_type, exc_value, exc_traceback, limit=2, file=sys.stdout)


class EchoClientFactory(ClientFactory):
    protocol = EchoClient

    def clientConnectionFailed(self, connector, reason):
        print 'connection failed:', reason.getErrorMessage()
        reactor.stop()

    def clientConnectionLost(self, connector, reason):
        print 'connection lost:', reason.getErrorMessage()
        reactor.stop()

def Automatic():
    #apro la seriale alla quale è collegato arduino
    arduino = serial.Serial('COM5',9600,timeout=1)
    #apro la seriale alla quale è collegato il rover
    rover = ComunicationSerial()
    time.sleep(2)
    max = int(arduino.readline())
    #inizializzazione
    for i in range(1,3):
        #mi sposto a destra di 45°
        # rover.write(Comandi.ComandiDestra[30])
        if i==1:
            direzione = "destra"
        elif i==2:
            direzione = "indietro"
        else:
            direzione = "sinistra"

        lettura = int(arduino.readline())
        if lettura > max:
            max = lettura
            dir = direzione
        else:
            direzione = "avanti"

    if direzione == "avanti":
        rover.write(Comandi.ComandiAvanti[30])
    elif direzione == "sinistra":
        rover.write(Comandi.ComandiSinistra[30])
    elif direzione == "destra":
        rover.write(Comandi.ComandiDestra[30])
    else:
        rover.write(Comandi.ComandiIndietro[30])


    #comandi successivi all inizializzazione
    while True:
        lettura = arduino.readline()
        print "ho letto: " + lettura
        time.sleep(1)
        while (int(lettura) > 50):
            #rover.write(Comandi.ComandiAvanti[30])
            lettura = arduino.readline()

        #giro a destra e ricomincio
        #rover.erite(Comandi.ComandiDestra[30])




def main():

    factory = EchoClientFactory()
    scelta= raw_input("Modalità di esecuzione: ")
    if(scelta == "standalone"):
        Automatic()
    elif(scelta=="connect"):
        host = raw_input("Inserisci IP del Server: ")
        reactor.connectTCP(host, 8000, factory)
        reactor.run()


if __name__ == '__main__':
    main()