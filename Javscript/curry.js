// sum(1)(2)(3)...(n);

let sum = function(a){
    if(a){
        return function(b){
            if(b){
                return sum(a+b);
            }
            return a;
        }
    }
    return 0;
}