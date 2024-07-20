# Write your MySQL query statement below
-- SELECT distinct(v.customer_id), COUNT(t.amount) FROM Visits as v INNER JOIN Transactions AS t ON t.visit_id != v.visit_id;

SELECT customer_id, COUNT(*) AS count_no_trans
FROM Visits
WHERE visit_id NOT IN (SELECT visit_id FROM Transactions)
GROUP BY customer_id;
