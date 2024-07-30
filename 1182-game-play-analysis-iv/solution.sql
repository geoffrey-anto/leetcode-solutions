-- -- # Write your MySQL query statement below
-- -- SELECT round(count(distinct(a.player_id))/count(a2.player_id), 2) as fraction FROM Activity as a, (SELECT distinct a2.player_id FROM Activity as a2) as a2 WHERE (SELECT count(a1.event_date) FROM Activity as a1 WHERE a1.player_id = a.player_id AND DATE_ADD(a.event_date, INTERVAL 1 DAY) = a1.event_date) > 0;


-- select
-- round(sum(datediff(t2.event_date, t1.event_date) = 1) / count(distinct t2.player_id),2) as fraction
-- from
-- Activity t1 join Activity t2
-- on
-- t1.player_id = t2.player_id;

SELECT
  ROUND(COUNT(DISTINCT player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM
  Activity
WHERE
  (player_id, DATE_SUB(event_date, INTERVAL 1 DAY))
  IN (
    SELECT player_id, MIN(event_date) AS first_login FROM Activity GROUP BY player_id
  )
