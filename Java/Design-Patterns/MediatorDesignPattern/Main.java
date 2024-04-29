public class Main {
    public static void main(String args[]){
        AuctionMediator mediator = new Auction();
        Colleague bidder1 = new Bidder("A", mediator);
        Colleague bidder2 = new Bidder("B", mediator);

        bidder1.placeBid(2000);
        bidder2.placeBid(3000);
        bidder1.placeBid(4000);
    }
}