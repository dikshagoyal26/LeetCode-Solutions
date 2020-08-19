/** 
Title :   Goat Latin
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3429/
Idea  :   Splitting the string into words, modifying them as asked and then rejoining them
Time Complexity : O(n)
*/

/*
    A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.
    We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)
    The rules of Goat Latin are as follows:
    If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
    For example, the word 'apple' becomes 'applema'.
    If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
    For example, the word "goat" becomes "oatgma".
    Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
    For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
    Return the final sentence representing the conversion from S to Goat Latin. 

    Example 1:
    Input: "I speak Goat Latin"
    Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
    
    Example 2:
    Input: "The quick brown fox jumped over the lazy dog"
    Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
    
    Notes:
    S contains only uppercase, lowercase and spaces. Exactly one space between each word.
    1 <= S.length <= 150.
*/
/**
 * @param {string} S
 * @return {string}
 */
function isVowel(ch) {
    switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
    }
    return false;
}

/* Approach 1 */
var toGoatLatin = function (S) {
    let arr = S.split(' ');
    let s = '';
    for (let i = 1; i <= arr.length; i++) {
        s += 'a';
        if (isVowel(arr[i - 1][0])) {
            arr[i - 1] += 'ma';
        } else {
            let ch = arr[i - 1][0]
            arr[i - 1] = arr[i - 1].substring(1);
            arr[i - 1] += ch + 'ma';
        }
        arr[i - 1] += s;
    }
    return arr.join(' ');
};

/* Approach 2 */
var toGoatLatin = function (S) {
    return S.split(' ').map((el, i) => {
        return `${isVowel(el[0]) ? el : el.substring(1) + el[0]}ma${'a'.repeat(i + 1)}`;
    }).join(' ')
};