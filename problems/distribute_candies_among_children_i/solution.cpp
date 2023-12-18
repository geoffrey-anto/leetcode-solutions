class Solution
{
public:
    int distributeCandies(int n, int limit)
    {
        int cnt = 0;
        
        int mn = (min(n, limit));
        
        // no of candy child a recieves
        for (int i = 0; i <= mn; i++)
        {
            for (int j = 0; j <= min(n - i, limit); j++)
            {
                // check if there is candies left after 2nd is taken
                if ((n - i - j) >= 0 )
                {
                    // now check if they are less or eq to the limit given
                    if((n - i - j) <= limit){
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};