public class TypeCouponDecorator extends CouponDecorator{
    Product product;
    int discountPercentage;
    ProductType type;
    static List<ProductType> eligibleTypes = new ArrayList<>();
    static {
        eligibleTypes.add(ProductType.FURNITURE_GOODS);
        eligibleTypes.add(ProductType.DECORATIVE_GOODS);
    }
    TypeCouponDecorator(Product product, int discountPercentage, ProductType type){
        this.product = product;
        this.discountPercentage = discountPercentage;
        this.type = type;
    }
    public double getPrice(){
        double price = product.getPrice();
        if(eligibleTypes.contains(type)){
            return price - (price * discountPercentage)/100;
        }
        return price;
    }
}