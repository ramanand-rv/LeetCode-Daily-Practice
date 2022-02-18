class Solution {
public:
string removeKdigits(string num, int k) {
          string s="";
        int diff=num.length()-k;
        if(diff==0)
            return "0";
        for(int i=0;i<num.length();)
        {
            int k=i;
            int res=INT_MAX;
            for(int j=i;j<=num.length()-diff;j++)
            {
                int t=num[j]-48;
                if(res>t)
                {
                    res=t;
                    k=j;
                }
            }
            s+=num[k];
            diff=diff-1;
            i=k+1;
            if(diff==0)
                break;
            
        }
       
        int i;
        for(i=0;i<num.length()-k;i++)
        {
            if(s[i]!='0')
                break;
        }
        if(i==num.length()-k)
            return "0";
        return s.substr(i);
}
};