/*
what is block -> area covered by {}
Blocks is also known as Compound statement. It is used to combine multiple statement 
into one grp.

blocks is basically wrapping up of multiple statement into one so that we can use
it in a place where js expect one single statement.

like if(true) -> expected end of input, means here js expected a statement
if(true)true; // works
if(true){
    // works
    // so wrapping up of multiple statemnt into one where js so that we can use it where 
    js can expect a single statement
}
*/


/*

Shadowing:
rewriting the value or shadow or occupy the same memory location

var a=100;
{
    var a=200; // shadowing occurs, as both a are in global scopre and pointing to same location
    console.log(a); //200;
}
console.log(a); //200;


let a=100;
{
    var a=200; // illegal shaowing, as it would not as var in global scope, so redeclaration of a err occurs
}
*/