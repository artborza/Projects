package com.example.java.utilities;

public class MathHelper {

    private int total;

    public MathHelper(int total) {
        this.total += total;
    }

    public int getTotal() {
        return total;
    }

    public int doMath(String prompt) throws NumberFormatException {
        String input = InputHelper.getInput(prompt);
        int value = Integer.parseInt(input);
        total += value;
        return value;
    }
}
