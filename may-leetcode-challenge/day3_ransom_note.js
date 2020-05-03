/** 
Title :  Ransom Note
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/
Idea  :  Used map to keep count of different characters in both ransomNote and magazine, then iterate through note map and check if all its keys are present in magazine with value atleast equal to the value in note.
Time Complexity : O(R+M)
*/
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function (ransomNote, magazine) {
    var magazines = new Map();
    for (let i = 0; i < magazine.length; i++) {
        let val = magazines.has(magazine[i]) ? magazines.get(magazine[i]) : 0;
        magazines.set(magazine[i], val + 1);
    }
    var notes = new Map();
    for (let i = 0; i < ransomNote.length; i++) {
        let val = notes.has(ransomNote[i]) ? notes.get(ransomNote[i]) : 0;
        notes.set(ransomNote[i], val + 1);
    }
    for (let [key, val] of notes) {
        if (!magazines.has(key) || magazines.get(key) < val) return false;
    }
    return true;

};