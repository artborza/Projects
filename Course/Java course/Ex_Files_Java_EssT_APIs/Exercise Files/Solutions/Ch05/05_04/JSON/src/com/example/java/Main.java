package com.example.java;

import com.example.java.model.Flower;
import com.google.gson.Gson;
import com.google.gson.stream.JsonReader;

import java.io.FileReader;
import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException {
        // write your code here
        String fileName = "files/data.json";

        Gson gson = new Gson();
        try (FileReader fileReader = new FileReader(fileName);
             JsonReader reader = new JsonReader(fileReader)
        ) {
            Flower[] data = gson.fromJson(reader, Flower[].class);
            for (Flower flower :
                    data) {
                System.out.println(flower);
            }
        }

    }
}
