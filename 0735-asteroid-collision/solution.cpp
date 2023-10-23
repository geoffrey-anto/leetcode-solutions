class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        int n = a.size();

        for(
            int i=0;
            i < n;
            i++
        ) {
            int asteriod = a[i];
            // Check if it is empty and +ve ; then push it
            if(st.empty() || asteriod > 0) {
                st.push(asteriod);
            } else {
                // If it has a value or the value at curr is negative
                while(true) {
                    // get the recently seen one
                    int top = st.top();
                    int curr = a[i];

                    // if it is negative push the negative and continue for next A[i]
                    if(top < 0) {
                        st.push(curr);
                        break;
                    // if not both are the same value of oppo sign the remove thr val at stack and go
                    } else if (top == -curr) {
                        st.pop();
                        break;
                    // if the val moving right is greater keep it and dont add the negative smaller
                    } else if(top > -curr) {
                        break;
                    } else {
                        // if not any case above which means it is lesser pop the top
                        // if it is empty push the negative val and go
                        st.pop();

                        if(st.empty()) {
                            st.push(curr);
                            break;
                        }
                    }
                }
            }
        }

        vector<int> ans(st.size(), 0);

        for(int i=st.size()-1; i>=0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
