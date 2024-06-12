package org.code;

import java.io.*;
import java.text.SimpleDateFormat;
import java.time.LocalTime;
import java.util.*;

public class Parser {
//    public static void parse(File file, File result) {
//        try (FileReader fileReader = new FileReader(file);
//             BufferedReader reader = new BufferedReader(fileReader);
//             FileWriter fileWriter = new FileWriter(result);
//             BufferedWriter writer = new BufferedWriter(fileWriter))
//        {
//            writer.append("day").append(",").append("hour").append(",").append("operation").append("\n");
//            writer.flush();
//
//            int date = 1;
//            String time;
//            String timeZone = "";
//            LocalTime oldTime = LocalTime.parse("00:00");
//            while (reader.ready()) {
//                String line = reader.readLine();
//
//                if (line.contains("APP")) {
//                    timeZone = line.substring(line.indexOf(":") + 4, line.indexOf(":") + 6);
//                }
//
//                if (line.contains(":")) {
//                    LocalTime localTime = null;
//                    time = line.replaceAll("^(\\D+)| *PM| +AM", "");
//
//                    if (time.length() == 4) {
//                        time = "0" + time;
//                    }
//
//                    if (timeZone.equals("PM")) {
//                        localTime = LocalTime.parse(time).plusHours(12);
//                    } else if (timeZone.equals("AM")) {
//                        localTime = LocalTime.parse(time);
//                    }
//
//                    if (oldTime.isAfter(localTime)) {
//                        date++;
//                    }
//
//                    oldTime = localTime;
//                    writer.append(String.valueOf(date)).append(",").append(localTime.toString()).append(",");
//                }
//
//                List<String> list = Arrays.asList("команда создана в графане", "подписка для команды создана", "зарегистрировался",
//                        "команда создана", "запустил test", "перешел в status TEST_STOPPING", "перешел в status CANCELED",
//                        "стартовал grafana", "перешел в status FINISHED", "обновил подписку", "перешел в status FAILED",
//                        "ошибка регистрации");
//
//                for (String s : list) {
//                    if (line.contains(s)) {
//                        writer.append(s).append("\n");
//                        break;
//                    }
//                }
//                writer.flush();
//                fileWriter.flush();
//            }
//        } catch (Exception e) {
//            System.out.println(e.getMessage());
//        }
//    }

    public static void parse(File file, File result) {
        try (FileReader fileReader = new FileReader(file);
             BufferedReader reader = new BufferedReader(fileReader);
             FileWriter fileWriter = new FileWriter(result);
             BufferedWriter writer = new BufferedWriter(fileWriter))
        {

            List<String> list = Arrays.asList("команда создана в графане", "подписка для команды создана", "зарегистрировался",
                    "команда создана", "запустил test", "перешел в status TEST_STOPPING", "перешел в status CANCELED",
                    "стартовал grafana", "перешел в status FINISHED", "обновил подписку", "перешел в status FAILED",
                    "ошибка регистрации");

            writer.append("day").append(",").append("hour").append(",").append("operation").append("\n");
            writer.flush();

            int date = 1;
            String time;
            String timeZone = "";
            SimpleDateFormat formatDate = new SimpleDateFormat("hh:mm a");
            Date oldTime = formatDate.parse("00:00 PM");
            while (reader.ready()) {
                String line = reader.readLine();

                if (line.contains("APP")) {
                    timeZone = line.substring(line.indexOf(":") + 4, line.indexOf(":") + 6);
                }

                if (line.contains(":")) {
                    time = line.replaceAll("^(\\D+)| *PM| +AM", "");
                    time = time.concat(" " + timeZone);
                    if (oldTime.after(formatDate.parse(time))) {
                        date++;
                    }

                    String resultTime = String.valueOf(formatDate.parse(time));
                    resultTime = resultTime.substring(resultTime.indexOf("01") + 2, resultTime.indexOf("MSK") - 4);
                    oldTime = formatDate.parse(time);
                    writer.append(String.valueOf(date))
                            .append(",")
                            .append(resultTime.trim())
                            .append(",");
                }
                
                for (String s : list) {
                    if (line.contains(s)) {
                        writer.append(s).append("\n");
                        break;
                    }
                }
                writer.flush();
                fileWriter.flush();
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
