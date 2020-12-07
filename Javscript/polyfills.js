// Implement Bind Function

let name={
    firstname: "Prince",
    lastname: "Mittal",
}
let friend={
    firstname: "Akshay",
    lastname: "Katyal",
}

let printFullName = function(homwtown, state, country){
    console.log(this.firstname + " " + this.lastname + ", " + homwtown + ", " + state + ", " + country);
}
let printMyName = printFullName.bind(name, "Delhi");
printMyName("Delhi", "India"); // traditional bind func works

Function.prototype.mybind =function(...agrs){
    // ...agrs will be the arr of arguments passed
    // we use when we dont know about exact agrument list
    // here this refer for printFullName, as it call bind method
    let context = this;
    let params = agrs.slice(1);
    return function(...args2){ // ...agrs2-> arguments given in printMyName func
        // context.call(agrs[0]);
        context.apply(agrs[0], [...params, ...args2]);
    }
}

let printMyName2 = printFullName.mybind(friend, "Amritsar");
printMyName2("Punjab", "India"); 