package com.example.java;

import com.example.java.model.ClothingItem;
import com.example.java.model.Shirt;

/**
 * My main class that starts the application
 */
public class Main {

    /**
     * The main method
     */
    public static void main(String[] args) {
        // write your code here
        ClothingItem item = new ClothingItem("Shirt", "L", 19.99);
        System.out.println(item);

        Shirt shirt = new Shirt("M", 14.99);
        System.out.println(shirt);
    }
}
