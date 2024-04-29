package LowLevelDesign.LLDSnakeLadder;

import java.util.concurrent.ThreadLocalRandom;
public class Board {
    Cell[][] cells;

    Board(int boardSize, int numberOfSnakes, int numberOfLadders){
        initializeCells(boardSize);
        addSnakesAndLadders(numberOfSnakes, numberOfLadders);
    }
    private void initializeCells(int boardSize){
        cells = new Cell[boardSize][boardSize];
        for(int i=0; i<boardSize; i++){
            for(j=0; j<boardSize; j++){
                Cell obj = new Cell();
                cell[i][j] = obj;
            }
        }
    }
    private void addSnakesAndLadders(int numberOfSankes, int numberOfLadders) {
        while (numberOfSankes) {
            int snakeHead = ThreadLocalRandom.current().next(1, cells.length * cell.length - 1);
            int snakeTail = ThreadLocalRandom.current().next(1, cells.length * cells.length - 1);
            if (snakeTail >= snakeHead) {
                continue;
            }
            Jump snakeObj = new Jump();
            snakeObj.start = snakedHead;
            snakeObj.end = snakeTail;

            Cell cell = getCell(snakeHead);
            cell.jump = snakeObj;
            numberOfSankes--;
        }
        while (numberOfLadders) {
            int ladderHead = ThreadLocalRandom.current().next(1, cells.length * cell.length - 1);
            int ladderTail = ThreadLocalRandom.current().next(1, cells.length * cells.length - 1);
            if (ladderTail <= ladderHead) {
                continue;
            }
            Jump ladderObj = new Jump();
            ladderObj.start = ladderHead;
            ladderObj.end = ladderTail;

            Cell cell = getCell(ladderHead);
            cell.jump = ladderObj;
            numberOfLadders--;
        }
    }
    Cell getCell(int playerPosition){
        int row = playerPosition/cells.length;
        int col = (playerPosition % cells.length);
        return cells[row][col];
    }
}