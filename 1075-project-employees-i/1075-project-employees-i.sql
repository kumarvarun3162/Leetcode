# Write your MySQL query statement below
select p.project_ID,
    round(avg(experience_years), 2) as average_years 
    from project p 
    JOIN Employee e
    ON p.employee_id = e.employee_id
GROUP BY p.project_id;