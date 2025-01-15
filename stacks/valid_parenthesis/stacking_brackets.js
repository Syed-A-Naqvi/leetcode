class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isValid(s){

        const stack = []
        const bracketPairs = {
            ')' : '(',
            '}' : '{',
            ']' : '['
        };

        for (const c of s) {
            if(bracketPairs[c]){
                if(stack.length > 0 && stack[stack.length - 1] === bracketPairs[c]){
                    stack.pop();
                }
                else {
                    return false;
                }
            }
            else{
                stack.push(c);
            }
        }

        return stack.length === 0;

    }
}

let parenthesis_check = new Solution();
let s = "([{}])"

console.log(parenthesis_check.isValid(s));