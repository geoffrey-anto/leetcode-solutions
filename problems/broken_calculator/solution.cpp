class Solution {
public:
       
    int brokenCalc(int startValue, int target) {
        int a=0;
        while(startValue<target){
            a++;
            if(target%2==1){
                target++;
            } else {
                target/=2;
            }
        }
        
        return a+startValue-target;
    }
};