public class Bidder implements Colleague{
    String name;
    AuctionMediator mediator;

    Bidder(string name, AuctionMediator mediator){
        this.name = name;
        this.mediator = mediator;
    }
    public void placeBid(int bidAmount){
        mediator.addBid(this, bidAmount);
    }
    public void receiveBidNotifaction(int bidAmount){
        System.out.println("Place bid amount :" + bidAmount);
    }

    public String getName() {
        return name;
    }
}