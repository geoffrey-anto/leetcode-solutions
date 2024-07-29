# Write your MySQL query statement below
-- SELECT SUM(IF(MIN(order_date)=MIN(customer_pref_delivery_date), 1, 0))/total AS immediate_percentage FROM Delivery, (SELECT COUNT(*) AS total FROM Delivery) AS total
-- GROUP BY customer_id;

select round(sum(minOrder = cust)*100/count(*),2) as immediate_percentage
from (
    select customer_id, min(order_date) as minOrder, min(customer_pref_delivery_date) as cust
    from delivery
    group by customer_id) as minOrderTable
