class Solution {
public:
   string longestPrefix(string s) {
    for (int n = s.size() - 1; n >= 0; n--)
        if (equal(s.end() - n, s.end(), s.begin()))
            return string(s.end() - n, s.end());
    return ""; // needed to compile (but never hit)
}
};
