class Solution {

    /**
     * @param {number[]} nums
     * @return {number} 
     */
    findMin(nums){
        
        let l = 0, r = nums.length-1, m = 0;
        while (l < r) {
            
            m = Math.floor( (l+r) / 2);
            console.log(`l = ${l}, m = ${m}, r = ${r} `);
            console.log(`nums[${l}] = ${nums[l]}, nums[${m}] = ${nums[m]}, nums[${r}] = ${nums[r]}`);
            console.log();
            
            if(nums[m] < nums[r]){
                r = m;
            }
            else {
                l = m+1;
            }

        }

        return nums[l];

    }
}

let nums = [3,4,5,6,1,2];
let mySol = new Solution();

console.log(`minimum element is ${mySol.findMin(nums)}`);
