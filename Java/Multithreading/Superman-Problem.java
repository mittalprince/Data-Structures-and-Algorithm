/*
You are designing a library of superheroes for a video game that your fellow developers will consume.
Your library should always create a single instance of any of the superheroes and return the same instance to all the requesting consumers.

Say, you start with the class Superman. Your task is to make sure that other developers using your class can never instantiate multiple copies of superman.
After all, there is only one superman!

First let us understand what the pattern is. A singleton pattern allows only a single object/instance of a class to ever exist during an application run.

There are two requirements to make a class adhere to the singleton pattern:

Declaring the constructor of a class private. When you declare the Superman class’s constructor private then the constructor isn’t visible outside the class or in its subclasses. Only the instance and static methods of the Superman class are able to access the constructor and create instances of the Superman class.
The second trick is to create a public static method usually named getInstance() to return the only instance. We create a private static object of the class Superman and return it via the getInstance() method. We can control when to instantiate the lone static private instance. Here’s what the code looks like:

*/

// Using singleton design pattern
public class SupermanNaiveButCorrect {

    // We are initializing the object inline
    private static SupermanNaiveButCorrect superman = new SupermanNaiveButCorrect();

    // We have marked the constructor private
    private SupermanNaiveButCorrect() {
    }

    public static SupermanNaiveButCorrect getInstance() {
        return superman;
    }

    // Object method
    public void fly() {
        System.out.println("I am Superman & I can fly !");
    }
}

// What if the creation of Superman is a very resource-intensive effort after all he’s coming from planet Krypton
public class SupermanWithFlaws {

    private static SupermanWithFlaws superman;

    private SupermanWithFlaws() {

    }

    // This will fail with multiple threads
    public static SupermanWithFlaws getInstance() {
        if (superman == null) {
            // A thread can be context switched at this point and
            // superman will evaluate to null for any other threads
            // testing the if condition. Now multiple threads will
            // fall into this if clause till the superman object is
            // assigned a value. All these threads will intialize the
            // superman object when it should have been initialized
            // only one.
            superman = new SupermanWithFlaws();
        }
        return superman;
    }

    // Object method
    public void fly() {
        System.out.println("I am Superman & I can fly !");
    }
}

/*
A thread can context switch out just before it initializes the Superman, causing later threads to also fall into the if clause and end up creating multiple superman objects.
The naive way to fix this issue is to use our good friend synchronized and either add synchronized to the signature of the getInstance() method or add a synchronized block within the method body
*/
public class SupermanCorrectButSlow {

    private static SupermanCorrectButSlow superman;

    private SupermanCorrectButSlow() {

    }

    public static SupermanCorrectButSlow getInstance() {
        synchronized(Superman.class) {
            if (superman == null) {
                superman = new SupermanWithFlaws();
            }
        }
        return superman;
    }

    // Object method
    public void fly() {
        System.out.println("I am Superman & I can fly !");
    }
}

// Can we synchronize only when initializing the singleton instance and not at other times? The answer is yes and leads us to an implementation known as double checked locking
public class SupermanSlightlyBetter {

    private static SupermanSlightlyBetter superman;

    private SupermanSlightlyBetter() {

    }

    public static SupermanSlightlyBetter getInstance() {

        // Check if object is uninitialized
        if (superman == null) {

            // Now synchronize on the class object, so that only
            // 1 thread gets a chance to initialize the superman
            // object. Note that multiple threads can actually find
            // the superman object to be null and fall into the
            // first if clause
            synchronized (SupermanSlightlyBetter.class) {

                // Must check once more if the superman object is still
                // null. It is possible that another thread might have
                // initialized it already as multiple threads could have
                // made past the first if check.
                if (superman == null) {
                    superman = new SupermanSlightlyBetter();
                }
            }

        }

        return superman;
    }
}

// To fix the above issue, we mark our superman static object as volatile. The happens-before semantics of volatile guarantee that the faulty scenario of threads A and B never happens.

public class Superman {

    private static volatile Superman superman;

    private Superman() {

    }

    public static Superman getInstance() {

        if (superman == null) {
            synchronized (Superman.class) {

                if (superman == null) {
                    superman = new Superman();
                }
            }
        }

        return superman;
    }

    public void fly() {
        System.out.println("I am Superman & I can fly !");
    }
}



class Demonstration {
    public static void main( String args[] ) {
        Superman superman = Superman.getInstance();
        superman.fly();
    }
}


/*
Another implementation of the singleton pattern is the holder or Bill Pugh's singleton.
The idea is to create a private nested static class that holds the static instance.
The nested class Helper isn't loaded when the outer class Superman is loaded.
The inner static class Helper is loaded only when the method getInstance() is invoked.
This saves us from eagerly initializing the singleton instance
*/

class Superman {

    private Superman() {
    }

    private static class Holder {
        private static final Superman superman = new Superman();
    }

    public static Superman getInstance() {
        return Holder.superman;
    }

    public void fly() {
        System.out.println("I am flyyyyinggggg ...");
    }
}