package Interfaz;

import static Interfaz.PanelInicial.btnEjecutar;
import com.panamahitek.ArduinoException;
import com.panamahitek.PanamaHitek_Arduino;
import java.awt.BorderLayout;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.table.DefaultTableModel;
import jssc.SerialPortException;

/**
 *
 * @author Jorge Enrique Aguado Guaní
 * @author Natalia Méndez Martínez
 */
public class BrazoRobotico extends javax.swing.JFrame {
    static PanamaHitek_Arduino arduino = new PanamaHitek_Arduino();
    
    static DefaultTableModel model = new DefaultTableModel();
    
    String gradosMotores = "";
    String valoresMotores = "";
    
    public BrazoRobotico() {
        initComponents();
        createPanels();
        model.addColumn("Articulación");
        model.addColumn("Grado");
        tablaPasos.setModel(model);
        tablaPasos.setEnabled(false);
        btnEscribirValores.setVisible(false);
        btnFinalizar.setVisible(false);
        
        try {
            arduino.arduinoTX("/dev/ttyUSB0", 9600);
        } catch (ArduinoException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                            .log(Level.SEVERE, null, ex);
        }
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        panelPrincipal = new javax.swing.JPanel();
        contenedorTablaPasos = new javax.swing.JScrollPane();
        tablaPasos = new javax.swing.JTable();
        btnEscribirValores = new javax.swing.JButton();
        btnFinalizar = new javax.swing.JButton();
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jMenu2 = new javax.swing.JMenu();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        panelPrincipal.setBackground(new java.awt.Color(239, 239, 239));

        javax.swing.GroupLayout panelPrincipalLayout = new javax.swing.GroupLayout(panelPrincipal);
        panelPrincipal.setLayout(panelPrincipalLayout);
        panelPrincipalLayout.setHorizontalGroup(
            panelPrincipalLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        panelPrincipalLayout.setVerticalGroup(
            panelPrincipalLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 265, Short.MAX_VALUE)
        );

        tablaPasos.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {

            }
        ));
        contenedorTablaPasos.setViewportView(tablaPasos);

        btnEscribirValores.setText("Escribir valores");
        btnEscribirValores.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnEscribirValoresActionPerformed(evt);
            }
        });

        btnFinalizar.setText("Finalizar");
        btnFinalizar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnFinalizarActionPerformed(evt);
            }
        });

        jMenu1.setText("File");
        jMenuBar1.add(jMenu1);

        jMenu2.setText("Edit");
        jMenuBar1.add(jMenu2);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(panelPrincipal, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(contenedorTablaPasos, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(117, 117, 117)
                        .addComponent(btnEscribirValores, javax.swing.GroupLayout.PREFERRED_SIZE, 153, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 26, Short.MAX_VALUE)
                        .addComponent(btnFinalizar, javax.swing.GroupLayout.PREFERRED_SIZE, 95, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(panelPrincipal, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(contenedorTablaPasos, javax.swing.GroupLayout.PREFERRED_SIZE, 145, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(btnEscribirValores, javax.swing.GroupLayout.DEFAULT_SIZE, 43, Short.MAX_VALUE)
                    .addComponent(btnFinalizar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnEscribirValoresActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnEscribirValoresActionPerformed
        try {
            arduino.sendData(valoresMotores);
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        }
                
        btnEscribirValores.setVisible(false);
        btnEjecutar.setEnabled(true);
        btnEjecutar.requestFocus(true);
        
    }//GEN-LAST:event_btnEscribirValoresActionPerformed

    private void btnFinalizarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnFinalizarActionPerformed
        try {
            arduino.sendData("2");
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(PanelConfiguracionGDL.class.getName())
                    .log(Level.SEVERE, null, ex);
        }
        
        PanelInicial inicio = new PanelInicial();
        inicio.setSize(400, 300);
        inicio.setLocation(2, 2);
        
        panelPrincipal.removeAll();
        panelPrincipal.add(inicio, BorderLayout.CENTER);
        panelPrincipal.revalidate();
        panelPrincipal.repaint();
        btnEscribirValores.setVisible(false);
        
        valoresMotores = "";
        
        for (int i = 0; i < tablaPasos.getModel().getRowCount(); i++) {
            // Cambiar nombre del servo por ID
            int idServo = 0;
            switch(tablaPasos.getModel().getValueAt(i, 0).toString()) {
                case "Cintura":
                    idServo = 6;
                    break;
                case "Hombro":
                    idServo = 2;
                    break;
                case "Codo":
                    idServo = 3;
                    break;
                case "Muñeca":
                    idServo = 4;
                    break;
                case "Pinza":
                    idServo = 5;
                    break;
            }
            
            if(i == tablaPasos.getModel().getRowCount() - 1) {
                valoresMotores += idServo + ",";
                valoresMotores += tablaPasos.getModel().getValueAt(i, 1);            
            } else {
                valoresMotores += idServo + ",";
                valoresMotores += tablaPasos.getModel().getValueAt(i, 1) + ";";                
            }           
        }
        System.out.println(valoresMotores);
        btnFinalizar.setVisible(false);
        btnEscribirValores.setVisible(true);
    }//GEN-LAST:event_btnFinalizarActionPerformed

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
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(BrazoRobotico.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(BrazoRobotico.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(BrazoRobotico.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(BrazoRobotico.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new BrazoRobotico().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    public static javax.swing.JButton btnEscribirValores;
    public static javax.swing.JButton btnFinalizar;
    private javax.swing.JScrollPane contenedorTablaPasos;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenuBar jMenuBar1;
    public static javax.swing.JPanel panelPrincipal;
    public static javax.swing.JTable tablaPasos;
    // End of variables declaration//GEN-END:variables

    private void createPanels() {
        PanelInicial p1 = new PanelInicial();
        p1.setSize(400, 300);
        p1.setLocation(2, 2);
        
        panelPrincipal.removeAll();
        panelPrincipal.add(p1, BorderLayout.CENTER);
        panelPrincipal.revalidate();
        panelPrincipal.repaint();
    }
}
