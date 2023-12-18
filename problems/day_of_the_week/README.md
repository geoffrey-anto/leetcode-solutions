# Day Of The Week

## Leetcode Link: [Day Of The Week](https://leetcode.com/problems/day-of-the-week/)
### Language: JavaScript

```js
/**
 * @param {number} day
 * @param {number} month
 * @param {number} year
 * @return {string}
 */
var dayOfTheWeek = function(day, month, year) {
    const days = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    return(days[(new Date(`${year}-${month}-${day}`)).getDay()]);
};```



