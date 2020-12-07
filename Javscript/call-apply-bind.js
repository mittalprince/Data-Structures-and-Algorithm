let test={
    firstname:"Prince",
    lastname:"Mittal",
    getFullName: function(){
        // here this refer to parent obj
        console.log(this.firstname+" "+this.lastname);
    }
}

test.getFullName();
/*
make an object and use methods
*/

let printFullName = function(){
    console.log(this.firstname + " " + this.lastname);
}

let name={
    firstname: "Akshay",
    lastname: "Katyal",
}


// Borrow a function
/*
here borrow a function from diff object or any other func and call it using 
call method of JS. the first agrument always is object context, means for which obje we access data
as here name obj firstname, lastname value used, by this. so this basically refer to name obj
*/
/*
call to check borrow -> test.getFullName.call(name);
*/

// Best practice is to make function outside obj when we want to reuse it 

printFullName.call(name); 
/*
so here we borrow a general function
*/

/*
Syntax ->

1. call = .call(context, agrument1, agrument2,..., argumentn);
2. apply = .apply(context, [arguments arr])
*/


// bind Method
let printMyName = printFullName.bind(name);

/*
So in bind we just made copy of it and bind with obj and also we can invoke it later
as it gives us an copy and not call immediately like happen in call or apply
*/
console.log(printMyName);
printMyName();