class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isValid(s){

        let par_stack = []
        let openBrackets = new Set(['(', '[', '{']);
        let closeBrackets = new Set([')', ']', '}']);
        
        if (s == ''){
            return true;
        }

        for (let c of s){

            if (openBrackets.has(c)){             
                par_stack.push(c);
            }
            else if (closeBrackets.has(c)){
                let open = par_stack.pop();
                if (!open){
                    return false; 
                } else if(open == '(' && c != ')'){
                    print();
                    return false;
                } else if(open == '[' && c != ']'){
                    print();
                    return false;
                } else if(open == '{' && c != '}'){
                    print();
                    return false;
                }
            }
        }
        
        if (par_stack.length){
            return false;
        }
        else {
            return true;
        }

    }
}

let parenthesis_check = new Solution();
let s = "([{}])"

console.log(parenthesis_check.isValid(s));