# Write your MySQL query statement below
with cte as (
    select visited_on,
    sum(amount) as daily_amount
    from Customer
    group by visited_on
)

select visited_on,
    sum(daily_amount) over(ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) as amount,
    round(avg(daily_amount) over(ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW),2) as average_amount
from cte 
limit 1000 offset 6
