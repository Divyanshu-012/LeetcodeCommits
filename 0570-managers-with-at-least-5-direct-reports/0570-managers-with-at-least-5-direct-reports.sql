# Write your MySQL query statement below
select  e.name  from Employee e join Employee m on e.id = m.managerId GROUP BY e.id
HAVING COUNT(m.id) >= 5;



