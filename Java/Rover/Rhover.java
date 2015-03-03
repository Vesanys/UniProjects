
/**
 *
 * @author josef
 */

/*
=======================================================================
* Class Rhover
* e' la classe principale che contiene la form, i tasti e tutti i 
* componenti necessari all'applicazione
=======================================================================
*/

public class Rhover extends javax.swing.JFrame {

    /**
    * Returns if there is a connection to the VMC established.
    *
    * @return true if there is a connection, otherwise false
    */
    public static native boolean isConnected();

    /**
     * Set the desi velocity for the motors of the drive.
     * The left value is being inverted for letting the left wheel drive
     * forward when getting positive values (which the right wheel does
     * without inverting).
     * @param velocityLeft the desired velocity for left motor
     *		at output 2 (-100 - +100)
     * @param velocityRight the desired velocity for right motor
     *		at output 1 (-100 - +100)
     */
    public static native void setMotors(int velocityLeft, int velocityRight);


    /*Caricamento della libreria per i metodi nativi*/
    static {
        System.loadLibrary("rhoverlib");
    }

    
    /*
=======================================================================
* Costruttore della classe Rhover
=======================================================================
*/
    public Rhover() {   
        //inizializzo tutti i componenti
         initComponents();
         //disabilito i tasti e altri componenti
         AreaOUTPUT.setEditable(false);
         ospitaButton .setEnabled(false);
         forwardButton.setEnabled(false);
         backButton.setEnabled(false);
         leftButton.setEnabled(false);
         rightButton.setEnabled(false);
         stopButton.setEnabled(false);
         tastieraReale.setEnabled(false);
         tastieraVirtuale.setEnabled(false);
         //imposto il colore del led che indica lo stato della connesisone 
         //a rosso
         labelStatoRV.setBackground(java.awt.Color.red);
         closeConnectionButton.setEnabled(false);
         plusButton.setEnabled(false);
         minusButton.setEnabled(false);
         
    }

  
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jSlider1 = new javax.swing.JSlider();
        buttonGroup1 = new javax.swing.ButtonGroup();
        buttonGroup2 = new javax.swing.ButtonGroup();
        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        sceltaStandAlone = new javax.swing.JRadioButton();
        SceltaClientServer = new javax.swing.JRadioButton();
        jSeparator1 = new javax.swing.JSeparator();
        forwardButton = new javax.swing.JButton();
        leftButton = new javax.swing.JButton();
        backButton = new javax.swing.JButton();
        stopButton = new javax.swing.JButton();
        rightButton = new javax.swing.JButton();
        labelStatoConnessione = new javax.swing.JLabel();
        jSeparator3 = new javax.swing.JSeparator();
        labelStatoRV = new javax.swing.JLabel();
        jSeparator2 = new javax.swing.JSeparator();
        ospitaButton = new javax.swing.JButton();
        jScrollPane2 = new javax.swing.JScrollPane();
        jScrollPane1 = new javax.swing.JScrollPane();
        AreaOUTPUT = new javax.swing.JTextArea();
        tastieraVirtuale = new javax.swing.JRadioButton();
        tastieraReale = new javax.swing.JRadioButton();
        jLabel2 = new javax.swing.JLabel();
        pulisciButton = new javax.swing.JButton();
        closeConnectionButton = new javax.swing.JButton();
        jLabel3 = new javax.swing.JLabel();
        RoverVelocity = new javax.swing.JLabel();
        minusButton = new javax.swing.JButton();
        plusButton = new javax.swing.JButton();
        choiceDevices = new java.awt.Choice();
        choiceFunctions = new java.awt.Choice();
        labelDispositivi = new javax.swing.JLabel();
        labelFunctions = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("VolksBot RT-6 Command Panel Ver. 2.0");
        setMinimumSize(new java.awt.Dimension(320, 240));

        jPanel1.setBackground(new java.awt.Color(75, 132, 217));

        jLabel1.setFont(new java.awt.Font("Comic Sans MS", 0, 14)); // NOI18N
        jLabel1.setText("Scegli il tipo di connessione");

