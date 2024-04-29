public abstract class BasePizza {
    public abstract int cost();
}

// diff type of basePizza
public class Farmhouse extends BasePizza{ // IS-A relationship
    public int cost(){
        return 200;
    }
}
public class VegDelight extends BasePizza{ // IS-A relationship
    public int cost(){
        return 120;
    }
}
public class Margherita extends BasePizza{ // IS-A relationship
    public int cost(){
        return 100;
    }
}

public abstract class ToppingDecorator extends BasePizza{ // IS-A relationship + HAS-A relationship (as we have BasePizza class obj ref in child class)

}
public class ExtreaCheese extends ToppingDecorator{
    BasePizza basePizza;
    public ExtreaCheese(BasePizza basePizza){
        this.basePizza = basePizza;
    }
    public int cost(){
        return basePizza.cost() + 10;
    }
}
public class Mushroom extends ToppingDecorator{
    BasePizza basePizza;
    public Mushroom(BasePizza basePizza){
        this.basePizza = basePizza;
    }
    public int cost(){
        return basePizza.cost() + 20;
    }
}

public static void main(){
    BasePizza pizza = new Mushroom(new ExtreaCheese(new Margherita()));
}