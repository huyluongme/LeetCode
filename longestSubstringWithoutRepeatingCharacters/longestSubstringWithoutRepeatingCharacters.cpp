#include <iostream>

using namespace std;

#define CHAR_RANGE 256

/*
    abcabcbb
    loop1:
        max_len = 0
        start = 0
        end = 0
        c = 'a'
        last_index[c] = -1
        update last_index[c] = 0
        window_len = 0 - 0 + 1 = 1
        -> update max_len = 1
    loop2:
        max_len = 1
        start = 0
        end = 1
        c = 'b'
        last_index[c] = -1
        update last_index[c] = 1
        window_len = 1 - 0 + 1 = 2
        -> update max_len = 2
    loop3:
        max_len = 2
        start = 0
        end = 2
        c = 'c'
        last_index[c] = -1
        update last_index[c] = 2
        window_len = 2 - 0 + 1 = 3
        -> update max_len = 3
    loop4:
        max_len = 3
        start = 0
        end = 3
        c = 'a'
        last_index[c] = 0
        -> update start = 0 + 1 = 1
        update last_index[c] = 3
        window_len = 3 - 1 + 1 = 3
        -> not update max_len
    ... 
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int start = 0, max_len = 0;

        int last_index[CHAR_RANGE];
        for(int i = 0; i < CHAR_RANGE; i++) last_index[i] = -1;
        
        for(int end = 0; end < len; end++) {
            unsigned char c = (unsigned char)s[end];
            if(last_index[c] >= start) {
                start = last_index[c] + 1;
            }

            last_index[c] = end;

            int window_len = end - start + 1;
            if(window_len > max_len)
                max_len = window_len;
        }

        return max_len;
    }
};

int main() {
    string s1("abcabcbb");
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s1);
    return 0;
}