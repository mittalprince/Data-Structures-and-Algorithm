// Hositing -> move all the varibale and function declaration to the top of th file
// only declaration parts moved to top not initilization part

/*
how hoisting works:

even before the start of execution of program, memory is allocated to each variable and function
hecne they are already declared as memory is allocated to them, so we can easily access them before declare them in js program.

Its all working and understanding depend upen how the js prgram execution works. 
*/

var x=5;
function getName(){
    console.log("Prince Mittal");
}

getName();
console.log(x);

/*
Output ->
Prince Mittal
5
*/

getName2();
console.log(y);

var y=5;
function getName2(){
    console.log("Prince Mittal");
}

/*
Output -> (not show any err, as be access thing before decalration)
Prince Mittal
undefined
*/

getName3();
console.log(z);

var z=5;
var getName3 = ()=>{
    console.log("Prince Mittal");
}

/*
Output -> (not show any err, as be access thing before decalration)
getName3 is not a method (as we know only delcaration move) so,
var getName3;
var z;

getName3();
console.log(z);

z-5;
getName3 = ()=>{
    console.log("Prince Mittal");
}

whole program is look like this and we can see getName3 is not any method while calling it.
so output is getName3 is not a method

undefined
*/

/*
Note:
All declarations (var, let, const, function, function*, class) are "hoisted" in JavaScript. 
This means that if a name is declared in a scope, in that scope the identifier will always 
reference that particular variable:

The difference between var/function/function* declarations and let/const/class declara­tions is the initialisation.
The former are initialised with undefined or the (generator) function right when the binding is created at the top of the scope. 
The lexically declared variables however stay uninitialised. This means that a ReferenceError exception is thrown when you try to access it. 
It will only get initialised when the let/const/class statement is evaluated, everything before (above) that is called the temporal dead zone.

Temporal Dead Zone -> the time snap or time period between the declaration and intilization, as in case of let and const
they are declared but they stay uninitialized, so the time gap between declaration to initialization is temporal dead zone, as while access them in this
period will give reference err.

The temporal dead zone is not a syntactic location, but rather the time between the variable (scope) creation 
and the initialisation. It's not an error to reference the variable in code above the declaration as long as that code 
is not executed (e.g. a function body or simply dead code), and it will throw an exception if you access the variable before 
the initialisation even if the accessing code is below the declaration (e.g. in a hoisted function declaration that is called too early).

*/