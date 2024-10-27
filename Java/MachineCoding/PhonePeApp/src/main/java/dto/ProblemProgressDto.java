package dto;

import lombok.Builder;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@Builder
public class ProblemProgressDto {

    private String problemId;
    private LocalDateTime startTime;
    private LocalDateTime endTime;
    private ProblemProgressState problemProgressState;

}
