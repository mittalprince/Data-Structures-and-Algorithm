public class ShoppingCart {
    List<Product> productList;
    public ShoppingCart(){
        this.productList = new ArrayList<>();
    }

    public void addProduct(Product product){
        Product productWithEligibleDiscount = new TypeCouponDecorator(new PercentageCouponDecorator(product, 10), 3, product.getType());
        productList.add(productWithEligibleDiscount);
    }
    public int getTotalPrice(){
        int totalPrice = 0;
        for(Product product: productList){
            totalPrice += product.getPrice();
        }
        return totalPrice;
    }
}