// Throttling in JS

const expensive = ()=>{
    console.log("Fetching...");
}

const throttle = function(fn, delay){
    let flag=true;
    return function(){
        let context=this, args=arguments;
        // calls fn only whenflag is set
        // once we call fn we set false flag and again set after certain dealy
        if(flag){
            fn.apply(context, args);
            flag=false;
            setTimeout(()=>{
                flag=true;
            },delay);
        }
    }
}

const bettweExpensive = throttle(expensive, 500);

/*
Throttling or sometimes is also called throttle function is a practice used in websites. 
Throttling is used to call a function after every millisecond or a particular interval of 
time only the first click is executed immediately.
*/