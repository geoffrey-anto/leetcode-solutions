# Write your MySQL query statement below
-- SELECT @times = (SELECT COUNT(*) as count FROM Users)

-- SELECT COUNT(user_id)/@times FROM Register GROUP BY contest_id;
-- SELECT @times := COUNT(*) 
-- FROM Users;

-- SELECT contest_id, COUNT(user_id) / @times as ratio 
-- FROM Register
-- GROUP BY contest_id;

SELECT contest_id, ROUND(COUNT(user_id) / total_users*100, 2) AS percentage
FROM Register, (SELECT COUNT(*) AS total_users FROM Users) AS total
GROUP BY contest_id ORDER BY percentage DESC, contest_id ASC;

