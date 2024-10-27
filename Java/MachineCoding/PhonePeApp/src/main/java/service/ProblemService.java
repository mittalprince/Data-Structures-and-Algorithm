package service;

import dto.AverageTimeWithCountDto;
import dto.ProblemProgressDto;
import dto.request.ProblemRequest;

import java.util.List;

public interface ProblemService {

    String registerNewProblem(ProblemRequest problemRequest);

    void startProblemSolving(String userId, String problemId);

    void submitSolutionToProblem(String userId, String problemId);


    List<ProblemProgressDto> getProblemsSolvedByUser(String contestantId);

    AverageTimeWithCountDto findNumberOfUsersWithTimeOfSolving(String firstProblemId);

    int getUserScore(String userId);
}
