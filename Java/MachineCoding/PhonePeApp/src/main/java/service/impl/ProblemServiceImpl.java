package service.impl;

import dto.*;
import dto.request.ProblemRequest;
import dto.request.UserIdToTimeMapping;
import lombok.extern.slf4j.Slf4j;
import org.apache.commons.lang3.StringUtils;
import service.ProblemService;

import java.sql.Time;
import java.time.LocalDateTime;
import java.time.Period;
import java.time.temporal.ChronoUnit;
import java.util.*;

@Slf4j
public class ProblemServiceImpl implements ProblemService {

    public Map<String, List<ProblemProgressDto>> userIdToSolvedProblemMapping = new HashMap<>();
    public Map<String, List<ProblemProgressDto>> userIdToInProgressProblemMapping = new HashMap<>();
    public Map<String, List<UserIdToTimeMapping>> problemIdIdToSolvedUsersMapping = new HashMap<>();
    public Map<String, Integer> userIdToScoreMapping = new HashMap<>();

    public Map<String, Problem> problemIdToProblemMapping = new HashMap<>();
    public Map<ProblemTag, List<String>> problemTagToProblemIdMapping = new HashMap<>();
    public Map<ProblemDifficultyLevel, List<String>> problemDifficultyToProblemIdMapping = new HashMap<>();

    @Override
    public String registerNewProblem(ProblemRequest problemRequest) {

        if (Objects.isNull(problemRequest) || StringUtils.isEmpty(problemRequest.getDescription())) {
            return StringUtils.EMPTY;
        }

        Problem problem = Problem
                .builder()
                .id(UUID.randomUUID().toString())
                .description(problemRequest.getDescription())
                .problemTag(problemRequest.getProblemTag())
                .problemDifficultyLevel(problemRequest.getProblemDifficultyLevel())
                .problemSetterId(problemRequest.getProblemSetterId())
                .score(problemRequest.getScore())
                .build();

        problemIdToProblemMapping.put(problem.getId(), problem);
        registerProblemToTag(problem);
        registerProblemToDifficultyLevel(problem);
        return problem.getId();
    }

    @Override
    public void startProblemSolving(String userId, String problemId) {

        List<ProblemProgressDto> currentlyInProgressProblems = userIdToInProgressProblemMapping.get(userId);

        for (ProblemProgressDto problemProgressEntity : currentlyInProgressProblems) {

            if (problemProgressEntity.getProblemId().equals(problemId)) {
                return;
            }
        }

        if (!userIdToInProgressProblemMapping.containsKey(userId)) {
            currentlyInProgressProblems = new ArrayList<>();
        }
        ProblemProgressDto problemProgressDto = ProblemProgressDto
                .builder()
                .problemId(problemId)
                .startTime(LocalDateTime.now())
                .problemProgressState(ProblemProgressState.IN_PROGRESS)
                .build();
        currentlyInProgressProblems.add(problemProgressDto);
        userIdToInProgressProblemMapping.put(userId, currentlyInProgressProblems);

    }

    @Override
    public void submitSolutionToProblem(String userId, String problemId) {

        List<ProblemProgressDto> currentlyInProgressProblems = userIdToInProgressProblemMapping.get(userId);
        ProblemProgressDto problemProgressDto = null;
        for (ProblemProgressDto problemProgressEntity : currentlyInProgressProblems) {

            if (problemProgressEntity.getProblemId().equals(problemId)) {
                problemProgressDto = problemProgressEntity;
                currentlyInProgressProblems.remove(problemProgressEntity);
                break;
            }
        }
        userIdToInProgressProblemMapping.put(userId, currentlyInProgressProblems);

        problemProgressDto.setEndTime(LocalDateTime.now());
        problemProgressDto.setProblemProgressState(ProblemProgressState.COMPLETED);

        List<ProblemProgressDto> currentlyCompletedProblems = userIdToSolvedProblemMapping.get(userId);
        if (Objects.isNull(currentlyCompletedProblems)) {
            currentlyCompletedProblems = new ArrayList<>();
        }
        currentlyCompletedProblems.add(problemProgressDto);
        userIdToSolvedProblemMapping.put(userId, currentlyCompletedProblems);

        // update user score
        int getScore = problemIdToProblemMapping.get(problemId).getScore(); // we can add strategy pattern here to add more stragegies for scoring
        Integer currentScore = userIdToScoreMapping.get(userId);
        if (Objects.isNull(currentScore)) {
            currentScore = 0;
        }
        currentScore+= getScore;
        userIdToScoreMapping.put(userId, currentScore);

        // ad to users solved problem
        List<UserIdToTimeMapping> solvedUsersMapping = problemIdIdToSolvedUsersMapping.get(problemId);
        if (Objects.isNull(solvedUsersMapping)) {
            solvedUsersMapping = new ArrayList<>();
        }
        solvedUsersMapping.add(UserIdToTimeMapping
                .builder()
                .userId(userId)
                .timeTaken(ChronoUnit.MINUTES.between(problemProgressDto.getStartTime(), problemProgressDto.getEndTime()))
                .build());
        problemIdIdToSolvedUsersMapping.put(problemId, solvedUsersMapping);
    }

    @Override
    public List<ProblemProgressDto> getProblemsSolvedByUser(String contestantId) {
        List<ProblemProgressDto> problemProgressDtoList = userIdToSolvedProblemMapping.get(contestantId);
        if (Objects.isNull(problemProgressDtoList)) {
            return new ArrayList<>();
        }
        return problemProgressDtoList;
    }

    @Override
    public AverageTimeWithCountDto findNumberOfUsersWithTimeOfSolving(String firstProblemId) {
        List<UserIdToTimeMapping> userIdToTimeMappingList = problemIdIdToSolvedUsersMapping.get(firstProblemId);
        long averageTime = 0L;
        for (UserIdToTimeMapping userIdToTimeMapping : userIdToTimeMappingList) {
            averageTime+= userIdToTimeMapping.getTimeTaken();
        }
        return AverageTimeWithCountDto
                .builder()
                .numberOfSolvedUsers(userIdToTimeMappingList.size())
                .minutes(averageTime/userIdToTimeMappingList.size())
                .build();
    }

    @Override
    public int getUserScore(String userId) {
        Integer score = userIdToScoreMapping.get(userId);

        if (Objects.isNull(score)) {
            return 0;
        }
        return score;
    }

    private void registerProblemToDifficultyLevel(Problem problem) {

        List<String> problemIdsForGivenDifficulty = problemDifficultyToProblemIdMapping.get(problem.getProblemDifficultyLevel());
        problemIdsForGivenDifficulty.add(problem.getId());
        problemDifficultyToProblemIdMapping.put(problem.getProblemDifficultyLevel(), problemIdsForGivenDifficulty);
    }

    private void registerProblemToTag(Problem problem) {
        List<String> problemIdsForGivenTag = problemTagToProblemIdMapping.get(problem.getProblemTag());
        problemIdsForGivenTag.add(problem.getId());
        problemTagToProblemIdMapping.put(problem.getProblemTag(), problemIdsForGivenTag);
    }
}
