class Solution {
public:
   string longestPrefix(string s) {
    for (int n = s.size() - 1; n >= 0; n--)
        if (equal(s.end() - n, s.end(), s.begin()))
            return string(s.end() - n, s.end());
    return ""; // needed to compile (but never hit)
}
};


//lps
int longestPrefixSuffix(string s) 
{ 
    int n = s.length(); 
  
    int lps[n]; //lps[i]代表s[0]到s[i]的longest共同suf pre的長度
    lps[0] = 0; // lps[0] is always 0 

    int len = 0; 
  
    int i = 1; 
    while (i < n) 
    { 
        if (s[i] == s[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else 
        { 
            if (len != 0) 
            { 
                len = lps[len-1]; 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
  
    int res = lps[n-1]; 
  
    return (res > n/2)? n/2 : res; 
} 
  
// Driver program to test above function 
int main() 
{ 
    string s = "abcab"; 
    cout << longestPrefixSuffix(s); 
    return 0; 
} 
