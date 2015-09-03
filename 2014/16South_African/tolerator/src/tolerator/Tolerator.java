/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tolerator;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Administrator
 */
public class Tolerator {

    public static int diff(int a[], int size) {
        int big = a[0];
        int small = a[0];
        for (int i = 1; i < 3; i++) {
            if (big < a[i]) {
                big = a[i];
            }
            if (small > a[i]) {
                small = a[i];
            }
        }
        return big - small;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String temp = null;
        try {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            int[] a = new int[4];
            int index = 0;

            temp = br.readLine();
            while (temp.equals("-1") == false) {
                int loop = 0;
                while (loop < 4) {
                    index = temp.indexOf(" ");
                    if (index != -1) {
                        a[loop] = Integer.parseInt(temp.substring(0, index));
                        temp = temp.substring(index + 1);//                    
                        loop++;
                    } else {
                        a[loop] = Integer.parseInt(temp.substring(0));
                        loop++;
                    }
                }
                if (diff(a, 4) > a[3]) {
                    System.out.println("0");
                } else {
                    System.out.println("1");
                }
                temp = br.readLine();
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Tolerator.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Tolerator.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}
