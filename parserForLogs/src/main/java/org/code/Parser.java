package org.code;

import netscape.javascript.JSObject;

import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Parser {

    public static void parse(File file, File result) {
        try (FileReader fileReader = new FileReader(file);
            BufferedReader reader = new BufferedReader(fileReader);
            FileWriter fileWriter = new FileWriter(result);
            BufferedWriter writer = new BufferedWriter(fileWriter))
        {
            Map<String, Integer> map = new HashMap<>();
            while (reader.ready()) {
                String line = reader.readLine();
                if (line.contains("стартовал grafana")) {
                    map.put("стартовал grafana", map.getOrDefault("стартовал grafana", 0) + 1);
                } else if (line.contains("перешел в status")) {
                    map.put("тест перешел в status", map.getOrDefault("тест перешел в status", 0) + 1);
                } else if (line.contains("команда создана")) {
                    map.put("команда создана", map.getOrDefault("команда создана", 0) + 1);
                } else if (line.contains("запустил test")) {
                    map.put("запустил test", map.getOrDefault("запустил test", 0) + 1);
                } else if (line.contains("зарегистрировался")) {
                    map.put("зарегистрировался", map.getOrDefault("зарегистрировался", 0) + 1);
                } else if (line.contains("подписка для")) {
                    map.put("подписка для команды создана", map.getOrDefault("подписка для команды создана", 0) + 1);
                }
            }
            for (Map.Entry<String, Integer> entry : map.entrySet()) {
                String key = entry.getKey();
                Integer value = entry.getValue();
                writer.append(key).append(": ").append(String.valueOf(value)).append("\r\n");
            }
            writer.flush();
            fileWriter.flush();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    public static void parseRegex(File file, File result) {
        try (FileReader fileReader = new FileReader(file);
             BufferedReader reader = new BufferedReader(fileReader);
             FileWriter fileWriter = new FileWriter(result);
             BufferedWriter writer = new BufferedWriter(fileWriter))
        {
            Map<String, Integer> map = new HashMap<>();
            String regex = "[А-я][^на базе]";
            while (reader.ready()) {
                String line = reader.readLine();
                writer.write(line.replaceAll(regex, "") + "\r\n");
                writer.flush();
                fileWriter.flush();
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
