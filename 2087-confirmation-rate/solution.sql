# Write your MySQL query statement below
SELECT s.user_id, ROUND(IFNULL(SUM(c.action='confirmed')/COUNT(*), 0), 2) as confirmation_rate FROM Signups AS s LEFT JOIN Confirmations AS c ON s.user_id = c.user_id GROUP BY s.user_id;

-- SELECT c.user_id, SUM(c.action='confirmed')/COUNT(*) as confirmation_rate FROM Confirmations AS c GROUP BY c.user_id;

-- SELECT 
