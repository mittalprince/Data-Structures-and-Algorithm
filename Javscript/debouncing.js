// Debouncing in Javascript
let counter=0;
const getData = ()=>{
    //calls an API and get Data
    console.log("Fetching... ", counter++);
}

const debounce = function(fn, delay){
    let timer;
    return function(){
        let context=this, agrs=arguments;
        // if there will be key press event occurs between delay time
        // this will clear timeout and getData func would not call and we again start timeout.
        clearTimeout(timer);
        setTimeout(()=>{
            getData.apply(context, arguments);
        }, delay); 
    }
}

// so if there is pause in keyup event for 300 milisecond only then we will call getData API
const betterFunc = debounce(getData, 300);


// used to improve browser performance
// There might be some functionality in a web page which requires time-consuming computations. 
// If such a method is invoked frequently, it might greatly affect the performance of the browser, 
// as JavaScript is a single threaded language. Debouncing is a programming practice used to ensure 
// that time-consuming tasks do not fire so often, that it stalls the performance of the web page. 
// In other words, it limits the rate at which a function gets invoked.


// Application:
// 1. In search bar
// 2. Another application of debouncing is in content-loading webpages like Facebook and Twitter 
//    where the user keeps on scrolling. In these scenarios, if the scroll event is fired too frequently, 
//    there might be a performance impact, as it contains lots of videos and images. Thus the scroll 
//    event must make use of debouncing.

