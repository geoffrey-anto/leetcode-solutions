-- # Write your MySQL query statement below


-- -- SELECT 
-- --     s.student_id, s.student_name, e.subject_name, COUNT(*) AS attended_exams
-- -- FROM 
-- --     Students AS s 
-- -- LEFT JOIN 
-- --     Examinations AS e 
-- -- ON 
-- --     s.student_id=e.student_id
-- -- GROUP BY 
-- --     s.student_id, e.subject_name;

-- SELECT 
--     s.student_id, s.student_name, e.subject_name, COUNT(*) AS attended_exams
-- FROM 
--     Students AS s
-- WHERE
--     s.student_id in (
--         SELECT
--     )
-- -- Students AS s
-- -- Subjects AS sub
-- -- Examinations AS e

With CTE1 AS
(select student_id, student_name, subject_name from Students cross join subjects order by student_id),

CTE2 AS
(select student_id, subject_name, count(subject_name) AS attended_exams from Examinations group by student_id, subject_name)

select CTE1.student_id, CTE1.student_name, CTE1.subject_name, IFNULL(CTE2.attended_exams,0) AS attended_exams from CTE1 left join CTE2 on CTE1.student_id = CTE2.student_id and CTE1.subject_name = CTE2.subject_name

order by student_id asc, subject_name asc
