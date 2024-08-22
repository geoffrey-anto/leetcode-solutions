# Write your MySQL query statement below

(SELECT 
    name as results 
FROM 
    MovieRating as m 
JOIN 
    Users as u 
ON 
    u.user_id = m.user_id 
GROUP BY 
    m.user_id 
ORDER BY 
    COUNT(*) desc, 
    name asc 
LIMIT 1)

UNION ALL

(SELECT 
    title as results 
FROM 
    MovieRating as m 
JOIN 
    Movies as mo 
ON 
    m.movie_id=mo.movie_id 
WHERE 
    m.created_at LIKE '2020-02-%%' 
GROUP BY 
    m.movie_id 
ORDER BY 
    AVG(m.rating) desc, 
    mo.title asc 
LIMIT 1);
