package org.emualtor.mock;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class MockApplication {

    public static String SPRING_KAFKA_HOST;

    public static void main(String[] args) {
        if (args.length > 0) {
            SPRING_KAFKA_HOST = args[0];
            SpringApplication.run(MockApplication.class, args);
        }
        else {
            System.out.println("Invalid args");
        }

    }

}
