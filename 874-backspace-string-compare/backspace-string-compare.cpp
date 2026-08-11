class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.size(), n = t.size();

        int i = m - 1, j = n - 1;
        int skips = 0, skipt = 0;

        while (i >= 0 || j >= 0) {

            // Process string s
            while (i >= 0) {
                if (s[i] == '#') {
                    skips++;
                    i--;
                } else if (skips > 0) {
                    skips--;
                    i--;
                } else {
                    break;
                }
            }

                while (j >= 0) {

                    if (t[j] == '#') {
                        skipt++;
                        j--;
                    } else if (skipt > 0) {
                        skipt--;
                        j--;
                    } else {
                        break;
                    }
                }

                // Compare current valid characters
                if (i >= 0 && j >= 0) {
                    if (s[i] != t[j]) {
                        return false;
                    }
                } else if (i >= 0 || j >= 0) {
                    return false;
                }

                i--;
                j--;
            
        }
            return true;
        }
    };