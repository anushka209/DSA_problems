class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long rev=0;
        long long temp=x;
        while(temp!=0)
        {
            int digit=temp%10;
            rev=rev*10+digit;
            temp=temp/10;
        }
        return (rev==x);
    }
};