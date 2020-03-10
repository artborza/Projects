package com.example.java;

import java.io.*;

public class Main {

    public static void main(String[] args) {
        // write your code here
        String sourceFile = "files/loremipsum.txt";
        String targetFile = "files/target.txt";

        try (FileReader fileReader = new FileReader(sourceFile);
             BufferedReader bufferedReader = new BufferedReader(fileReader);
             FileWriter writer = new FileWriter(targetFile);
        ) {
            while (true) {
                String line = bufferedReader.readLine();
                if (line == null) {
                    break;
                }
                writer.write(line + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
