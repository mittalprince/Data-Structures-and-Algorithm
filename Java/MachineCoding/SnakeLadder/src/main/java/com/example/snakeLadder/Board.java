package com.example.snakeLadder;

import java.util.concurrent.ThreadLocalRandom;

public class Board {
    private Cell[][] cells;

    public Board(int boardSize, int numberOfSnakes, int numberOfLadders){
        initializeCells(boardSize);
        addSnakesAndLadders(numberOfSnakes, numberOfLadders);
    }

    public int getBoardSize(){
        return cells.length * cells.length-1;
    }
    private void initializeCells(int boardSize){
        cells = new Cell[boardSize][boardSize];
        for(int i=0; i<boardSize; i++){
            for(int j=0; j<boardSize; j++){
                Cell obj = new Cell();
                cells[i][j] = obj;
            }
        }
    }

    private void addSnakesAndLadders(int numberOfSnakes, int numberOfLadders){
        while(numberOfSnakes>0){
            int snakeHead = ThreadLocalRandom.current().nextInt(1, getBoardSize());
            int snakeTail = ThreadLocalRandom.current().nextInt(1, getBoardSize());
            if (snakeTail >= snakeHead) {
                continue;
            }
            Jump snakeObj = new Jump(snakeHead, snakeTail);
            Cell cell = getCell(snakeHead);
            cell.setJump(snakeObj);
            numberOfSnakes--;
        }
        while (numberOfLadders>0) {
            int ladderHead = ThreadLocalRandom.current().nextInt(1, cells.length * cells.length - 1);
            int ladderTail = ThreadLocalRandom.current().nextInt(1, cells.length * cells.length - 1);
            if (ladderTail <= ladderHead) {
                continue;
            }
            Jump ladderObj = new Jump(ladderHead, ladderTail);
            Cell cell = getCell(ladderHead);
            cell.setJump(ladderObj);
            numberOfLadders--;
        }
    }

    public Cell getCell(int playerPosition){
        int row = playerPosition/cells.length;
        int col = playerPosition % cells.length;
        return cells[row][col];
    }
}
