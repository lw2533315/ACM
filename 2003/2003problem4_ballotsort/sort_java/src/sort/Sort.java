/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sort;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Administrator
 */
public class Sort {

    public static boolean smallOne(String str, char a1, char a2) {
        int index1 = str.indexOf(a1);
        int index2 = str.indexOf(a2);
        return index1 > index2;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

//        String modle = " XWYPZRNQMKTJOIGHDBCLAEVUFS";
//        System.out.println(modle);
//        List list = new ArrayList<String>();
//        list.add("ADAMS JOHN QUINCY");
//        list.add("ADAMS JOHN");
//        list.add("FRANKLIN BENJAMIN");
//        list.add("HANCOCK JOHN");
//        list.add("JEFFERSON THOMAS");
//        list.add("LEE RICHARD HENRY");
//        list.add("LEE ROBERT E");
//        list.add("LINCOLN ABRAHAM");
//        String temp = (String) list.get(0);//取出第一行
//        int bigLen = temp.length();
//        for (int i = 0; i < list.size(); i++) {
//            temp = (String) list.get(i);
//            int tempLen = temp.length();
//            if (tempLen > bigLen) {
//                bigLen = tempLen;
//            }            
//        }
//        
        List list = new ArrayList<String>();
        String modle = null;
        String data = null;
        int bigLen = 0;
        //读取文件
        try { //输入的bufferedReader readLine 要在try下   
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            data = br.readLine();
            modle = data;

            while (data != null) {
                data = br.readLine();
                if (data != null) {
                    list.add(data);
                    if (bigLen < data.length()) {
                        bigLen = data.length();
                    }
                }
            }
            br.close();
        } catch (Exception e) {
            System.out.println(e);
        }

        for (int i = 0; i < list.size(); i++) {//将所有list成员补成一样长度
            String temp2 = "";
            while (list.get(i).toString().length() < bigLen) {
                temp2 = (String) list.get(i);
                temp2 += " ";
                list.set(i, temp2);
            }
        }

        for (Object x : list) {
            System.out.println((String) x);
        }
        for (int k = 0; k < list.size(); k++) {
            String smaller = (String) list.get(k);
            for (int j = k + 1; j < list.size(); j++) {
                for (int i = 0; i < bigLen; i++) {
                    if (smaller.charAt(i) != list.get(j).toString().charAt(i)) {
                        if (smallOne(modle, smaller.charAt(i), list.get(j).toString().charAt(i))) {
                            smaller = (String) list.get(j);
                            list.set(j, list.get(k));
                            list.set(k, smaller);
                        }
                        break;
                    }
                }
            }
        }
        System.out.println();
        for (Object x : list) {
            System.out.println(x);
        }
    }
}
