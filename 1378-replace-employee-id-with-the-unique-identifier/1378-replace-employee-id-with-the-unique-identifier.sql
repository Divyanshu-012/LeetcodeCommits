# Write your MySQL query statement below
select o.unique_id , e.name from Employees as e left join  EmployeeUNI as o on o.id = e.id ; 