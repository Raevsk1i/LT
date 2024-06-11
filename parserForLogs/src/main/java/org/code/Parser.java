package org.code;

import java.io.*;
import java.time.LocalTime;

public class Parser {
    public static void parse(File file, File result) {
        try (FileReader fileReader = new FileReader(file);
             BufferedReader reader = new BufferedReader(fileReader);
             FileWriter fileWriter = new FileWriter(result);
             BufferedWriter writer = new BufferedWriter(fileWriter))
        {
            writer.append("day").append(",").append("hour").append(",").append("operation").append("\n");
            writer.flush();

            int date = 1;
            String time;
            String timeZone = "";
            LocalTime oldTime = LocalTime.parse("00:00");
            while (reader.ready()) {
                String line = reader.readLine();

                if (line.contains("APP")) {
                    timeZone = line.substring(line.indexOf(":") + 4, line.indexOf(":") + 6);
                }

                if (line.contains(":")) {
                    LocalTime localTime = null;
                    time = line.replaceAll("^(\\D+)| *PM| +AM", "");

                    if (time.length() == 4) {
                        time = "0" + time;
                    }

                    if (timeZone.equals("PM")) {
                        localTime = LocalTime.parse(time).plusHours(12);
                    } else if (timeZone.equals("AM")) {
                        localTime = LocalTime.parse(time);
                    }

                    if (oldTime.isAfter(localTime)) {
                        date++;
                    }

                    oldTime = localTime;
                    writer.append(String.valueOf(date)).append(",").append(localTime.toString()).append(",");
                }

                if (line.contains("команда создана в графане")) {
                    writer.append("команда создана в графане").append('\n');
                } else if (line.contains("подписка для команды создана")) {
                    writer.append("подписка для команды создана").append('\n');
                } else if (line.contains("зарегистрировался")) {
                    writer.append("зарегистрировался").append('\n');
                } else if (line.contains("команда создана")) {
                    writer.append("команда создана").append('\n');
                } else if (line.contains("запустил test")) {
                    writer.append("запустил test").append('\n');
                } else if (line.contains("перешел в status TEST_STOPPING")) {
                    writer.append("перешел в status TEST_STOPPING").append('\n');
                } else if (line.contains("перешел в status CANCELED")) {
                    writer.append("перешел в status CANCELED").append('\n');
                } else if (line.contains("стартовал grafana")) {
                    writer.append("стартовал grafana").append('\n');
                } else if (line.contains("перешел в status FINISHED")) {
                    writer.append("перешел в status FINISHED").append('\n');
                } else if (line.contains("обновил подписку")) {
                    writer.append("обновил подписку").append('\n');
                } else if (line.contains("перешел в status FAILED")) {
                    writer.append("перешел в status FAILED").append('\n');
                } else if (line.contains("ошибка регистрации")) {
                    writer.append("ошибка регистрации").append('\n');
                }
                writer.flush();
                fileWriter.flush();
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
