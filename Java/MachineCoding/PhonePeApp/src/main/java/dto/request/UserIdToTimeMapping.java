package dto.request;

import lombok.Builder;
import lombok.Data;

import java.time.LocalDateTime;
import java.time.Period;

@Builder
@Data
public class UserIdToTimeMapping {

    private String userId;
    private long timeTaken;
}
