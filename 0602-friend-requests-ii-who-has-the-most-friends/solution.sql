# Write your MySQL query statement below
WITH cte AS (
    (SELECT accepter_id as id FROM RequestAccepted) UNION ALL (SELECT requester_id  as id FROM RequestAccepted)
)

SELECT id, COUNT(id) as num FROM cte GROUP BY id ORDER BY num desc LIMIT 1;
