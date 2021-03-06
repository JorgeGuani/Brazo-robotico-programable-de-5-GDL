package Interfaz;

import static Interfaz.BrazoRobotico.arduino;
import static Interfaz.BrazoRobotico.btnEscribirValores;
import static Interfaz.BrazoRobotico.panelPrincipal;
import com.panamahitek.ArduinoException;
import java.awt.BorderLayout;
import java.util.logging.Level;
import java.util.logging.Logger;
import jssc.SerialPortException;

/**
 *
 * @author Jorge Enrique Aguado Guaní
 * @author Natalia Méndez Martínez
 */
public class PanelInicial extends javax.swing.JPanel {

    /**
     * Creates new form PanelInicial
     */
    public PanelInicial() {
        initComponents();
        btnEjecutar.setEnabled(false);
        btnAbortar.setVisible(false);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        btnProgramar = new javax.swing.JButton();
        btnEjecutar = new javax.swing.JButton();
        lblBrazoRobot = new javax.swing.JLabel();
        btnAbortar = new javax.swing.JButton();

        setBackground(new java.awt.Color(213, 213, 213));

        btnProgramar.setText("Programar");
        btnProgramar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnProgramarActionPerformed(evt);
            }
        });

        btnEjecutar.setText("Ejecutar");
        btnEjecutar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnEjecutarActionPerformed(evt);
            }
        });

        lblBrazoRobot.setFont(new java.awt.Font("Ubuntu", 1, 18)); // NOI18N
        lblBrazoRobot.setText("Brazo Robot");
        lblBrazoRobot.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);

        btnAbortar.setBackground(new java.awt.Color(255, 0, 25));
        btnAbortar.setForeground(new java.awt.Color(254, 254, 254));
        btnAbortar.setText("Abortar");
        btnAbortar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAbortarActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(lblBrazoRobot, javax.swing.GroupLayout.PREFERRED_SIZE, 112, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(1, 1, 1)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(btnEjecutar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btnProgramar, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addGap(142, 142, 142))
            .addGroup(layout.createSequentialGroup()
                .addGap(77, 77, 77)
                .addComponent(btnAbortar, javax.swing.GroupLayout.PREFERRED_SIZE, 241, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(82, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(24, 24, 24)
                .addComponent(lblBrazoRobot, javax.swing.GroupLayout.PREFERRED_SIZE, 38, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(btnProgramar, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(btnEjecutar, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnAbortar, javax.swing.GroupLayout.PREFERRED_SIZE, 42, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(25, Short.MAX_VALUE))
        );
    }// </editor-fold>//GEN-END:initComponents

    private void btnProgramarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnProgramarActionPerformed
        System.out.println("Programar");
        PanelConfiguracionGDL configuracion = new PanelConfiguracionGDL();
        configuracion.setSize(400, 300);
        configuracion.setLocation(2, 2);
        
        panelPrincipal.removeAll();
        panelPrincipal.add(configuracion, BorderLayout.CENTER);
        panelPrincipal.revalidate();
        panelPrincipal.repaint();
        
        btnEscribirValores.setVisible(false);
        
        try {
            arduino.sendData("1");
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        } 
    }//GEN-LAST:event_btnProgramarActionPerformed

    private void btnEjecutarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnEjecutarActionPerformed
        try {
            arduino.sendData("8");
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        }
        
        btnProgramar.setEnabled(false);
        btnEjecutar.setEnabled(false);
        btnAbortar.setVisible(true);
        btnAbortar.requestFocus(true);
    }//GEN-LAST:event_btnEjecutarActionPerformed

    private void btnAbortarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAbortarActionPerformed
        try {
            arduino.sendData("9");
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        }
        
        btnProgramar.setEnabled(true);
        btnEjecutar.setEnabled(true);
        btnAbortar.setVisible(false);        
    }//GEN-LAST:event_btnAbortarActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnAbortar;
    public static javax.swing.JButton btnEjecutar;
    private javax.swing.JButton btnProgramar;
    private javax.swing.JLabel lblBrazoRobot;
    // End of variables declaration//GEN-END:variables
}
