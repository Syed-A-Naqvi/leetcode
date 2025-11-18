class Solution {
    /**
     * @param {number[]} height
     * @return {number}
     */
    trap(height) {

        let max_left = 0;
        let max_right = 0;
        let l = 0;
        let r = height.length-1;
        let totalTrapped = 0;

        while(l < r) {

            if(height[l] < height[r]){

                let trapped = max_left - height[l];
                if(trapped > 0) {totalTrapped += trapped;}
                if(max_left < height[l]) {max_left = height[l];}
                l++;
            
            }
            else {

                let trapped = max_right - height[r];
                if(trapped > 0) {totalTrapped += trapped;}
                if(max_right < height[r]) {max_right = height[r];}
                r--;
            
            }

        }

        return totalTrapped;

    }
}

const solution = new Solution();
const height = [0,2,0,3,1,0,1,3,2,1];
const result = solution.trap(height);

console.log(`Total trappable water = ${result}`)