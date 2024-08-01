# Write your MySQL query statement below
SELECT MAX(num) as num FROM (SELECT num FROM MyNumbers GROUP BY num having COUNT(*)=1) AS temp;
