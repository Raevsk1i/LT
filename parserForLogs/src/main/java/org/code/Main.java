package org.code;

import java.io.File;

public class Main {
    public static void main(String[] args) {
        File file = new File("./src/main/resources/3monthslog.txt");
        File result = new File("./src/main/resources/result.txt");
        Parser.parse(file, result);
    }
}