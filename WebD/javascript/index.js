function fun(){
    console.log(this);

    return 1;
}
fun();
let arr=[1,2,3,4,5];
function newpollyfill(arr,co){
    let newArr=[];
    for(let i=0;i<arr.length;i++){
        newArr[i]=co(arr[i]);
    }
    return newArr;
}

function co(l){
    return l*l;
}
console.log(newpollyfill(arr,co));

function pollymap(arr,ma){
    let newArr=[];
    for(let i=0;i<arr.length;i++){
        if(ma(arr[i])===true)
            newArr.push(arr[i]);
    }
    return newArr;
}
function ma(l){
    if(l%2===0)
        return true;
    return false;
}

console.log(pollymap(arr,ma));

function pollyfill3(sum,arr,elel)
