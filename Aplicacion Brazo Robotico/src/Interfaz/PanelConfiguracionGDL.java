package Interfaz;

import static Interfaz.BrazoRobotico.arduino;
import static Interfaz.BrazoRobotico.model;
import com.panamahitek.ArduinoException;
import java.util.logging.Level;
import java.util.logging.Logger;
import jssc.SerialPortException;
import static Interfaz.BrazoRobotico.btnFinalizar;

/**
 *
 * @author Jorge Enrique Aguado Guaní
 * @author Natalia Méndez Martínez
 */
public class PanelConfiguracionGDL extends javax.swing.JPanel {
    
    public PanelConfiguracionGDL() {
        initComponents();
        ocultarAjustes();   
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        btnCintura = new javax.swing.JButton();
        btnHombro = new javax.swing.JButton();
        btnCodo = new javax.swing.JButton();
        btnMuneca = new javax.swing.JButton();
        btnPinza = new javax.swing.JButton();
        sliderCintura = new javax.swing.JSlider(10,4076, 2038);
        btnGuardarPasoCintura = new javax.swing.JButton();
        sliderHombro = new javax.swing.JSlider(8,120,10);
        sliderCodo = new javax.swing.JSlider(8,120,60);
        sliderMuneca = new javax.swing.JSlider(8,130,10);
        sliderPinza = new javax.swing.JSlider(18,80,18);
        btnGuardarPasoHombro = new javax.swing.JButton();
        btnGuardarPasoCodo = new javax.swing.JButton();
        btnGuardarPasoMuneca = new javax.swing.JButton();
        btnGuardarPasoPinza = new javax.swing.JButton();

        setBackground(new java.awt.Color(193, 201, 254));

        jLabel1.setFont(new java.awt.Font("Ubuntu", 1, 15)); // NOI18N
        jLabel1.setText("Programar");

        btnCintura.setText("Cintura");
        btnCintura.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCinturaActionPerformed(evt);
            }
        });

        btnHombro.setText("Hombro");
        btnHombro.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnHombroActionPerformed(evt);
            }
        });

        btnCodo.setText("Codo");
        btnCodo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCodoActionPerformed(evt);
            }
        });

        btnMuneca.setText("Muñeca");
        btnMuneca.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnMunecaActionPerformed(evt);
            }
        });

        btnPinza.setText("Pinza");
        btnPinza.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnPinzaActionPerformed(evt);
            }
        });

        sliderCintura.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                sliderCinturaStateChanged(evt);
            }
        });
        sliderCintura.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                sliderCinturaMouseReleased(evt);
            }
        });

        btnGuardarPasoCintura.setText("Guardar paso");
        btnGuardarPasoCintura.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnGuardarPasoCinturaActionPerformed(evt);
            }
        });

        sliderHombro.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                sliderHombroMouseReleased(evt);
            }
        });

        sliderCodo.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                sliderCodoMouseReleased(evt);
            }
        });

        sliderMuneca.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                sliderMunecaStateChanged(evt);
            }
        });
        sliderMuneca.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                sliderMunecaMouseReleased(evt);
            }
        });

        sliderPinza.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                sliderPinzaMouseReleased(evt);
            }
        });

        btnGuardarPasoHombro.setText("Guardar paso");
        btnGuardarPasoHombro.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnGuardarPasoHombroActionPerformed(evt);
            }
        });

        btnGuardarPasoCodo.setText("Guardar paso");
        btnGuardarPasoCodo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnGuardarPasoCodoActionPerformed(evt);
            }
        });

        btnGuardarPasoMuneca.setText("Guardar paso");
        btnGuardarPasoMuneca.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnGuardarPasoMunecaActionPerformed(evt);
            }
        });

        btnGuardarPasoPinza.setText("Guardar paso");
        btnGuardarPasoPinza.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnGuardarPasoPinzaActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(btnPinza, javax.swing.GroupLayout.PREFERRED_SIZE, 91, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnMuneca, javax.swing.GroupLayout.PREFERRED_SIZE, 91, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnCodo, javax.swing.GroupLayout.PREFERRED_SIZE, 91, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnHombro, javax.swing.GroupLayout.PREFERRED_SIZE, 91, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnCintura, javax.swing.GroupLayout.PREFERRED_SIZE, 91, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 85, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(sliderMuneca, javax.swing.GroupLayout.PREFERRED_SIZE, 164, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(btnGuardarPasoMuneca))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(sliderPinza, javax.swing.GroupLayout.PREFERRED_SIZE, 164, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(btnGuardarPasoPinza))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(sliderCintura, javax.swing.GroupLayout.PREFERRED_SIZE, 164, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(btnGuardarPasoCintura))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(sliderHombro, javax.swing.GroupLayout.PREFERRED_SIZE, 164, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(btnGuardarPasoHombro))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(sliderCodo, javax.swing.GroupLayout.PREFERRED_SIZE, 164, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(btnGuardarPasoCodo)))
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 30, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnCintura, javax.swing.GroupLayout.PREFERRED_SIZE, 38, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(32, 32, 32)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(btnGuardarPasoCintura)
                            .addComponent(sliderCintura, javax.swing.GroupLayout.PREFERRED_SIZE, 30, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(btnHombro, javax.swing.GroupLayout.PREFERRED_SIZE, 38, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                        .addComponent(btnGuardarPasoHombro)
                        .addComponent(sliderHombro, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(btnCodo, javax.swing.GroupLayout.PREFERRED_SIZE, 38, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(sliderCodo, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnGuardarPasoCodo))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(btnMuneca, javax.swing.GroupLayout.PREFERRED_SIZE, 38, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(sliderMuneca, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnGuardarPasoMuneca))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(btnPinza, javax.swing.GroupLayout.PREFERRED_SIZE, 38, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                        .addComponent(btnGuardarPasoPinza)
                        .addComponent(sliderPinza, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addGap(0, 15, Short.MAX_VALUE))
        );
    }// </editor-fold>//GEN-END:initComponents

    private void sliderCinturaStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_sliderCinturaStateChanged
               
    }//GEN-LAST:event_sliderCinturaStateChanged

    private void btnGuardarPasoCinturaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnGuardarPasoCinturaActionPerformed
        String [] agregarPaso = new String[2];
        agregarPaso[0] = "Cintura";
        agregarPaso[1] = sliderCintura.getValue()+"";
        
        model.addRow(agregarPaso);
        btnFinalizar.setVisible(true);
    }//GEN-LAST:event_btnGuardarPasoCinturaActionPerformed

    private void sliderCinturaMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_sliderCinturaMouseReleased
        String valor = sliderCintura.getValue()+"";
        System.out.println(valor);
        try {
            arduino.sendData(valor);
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_sliderCinturaMouseReleased

    private void sliderHombroMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_sliderHombroMouseReleased
        String valor = sliderHombro.getValue()+"";
        System.out.println(valor);
        try {
            arduino.sendData(valor);
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_sliderHombroMouseReleased

    private void sliderCodoMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_sliderCodoMouseReleased
        String valor = sliderCodo.getValue()+"";
        System.out.println(valor);
        try {
            arduino.sendData(valor);
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_sliderCodoMouseReleased

    private void sliderMunecaMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_sliderMunecaMouseReleased
        String valor = sliderMuneca.getValue()+"";
        System.out.println(valor);
        try {
            arduino.sendData(valor);
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_sliderMunecaMouseReleased

    private void sliderPinzaMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_sliderPinzaMouseReleased
        String valor = sliderPinza.getValue()+"";
        System.out.println(valor);
        try {
            arduino.sendData(valor);
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_sliderPinzaMouseReleased

    private void btnCinturaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCinturaActionPerformed
        try {
            arduino.sendData("3");
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        }
        
        sliderCintura.setVisible(true);
        sliderHombro.setVisible(false);
        sliderCodo.setVisible(false);
        sliderMuneca.setVisible(false);
        sliderPinza.setVisible(false);
        
        btnGuardarPasoCintura.setVisible(true);
        btnGuardarPasoHombro.setVisible(false);
        btnGuardarPasoCodo.setVisible(false);
        btnGuardarPasoMuneca.setVisible(false);
        btnGuardarPasoPinza.setVisible(false);
    }//GEN-LAST:event_btnCinturaActionPerformed

    private void btnHombroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnHombroActionPerformed
        try {
            arduino.sendData("4");
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        }
        
        sliderCintura.setVisible(false);
        sliderHombro.setVisible(true);
        sliderCodo.setVisible(false);
        sliderMuneca.setVisible(false);
        sliderPinza.setVisible(false);
        
        btnGuardarPasoCintura.setVisible(false);
        btnGuardarPasoHombro.setVisible(true);
        btnGuardarPasoCodo.setVisible(false);
        btnGuardarPasoMuneca.setVisible(false);
        btnGuardarPasoPinza.setVisible(false);
    }//GEN-LAST:event_btnHombroActionPerformed

    private void btnCodoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCodoActionPerformed
        try {
            arduino.sendData("5");
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        }
        
        sliderCintura.setVisible(false);
        sliderHombro.setVisible(false);
        sliderCodo.setVisible(true);
        sliderMuneca.setVisible(false);
        sliderPinza.setVisible(false);
        
        btnGuardarPasoCintura.setVisible(false);
        btnGuardarPasoHombro.setVisible(false);
        btnGuardarPasoCodo.setVisible(true);
        btnGuardarPasoMuneca.setVisible(false);
        btnGuardarPasoPinza.setVisible(false);
    }//GEN-LAST:event_btnCodoActionPerformed

    private void btnMunecaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnMunecaActionPerformed
        try {
            arduino.sendData("6");
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        }
        
        sliderCintura.setVisible(false);
        sliderHombro.setVisible(false);
        sliderCodo.setVisible(false);
        sliderMuneca.setVisible(true);
        sliderPinza.setVisible(false);
        
        btnGuardarPasoCintura.setVisible(false);
        btnGuardarPasoHombro.setVisible(false);
        btnGuardarPasoCodo.setVisible(false);
        btnGuardarPasoMuneca.setVisible(true);
        btnGuardarPasoPinza.setVisible(false);
    }//GEN-LAST:event_btnMunecaActionPerformed

    private void btnPinzaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnPinzaActionPerformed
        try {
            arduino.sendData("7");
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        }
        
        sliderCintura.setVisible(false);
        sliderHombro.setVisible(false);
        sliderCodo.setVisible(false);
        sliderMuneca.setVisible(false);
        sliderPinza.setVisible(true);
        
        btnGuardarPasoCintura.setVisible(false);
        btnGuardarPasoHombro.setVisible(false);
        btnGuardarPasoCodo.setVisible(false);
        btnGuardarPasoMuneca.setVisible(false);
        btnGuardarPasoPinza.setVisible(true);
    }//GEN-LAST:event_btnPinzaActionPerformed

    private void btnGuardarPasoHombroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnGuardarPasoHombroActionPerformed
        String [] agregarPaso = new String[2];
        agregarPaso[0] = "Hombro";
        agregarPaso[1] = sliderHombro.getValue()+"";
        
        model.addRow(agregarPaso);
        btnFinalizar.setVisible(true);
    }//GEN-LAST:event_btnGuardarPasoHombroActionPerformed

    private void btnGuardarPasoCodoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnGuardarPasoCodoActionPerformed
        String [] agregarPaso = new String[2];
        agregarPaso[0] = "Codo";
        agregarPaso[1] = sliderCodo.getValue()+"";
        
        model.addRow(agregarPaso);
        btnFinalizar.setVisible(true);
    }//GEN-LAST:event_btnGuardarPasoCodoActionPerformed

    private void btnGuardarPasoMunecaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnGuardarPasoMunecaActionPerformed
        String [] agregarPaso = new String[2];
        agregarPaso[0] = "Muñeca";
        agregarPaso[1] = sliderMuneca.getValue()+"";
        
        model.addRow(agregarPaso);
        btnFinalizar.setVisible(true);
    }//GEN-LAST:event_btnGuardarPasoMunecaActionPerformed

    private void btnGuardarPasoPinzaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnGuardarPasoPinzaActionPerformed
        String [] agregarPaso = new String[2];
        agregarPaso[0] = "Pinza";
        agregarPaso[1] = sliderPinza.getValue()+"";
        
        model.addRow(agregarPaso);
        btnFinalizar.setVisible(true);
    }//GEN-LAST:event_btnGuardarPasoPinzaActionPerformed

    private void sliderMunecaStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_sliderMunecaStateChanged
        // TODO add your handling code here:
    }//GEN-LAST:event_sliderMunecaStateChanged


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnCintura;
    private javax.swing.JButton btnCodo;
    private javax.swing.JButton btnGuardarPasoCintura;
    private javax.swing.JButton btnGuardarPasoCodo;
    private javax.swing.JButton btnGuardarPasoHombro;
    private javax.swing.JButton btnGuardarPasoMuneca;
    private javax.swing.JButton btnGuardarPasoPinza;
    private javax.swing.JButton btnHombro;
    private javax.swing.JButton btnMuneca;
    private javax.swing.JButton btnPinza;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JSlider sliderCintura;
    private javax.swing.JSlider sliderCodo;
    private javax.swing.JSlider sliderHombro;
    private javax.swing.JSlider sliderMuneca;
    private javax.swing.JSlider sliderPinza;
    // End of variables declaration//GEN-END:variables

    private void ocultarAjustes() {
        sliderCintura.setVisible(false);
        sliderHombro.setVisible(false);
        sliderCodo.setVisible(false);
        sliderMuneca.setVisible(false);
        sliderPinza.setVisible(false);
        
        btnGuardarPasoCintura.setVisible(false);
        btnGuardarPasoHombro.setVisible(false);
        btnGuardarPasoCodo.setVisible(false);
        btnGuardarPasoMuneca.setVisible(false);
        btnGuardarPasoPinza.setVisible(false);
    }
}
