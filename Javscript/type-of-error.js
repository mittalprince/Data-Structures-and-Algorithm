/*

Reference Err -> occur when we try to access the memory that are not currently allocated or exist in scope.
Syntax Error -> Missing initializer in const variable: means const variable must be initialized while declaring.
and once declared and initialize can not change, if try to chnage gives typerror

let a;
console.log(a); // reference error, due to temporal zone it is declared but not initialized with undefined


const b;
b=100; // syntax error

const b=100;
b=1000; // typerror

const a={}
a.b=100; // works

a.b=6; // works;
a={} // typeerror
*/