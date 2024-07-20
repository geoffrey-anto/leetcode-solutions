# Write your MySQL query statement below
SELECT w.id 
FROM Weather as w 
WHERE w.temperature > (
    SELECT temperature 
    FROM Weather AS p
    WHERE DATEDIFF(p.recordDate,w.recordDate)=-1
);

-- -- FROM Weather
-- -- ) AS temp_table

-- -- WHERE today_temp>yesterday_temp AND DATEDIFF(recordDate,yes_date)=1

-- SELECT y.id
-- FROM Weather x
-- LEFT JOIN Weather y ON x.Id +1 = y.Id
-- WHERE x.Temperature < y.Temperature
