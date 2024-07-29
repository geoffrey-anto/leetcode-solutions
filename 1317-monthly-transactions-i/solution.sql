# Write your MySQL query statement below
SELECT 
    DATE_FORMAT(t.trans_date, '%Y-%m') AS month, 
    t.country,
    COUNT(id) AS trans_count, 
    SUM(IF(state='approved', 1, 0)) AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(IF(state='approved', amount, 0)) AS approved_total_amount
FROM 
    Transactions as t 
GROUP BY DATE_FORMAT(t.trans_date, '%Y-%m'), t.country;
