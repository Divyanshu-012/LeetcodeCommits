# Write your MySQL query statement below
Select f.customer_id , count(f.visit_id) as count_no_trans from Visits as f left join Transactions as s ON f.visit_id = s.visit_id
WHERE s.visit_id IS NULL
GROUP BY f.customer_id;