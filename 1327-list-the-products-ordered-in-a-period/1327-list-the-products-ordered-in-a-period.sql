# Write your MySQL query statement below
select p.product_name, sum(O.unit) as unit from Products p join Orders O on p.product_id = O.product_id where O.order_date Like'2020-02%' group by O.product_id
having (unit>=100);
