class Solution {
public:
    
    vector<string> vec;
    
    void paren(char ch[], int n, int idx, int op, int cl) {
        
        if(idx == 2*n) {
            ch[idx] = '\0';
            vec.push_back(ch);
            return;
        }
        
        if(op < n) {
            ch[idx] = '(';
            paren(ch, n, idx+1, op+1, cl);
        }
        
        if(cl < op) {
            ch[idx] = ')';
            paren(ch, n, idx+1, op, cl+1);
        }
    return;
    }
    vector<string> generateParenthesis(int n) {
        char ch[1000];
        if(n == 0)
            return vec;
        paren(ch, n, 0, 0, 0 );
        return vec;
        
    }
};
