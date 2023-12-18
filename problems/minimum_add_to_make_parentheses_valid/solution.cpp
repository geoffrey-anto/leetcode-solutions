class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        int x=0;
        for(auto i:s){
            if(i=='(')
				count++;
			else 
			{
				if(count==0)
				{
					x++;
				}
				else
				{
					 count--;
				}
			}
        }
        return abs(count+x);
    }
};