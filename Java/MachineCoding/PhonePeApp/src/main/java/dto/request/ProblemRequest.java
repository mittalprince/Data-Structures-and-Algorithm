package dto.request;

import dto.ProblemDifficultyLevel;
import dto.ProblemTag;
import lombok.Builder;
import lombok.Data;

@Builder
@Data
public class ProblemRequest {

    private String description;
    private ProblemTag problemTag;
    private int score;
    private ProblemDifficultyLevel problemDifficultyLevel;
    private String problemSetterId;
}
