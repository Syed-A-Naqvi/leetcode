class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number}
     */
    search(nums, target) {
        
        let l = 0;
        let r = nums.length-1;
        let m = Math.floor(r/2);

        while (!(l > r)) {

            console.log(`l = ${l}`);
            console.log(`r = ${r}`);
            console.log(`m = ${m}`);

            if (nums[m] === target) {
                return m;
            }
            if (nums[l] === target) {
                return l;
            }
            if (nums[r] === target) {
                return r;
            }

            if (nums[m] < target) {
                l = m+1;
            }
            else if (nums[m] > target) {
                r = m-1;
            }

            m = Math.floor( (l + r) / 2 );
        }

        return -1;

    }

}

target = 4;
nums = [-1,0,2,4,6,8];

const mysol = new Solution();
console.log(`Target = ${target}, Index = ${mysol.search(nums, target)}`);