package org.emualtor.mock.controller;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.emualtor.mock.dto.UserMessage;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.kafka.core.KafkaTemplate;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/messages")
@RequiredArgsConstructor
@Slf4j
public class MessagesController {

    @Autowired
    private KafkaTemplate<Long, UserMessage> kafkaTemplate;

    @PostMapping(value = "/send/{topic}",
            consumes = MediaType.APPLICATION_JSON_VALUE,
            produces = MediaType.APPLICATION_JSON_VALUE
    )
    public ResponseEntity<Object> sendMessage(@PathVariable String topic, @RequestBody UserMessage message) {
        try {
            log.info("Sending message to topic {}", topic);
            kafkaTemplate.send(topic, message);
        } catch (Exception e) {
            log.error(e.getMessage(), e);
            return ResponseEntity.status(HttpStatus.BAD_REQUEST).body(e.getMessage());
        }
        log.info("Message has been sent to topic {}", topic);
        return ResponseEntity.status(HttpStatus.OK).body(message);
    }
}
