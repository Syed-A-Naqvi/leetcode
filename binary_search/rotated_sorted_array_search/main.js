class Solution {

    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number} 
     */
    search(nums, target){
        
        // first we find the index of the minimum value to determine the rotation offset
        // Time: O(logn)
        // Space: O(1)
        
        let l = 0, m = 0, r = nums.length - 1;
        
        while(l < r) {
            
            m = Math.floor( (l+r) / 2);

            if (nums[m] < nums[r]) {
                r = m;
            }
            else {
                l = m + 1;
            }

        }



        // extract the offset and reinitialize for target binary search
        
        let offset = l, m_off = 0;
        l = 0, m = 0, r = nums.length - 1;
        
        while(l <= r) {
        
            m = Math.floor( (l+r) / 2);
            m_off = (m + offset) % nums.length;
            console.log(`offset = ${offset}, m_off = ${m_off}, m = ${m}`);

            if(nums[m_off] === target) {
                return m_off;
            }
            else if (nums[m_off] < target) {
                l = m + 1;
            }
            else if (nums[m_off] > target) {
                r = m - 1;
            }

        }

        //return -1 if target not found
        return -1;

    }
}

let nums = [4,5,6,7,0,1,2], target = 0;
let mySol = new Solution();

console.log(`target index is ${mySol.search(nums, target)}`);

