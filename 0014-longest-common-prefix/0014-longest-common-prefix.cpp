class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() < 2) {
            return strs[0];
        }
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            for (int len = prefix.length(); strs[i].substr(0, len) != prefix; len = prefix.length()) {
                if (len == 0) {
                    return prefix;
                }
                prefix = prefix.substr(0, len - 1);
            }
        }
        return prefix;
    }
};