        buttonGroup1.add(sceltaStandAlone);
        sceltaStandAlone.setFont(new java.awt.Font("Comic Sans MS", 0, 12)); // NOI18N
        sceltaStandAlone.setText("StandAlone");
        sceltaStandAlone.setOpaque(false);
        sceltaStandAlone.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                sceltaStandAloneActionPerformed(evt);
            }
        });

        buttonGroup1.add(SceltaClientServer);
        SceltaClientServer.setFont(new java.awt.Font("Comic Sans MS", 0, 12)); // NOI18N
        SceltaClientServer.setText("Client-Server");
        SceltaClientServer.setOpaque(false);
        SceltaClientServer.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                SceltaClientServerActionPerformed(evt);
            }
        });

        forwardButton.setFont(new java.awt.Font("Comic Sans MS", 1, 12)); // NOI18N
        forwardButton.setForeground(new java.awt.Color(204, 0, 51));
        forwardButton.setText("Avanti");
        forwardButton.setActionCommand("JButton1");
        forwardButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                forwardButtonActionPerformed(evt);
            }
        });

        leftButton.setFont(new java.awt.Font("Comic Sans MS", 1, 12)); // NOI18N
        leftButton.setForeground(new java.awt.Color(204, 0, 51));
        leftButton.setText("Sinistra");
        leftButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                leftButtonActionPerformed(evt);
            }
        });

        backButton.setFont(new java.awt.Font("Comic Sans MS", 1, 12)); // NOI18N
        backButton.setForeground(new java.awt.Color(204, 0, 51));
        backButton.setText("Dietro");
        backButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                backButtonActionPerformed(evt);
            }
        });

        stopButton.setFont(new java.awt.Font("Comic Sans MS", 1, 12)); // NOI18N
        stopButton.setForeground(new java.awt.Color(204, 0, 51));
        stopButton.setText("Stop");
        stopButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                stopButtonActionPerformed(evt);
            }
        });

        rightButton.setFont(new java.awt.Font("Comic Sans MS", 1, 12)); // NOI18N
        rightButton.setForeground(new java.awt.Color(204, 0, 51));
        rightButton.setText("Destra");
        rightButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                rightButtonActionPerformed(evt);
            }
        });

        labelStatoConnessione.setFont(new java.awt.Font("Comic Sans MS", 2, 14)); // NOI18N
        labelStatoConnessione.setText("Stato Connessione");

        jSeparator3.setOrientation(javax.swing.SwingConstants.VERTICAL);

        labelStatoRV.setBackground(new java.awt.Color(255, 255, 255));
        labelStatoRV.setText("        ");
        labelStatoRV.setOpaque(true);

        jSeparator2.setOrientation(javax.swing.SwingConstants.VERTICAL);

        ospitaButton.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        ospitaButton.setText("Ospita");
        ospitaButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ospitaButtonActionPerformed(evt);
            }
        });

        AreaOUTPUT.setColumns(20);
        AreaOUTPUT.setRows(5);
        jScrollPane1.setViewportView(AreaOUTPUT);

        jScrollPane2.setViewportView(jScrollPane1);

        buttonGroup2.add(tastieraVirtuale);
        tastieraVirtuale.setFont(new java.awt.Font("Comic Sans MS", 0, 12)); // NOI18N
        tastieraVirtuale.setText("Tastiera Virtuale");
        tastieraVirtuale.setOpaque(false);
        tastieraVirtuale.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tastieraVirtualeActionPerformed(evt);
            }
        });

        buttonGroup2.add(tastieraReale);
        tastieraReale.setFont(new java.awt.Font("Comic Sans MS", 0, 12)); // NOI18N
        tastieraReale.setText("Tastiera Reale");
        tastieraReale.setOpaque(false);
        tastieraReale.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tastieraRealeActionPerformed(evt);
            }
        });

        pulisciButton.setFont(new java.awt.Font("Comic Sans MS", 0, 12)); // NOI18N
        pulisciButton.setText("Pulisci");
        pulisciButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                pulisciButtonActionPerformed(evt);
            }
        });

        closeConnectionButton.setFont(new java.awt.Font("Comic Sans MS", 0, 12)); // NOI18N
        closeConnectionButton.setText("Disconnetti");
        closeConnectionButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                closeConnectionButtonActionPerformed(evt);
            }
        });

        jLabel3.setText("Velocità Rover");

        RoverVelocity.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        RoverVelocity.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        RoverVelocity.setText("0");
        RoverVelocity.setOpaque(true);

        minusButton.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
        minusButton.setText("-");
        minusButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                minusButtonActionPerformed(evt);
            }
        });

        plusButton.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
        plusButton.setText("+");
        plusButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                plusButtonActionPerformed(evt);
            }
        });

        labelDispositivi.setText("Dispositivi Connessi a Wall-j");

        labelFunctions.setText("Funzioni Disponibili");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addGap(19, 19, 19)
                                        .addComponent(tastieraVirtuale)
                                        .addGap(55, 55, 55)
                                        .addComponent(tastieraReale))
                                    .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addContainerGap()
                                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                            .addComponent(backButton)
                                            .addGroup(jPanel1Layout.createSequentialGroup()
                                                .addComponent(leftButton)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                                    .addComponent(forwardButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                                    .addComponent(stopButton, javax.swing.GroupLayout.PREFERRED_SIZE, 69, javax.swing.GroupLayout.PREFERRED_SIZE))))
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(rightButton)))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 131, Short.MAX_VALUE)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addComponent(RoverVelocity, javax.swing.GroupLayout.PREFERRED_SIZE, 83, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addComponent(plusButton, javax.swing.GroupLayout.PREFERRED_SIZE, 49, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(minusButton, javax.swing.GroupLayout.PREFERRED_SIZE, 47, javax.swing.GroupLayout.PREFERRED_SIZE))))
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGap(0, 0, Short.MAX_VALUE)
                                .addComponent(jLabel3)))
                        .addGap(109, 109, 109)
                        .addComponent(jSeparator2, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(27, 27, 27))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(ospitaButton)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 150, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(65, 65, 65)
                                .addComponent(sceltaStandAlone)))
                        .addGap(18, 18, 18)
                        .addComponent(SceltaClientServer)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(labelDispositivi, javax.swing.GroupLayout.PREFERRED_SIZE, 157, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(choiceDevices, javax.swing.GroupLayout.PREFERRED_SIZE, 141, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(233, 233, 233)
                        .addComponent(jLabel1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(14, 14, 14)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(choiceFunctions, javax.swing.GroupLayout.DEFAULT_SIZE, 135, Short.MAX_VALUE)
                            .addComponent(labelFunctions, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jSeparator3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(44, 44, 44)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(labelStatoConnessione)
                            .addComponent(closeConnectionButton))
                        .addGap(48, 48, 48)
                        .addComponent(labelStatoRV))
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 488, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(pulisciButton))
                .addContainerGap())
            .addComponent(jSeparator1)
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(36, 36, 36)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(labelStatoConnessione)
                            .addComponent(labelStatoRV))
                        .addGap(37, 37, 37)
                        .addComponent(closeConnectionButton))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jSeparator3, javax.swing.GroupLayout.PREFERRED_SIZE, 213, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(19, 19, 19)
                        .addComponent(jLabel2))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(29, 29, 29)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(choiceFunctions, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(jLabel1)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                    .addComponent(SceltaClientServer)
                                    .addComponent(sceltaStandAlone)
                                    .addComponent(labelDispositivi)
                                    .addComponent(labelFunctions))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addComponent(choiceDevices, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(ospitaButton))))))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 10, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(34, 34, 34)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(tastieraVirtuale)
                            .addComponent(tastieraReale))
                        .addGap(1, 1, 1)
                        .addComponent(jLabel3)
                        .addGap(18, 18, 18)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(forwardButton)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                    .addComponent(leftButton)
                                    .addComponent(stopButton)
                                    .addComponent(rightButton))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(backButton))
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(RoverVelocity, javax.swing.GroupLayout.PREFERRED_SIZE, 41, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                    .addComponent(plusButton)
                                    .addComponent(minusButton)))))
                    .addComponent(jSeparator2, javax.swing.GroupLayout.PREFERRED_SIZE, 337, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 295, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(pulisciButton)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void tastieraRealeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tastieraRealeActionPerformed
        tastieraVirtuale.setEnabled(false);
        plusButton.setEnabled(true);
         minusButton.setEnabled(true);
        ModificaVelocita.RealChoice=true;
        

    }//GEN-LAST:event_tastieraRealeActionPerformed

    private void tastieraVirtualeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tastieraVirtualeActionPerformed
        /*disabilito la tastiera Reale*/
        tastieraReale.setEnabled(false);
        /*Abilito tutti i pulsanti*/
        forwardButton.setEnabled(true);
        backButton.setEnabled(true);
        leftButton.setEnabled(true);
        rightButton.setEnabled(true);
        stopButton.setEnabled(true);
        plusButton.setEnabled(true);
         minusButton.setEnabled(true);
    }//GEN-LAST:event_tastieraVirtualeActionPerformed

    private void ospitaButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ospitaButtonActionPerformed
       /* Creo un nuovo Thread per la classe ThreadConnection*/
        ThreadConnection t=new ThreadConnection(); 
        /* faccio partire il thread*/
        t.start();
    }//GEN-LAST:event_ospitaButtonActionPerformed

    private void SceltaClientServerActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_SceltaClientServerActionPerformed
        /* abilito il pulsante Ospita*/
        ospitaButton.setEnabled(true);
    }//GEN-LAST:event_SceltaClientServerActionPerformed

    private void sceltaStandAloneActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_sceltaStandAloneActionPerformed
        /* disabilito il JRadioButton SceltaClient-Server*/
        SceltaClientServer.setEnabled(false);
        /* abilita la possibilità di scelta tra tastiera Reale e Virtuale*/
        tastieraReale.setEnabled(true);
        tastieraVirtuale.setEnabled(true);
        
    }//GEN-LAST:event_sceltaStandAloneActionPerformed

    private void pulisciButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_pulisciButtonActionPerformed
        /*pulisco l'area di OUTPUT*/
        AreaOUTPUT.setText("");
    }//GEN-LAST:event_pulisciButtonActionPerformed

    private void closeConnectionButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_closeConnectionButtonActionPerformed
        /*creo un nuovo thread*/
        ThreadConnection t=new ThreadConnection();
	/* chiudo la connessione*/	
        t.Stop();
    }//GEN-LAST:event_closeConnectionButtonActionPerformed

    private void plusButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_plusButtonActionPerformed
        ModificaVelocita v=new ModificaVelocita();   
         v.start(true);
    }//GEN-LAST:event_plusButtonActionPerformed

    private void minusButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_minusButtonActionPerformed
         ModificaVelocita v=new ModificaVelocita();
         v.start(false);
    }//GEN-LAST:event_minusButtonActionPerformed

    private void forwardButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_forwardButtonActionPerformed
       
        /* questo if serve a gestire il caso in cui l'utente 
           clicchi più volte sul comando, in questo caso 
           fermo il rover in attesa della nuova istruzione*/
                               if(DoRun.stopThread == false)
                               {                                 
                                   DoRun.stopThread =true;
                               }
                           /* creo un nuovo Thread*/
				DoRun r = new DoRun();
                          /* ottengo in input la velocità da impostare*/ 				                       
		          /* la converto in INT*/
		int velocity = Integer.parseInt(Rhover.RoverVelocity.getText()); 
				/* questa istruzione serve a reimpostare la 
                                * variabile stopThread che blocca il Thread 
                                * altrimenti non accetta più comandi*/
				DoRun.stopThread = false;
                               /*setto la velocità*/				
				r.setVelocity = velocity; 
				/* faccio partire il Thread*/
				r.start();
    }//GEN-LAST:event_forwardButtonActionPerformed

    private void stopButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_stopButtonActionPerformed
        DoRun r = new DoRun(); 
		boolean serial = false; 
		r.StopMe(serial);
    }//GEN-LAST:event_stopButtonActionPerformed

    private void rightButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_rightButtonActionPerformed
        /* questo if serve a gestire il caso in cui l'utente 
                                 clicchi più volte sul comando, in questo caso 
                                 fermo il rover in attesa della nuova istruzione*/
                               if(DoRun.stopThread == false)
                               {                                 
                                   DoRun.stopThread =true;
                               }
				DoRun r = new DoRun();                           
				int velocity = Integer.parseInt(Rhover.RoverVelocity.getText()); 
				DoRun.stopThread = false; 
				r.turn = true; 
				r.turnL = false; 
				r.setVelocity = velocity; 
				r.start();
    }//GEN-LAST:event_rightButtonActionPerformed

    private void backButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_backButtonActionPerformed
        /* questo if serve a gestire il caso in cui l'utente 
                                 clicchi più volte sul comando, in questo caso 
                                 fermo il rover in attesa della nuova istruzione*/
                               if(DoRun.stopThread == false)
                               {                                 
                                   DoRun.stopThread =true;
                               }
				DoRun r = new DoRun(); 
				int velocity = Integer.parseInt(Rhover.RoverVelocity.getText());
				DoRun.stopThread = false; 
				r.setVelocity = -velocity; 
				r.start();
    }//GEN-LAST:event_backButtonActionPerformed

    private void leftButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_leftButtonActionPerformed
       /* questo if serve a gestire il caso in cui l'utente 
                                 clicchi più volte sul comando, in questo caso 
                                 fermo il rover in attesa della nuova istruzione*/
                               if(DoRun.stopThread == false)
                               {                                 
                                   DoRun.stopThread =true;
                               }
				DoRun r = new DoRun();
				int velocity = Integer.parseInt(Rhover.RoverVelocity.getText()); 
				DoRun.stopThread = false; 
				r.turn = true; 
				r.turnL = true; 
				r.setVelocity = velocity; 
				r.start();
    }//GEN-LAST:event_leftButtonActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException | InstantiationException | IllegalAccessException | javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Rhover.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                new Rhover().setVisible(true);    
            }
        });      
}
        
    // Variables declaration - do not modify//GEN-BEGIN:variables
    public static javax.swing.JTextArea AreaOUTPUT;
    public static javax.swing.JLabel RoverVelocity;
    private javax.swing.JRadioButton SceltaClientServer;
    public static javax.swing.JButton backButton;
    private javax.swing.ButtonGroup buttonGroup1;
    private javax.swing.ButtonGroup buttonGroup2;
    public static java.awt.Choice choiceDevices;
    public static java.awt.Choice choiceFunctions;
    public static javax.swing.JButton closeConnectionButton;
    public static javax.swing.JButton forwardButton;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    public static javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JSeparator jSeparator1;
    private javax.swing.JSeparator jSeparator2;
    private javax.swing.JSeparator jSeparator3;
    private javax.swing.JSlider jSlider1;
    private javax.swing.JLabel labelDispositivi;
    private javax.swing.JLabel labelFunctions;
    private javax.swing.JLabel labelStatoConnessione;
    public static javax.swing.JLabel labelStatoRV;
    public static javax.swing.JButton leftButton;
    public static javax.swing.JButton minusButton;
    private javax.swing.JButton ospitaButton;
    public static javax.swing.JButton plusButton;
    private javax.swing.JButton pulisciButton;
    public static javax.swing.JButton rightButton;
    private javax.swing.JRadioButton sceltaStandAlone;
    public static javax.swing.JButton stopButton;
    public static javax.swing.JRadioButton tastieraReale;
    private javax.swing.JRadioButton tastieraVirtuale;
    // End of variables declaration//GEN-END:variables
}