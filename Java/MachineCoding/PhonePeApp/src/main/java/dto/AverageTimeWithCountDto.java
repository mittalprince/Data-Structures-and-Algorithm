package dto;

import lombok.Builder;
import lombok.Data;

@Data
@Builder
public class AverageTimeWithCountDto {

    private long minutes;
    private int numberOfSolvedUsers;
}
