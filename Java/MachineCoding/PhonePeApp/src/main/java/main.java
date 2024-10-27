import dto.*;
import dto.request.ProblemRequest;
import dto.request.UserRequest;
import service.ProblemService;
import service.UserService;
import service.impl.ProblemServiceImpl;
import service.impl.UserServiceImpl;

import java.util.List;

public class main {

    public static void main(String[] args) {

        UserService userService = new UserServiceImpl();
        ProblemService problemService = new ProblemServiceImpl();
        // register a problem setter
        UserRequest userProblemSetterRequest = UserRequest
                .builder()
                .contactNumber("8826783898")
                .department("UPI")
                .name("Rishabh")
                .userCategory(UserCategory.PROBLEM_SETTER)
                .build();

        // register a contestant
        UserRequest userContestantRequest = UserRequest
                .builder()
                .contactNumber("9876567890")
                .department("UPI")
                .name("Shubham")
                .userCategory(UserCategory.CONTESTANT)
                .build();

        String problemSetterId = userService.registerNewUser(userProblemSetterRequest);
        String contestantId = userService.registerNewUser(userContestantRequest);

        // register a problem
        ProblemRequest problemRequest = ProblemRequest
                .builder()
                .description("Solve this question with given array")
                .problemTag(ProblemTag.ARRAYS)
                .problemDifficultyLevel(ProblemDifficultyLevel.HARD)
                .score(50)
                .problemSetterId(problemSetterId)
                .build();

        ProblemRequest problemRequest2 = ProblemRequest
                .builder()
                .description("Solve this question with given stacks")
                .problemTag(ProblemTag.STACK)
                .problemDifficultyLevel(ProblemDifficultyLevel.HARD)
                .score(70)
                .problemSetterId(problemSetterId)
                .build();


        String firstProblemId = problemService.registerNewProblem(problemRequest);
        String secondProblemId = problemService.registerNewProblem(problemRequest2);

        // contestant starts first problem
        problemService.startProblemSolving(contestantId, firstProblemId);

        // contestant starts second problem
        problemService.startProblemSolving(contestantId, secondProblemId);

        // contestant finish second problem
        problemService.submitSolutionToProblem(contestantId, secondProblemId);

        // get solved user problems
        List<ProblemProgressDto> solvedProblemIds = problemService.getProblemsSolvedByUser(contestantId);

        // get num of users who solved a problem with time
        AverageTimeWithCountDto averageTimeWithCountDto = problemService.findNumberOfUsersWithTimeOfSolving(firstProblemId);

        // get usre score
        int userScore = problemService.getUserScore(contestantId);

    }

}