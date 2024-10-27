package dto;

import lombok.Builder;
import lombok.Data;

@Data
@Builder
public class Problem {

    private String id;
    private String description;
    private ProblemTag problemTag;
    private int score;
    private ProblemDifficultyLevel problemDifficultyLevel;
    private String problemSetterId;

}
