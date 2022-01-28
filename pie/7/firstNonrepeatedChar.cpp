// Find the First Nonrepeated Character
// https://leetcode.com/problems/first-unique-character-in-a-string/
//
// Two iterations approach using hash table / unordered_map in C++
// Runtime O(n) | Space O(n) 

class Solution {
public:
    int firstUniqChar(string s)
    {
        int index = -1;
        unordered_map<char, int> Seen;
        
        // Fill the hash-table
        for(int i = 0; i < s.length(); i++) {
            // If current char is not found on Seen map, add it
            if(Seen.find(s[i]) == Seen.end()) {
                Seen.insert(make_pair(s[i], 1));
            }
            else {
                Seen[s[i]]++;
            }
        }
        
        // Iterate to verify which is the first unique
        // char using the hash-table as reference
        for(int i = 0; i < s.length(); i++) {
            if(Seen[s[i]] == 1) {
                index = i;
                break;
            }
        }
        
        return index;
    }
};
