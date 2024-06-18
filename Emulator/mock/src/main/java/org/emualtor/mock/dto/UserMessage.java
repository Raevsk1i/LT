package org.emualtor.mock.dto;

import lombok.Data;

@Data
public class UserMessage {
    private String rqUID;
    private String clientId;
    private String openDate;
    private String closeDate;
}
