class MinStack {

    stack = [];
    minStack = [];

    constructor() {

    }

    /*
    * @param {number} val
    * @return {void} 
    */
    push(val){

        this.stack.push(val);

        let currMin = this.minStack[this.minStack.length-1];
        console.log(`value of currmin = ${currMin}`);
        if(currMin === undefined){
            this.minStack.push(val);
        }
        else if (currMin > val){
            this.minStack.push(val);
        }

        console.log(`stack = ${this.stack}`);
        console.log(`min stack = ${this.minStack}`);
    
    }

    /*
    * @return {void} 
    */
    pop(){
        let currVal = this.stack.pop();
        let currMin = this.minStack[this.minStack.length-1];
        
        if(currMin === currVal){
            this.minStack.pop();
        }

        console.log(`stack = ${this.stack}`);
        console.log(`min stack = ${this.minStack}`);

    }

    /*
    * @return {number} 
    */    
    top(){
        console.log(`stack = ${this.stack}`);
        console.log(`min stack = ${this.minStack}`);
        return this.stack[this.stack.length - 1];
    }

    /*
    * @return {number} 
    */
    getMin(){
        console.log(`stack = ${this.stack}`);
        console.log(`min stack = ${this.minStack}`);
        return this.minStack[this.minStack.length - 1];
    }

}

let minstack = new MinStack();

minstack.push(5);
minstack.push(0);
minstack.push(2);
minstack.push(4);
console.log(minstack.getMin()); // 0
minstack.pop();
console.log(minstack.getMin()); // 0
minstack.pop();
console.log(minstack.getMin()); // 0