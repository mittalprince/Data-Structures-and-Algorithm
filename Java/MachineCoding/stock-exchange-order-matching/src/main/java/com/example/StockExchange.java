package com.example;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class StockExchange {
    private PriorityQueue<Order> buyOrders = new PriorityQueue<>();
    private PriorityQueue<Order> sellOrders = new PriorityQueue<>();

    public void processOrder(Order order){
        List<Trade> trades = new ArrayList<>();
        if (order.getType().equals(StockType.BUY)){
            matchOrder(order, sellOrders, trades);
            if(order.getQuantity()>0) buyOrders.offer(order); // Add remaining quantity
        } else{
            matchOrder(order, buyOrders, trades);
            if(order.getQuantity()>0) sellOrders.offer(order); // Add remaining quantity
        }

        trades.forEach(System.out::println);
    }
    private void matchOrder(Order order, PriorityQueue<Order>oppositeOrders, List<Trade> trades){
        while (!oppositeOrders.isEmpty() && order.getQuantity()>0){
            Order match = oppositeOrders.peek();
            boolean isMatch = order.getType().equals(StockType.BUY) ?
                    order.getPrice() >= match.getPrice() :
                    order.getPrice() <= match.getPrice() ;
            if(!isMatch) break;

            int tradeQuantity = Math.min(order.getQuantity(), match.getQuantity());
            trades.add(new Trade(
                    order.getType().equals(StockType.BUY) ? order.getId() : match.getId(),
                    order.getType().equals(StockType.BUY) ? match.getId() : order.getId(),
                    match.getPrice(),
                    tradeQuantity
            ));
            order.setQuantity(order.getQuantity()-tradeQuantity);
            match.setQuantity(match.getQuantity()-tradeQuantity);
            if (match.getQuantity() == 0) oppositeOrders.poll();
        }
    }
    public static void main(String[] args) throws FileNotFoundException {
        if (args.length != 1) {
            System.err.println("Usage: java StockExchange <input_file>");
            return;
        }
        StockExchange stockExchange = new StockExchange();
        try (BufferedReader bufferedReader = new BufferedReader(new FileReader(args[0]))){
            String line;
            while ((line = bufferedReader.readLine()) != null){
                String[] parts = line.split(" ");
                Order order = new Order(
                        parts[0],
                        parts[1],
                        parts[2],
                        StockType.valueOf(parts[3].toUpperCase()),
                        Double.parseDouble(parts[4]),
                        Integer.parseInt(parts[5])
                );
                stockExchange.processOrder(order);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}