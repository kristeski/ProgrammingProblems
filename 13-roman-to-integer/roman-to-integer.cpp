class Solution {
public:
    int f(char ch) {
        if(ch == 'I')
            return 1;
        if(ch == 'V')
            return 5;
        if(ch == 'X')
            return 10;
        if(ch == 'L')
            return 50;
        if(ch == 'C')
            return 100;
        if(ch == 'D')
            return 500;
        if(ch == 'M')
            return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int sum = 0;
        sum += f(s[0]);
        int prev = f(s[0]);
        for(int i = 1; i < s.size(); i++) {
            sum += f(s[i]);
            if(prev < f(s[i]))
                sum -= 2 * prev;
            prev = f(s[i]);
        }
        return sum;
    }
};