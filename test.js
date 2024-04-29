function BitwiseTwo(strtArr){
    let a = strtArr[0];
    let b = strtArr[1];

    let c = "";
    for(let i=0; i<a.length; i++){
        if (a[i] & b[i]) c += "1";
        else c += "0";
    }
    return c;
}
// const input = ["100", "000"];
// const input = ["10100", "11100"];
// const input = ["10111", "01101"];
// console.log(BitwiseTwo(input));

function ArrayRotation(arr) {
    let n = arr.length;
    let k = arr[0];
    arr.push(...arr.splice(0, k));
    let c = "";
    arr.forEach(a => c += a);
    return c;
}

// const a = [2,3,4,1,6,10];
// const a = [3,2,1,6];
// const a = [4,3,4,3,1,2];
// console.log(ArrayRotation(a));

function TimeConvert(num){
    let b = Math.floor(num/60);
    let c = num%60;
    return b+":"+c;
}

// const a = 45;
// console.log(TimeConvert(a));

function NumberEncoding(str){
    let c = "";
    const isAlpha = (char) => (/[a-zA-Z]/).test(char)
    for(let i=0; i<str.length; i++){
        let a = str[i];
        if(isAlpha(a)) c += a.toLowerCase().charCodeAt(0) - 97 + 1;
        else c += a;
    }
    return c;
}

// const a = "af5ca#";
// const a = "hello 45";
// const a = "jaj-a";
// console.log(NumberEncoding(a));

function  NumberSearch(str){
    const isAlpha = (char) => (/[a-zA-Z]/).test(char);
    let a = 0, b = 0;
    for(let i=0; i<str.length; i++){
        if (isAlpha(str[i])) a++;
        else if (Number(str[i]) == str[i]) b += Number(str[i]); 
    }
    return Math.floor(b/a);
}

// const a = "Hello6 9World 2, Nic8e D7ay!";
// const a = "H3ello9-9";
// const a = "One Number*1*";
// console.log(NumberSearch(a));


