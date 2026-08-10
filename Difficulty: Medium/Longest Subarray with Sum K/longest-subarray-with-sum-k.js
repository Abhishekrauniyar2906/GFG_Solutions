/**
 * @param {number[]} arr
 * @param {number} k
 * @returns {number}
 */
class Solution {
    longestSubarray(arr, k) {
        // code here
        let left = 0;
        let longest = 0;
        let map = new Map()
        let sum = 0;
        
        for(let i = 0; i < arr.length; i++){
            sum += arr[i];
            
            if(sum == k){
                longest = i + 1;
            }
            
            if(map.has(sum - k)){
                longest = Math.max(longest, i - map.get(sum - k));
            }
            
            if(!map.has(sum)){
                map.set(sum, i);
            }
        }
        return longest
    }
}
