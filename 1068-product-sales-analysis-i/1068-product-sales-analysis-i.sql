# Write your MySQL query statement below
select o.product_name, e.year, e.price from Sales as e left join Product as o on e.product_id = o.product_id;