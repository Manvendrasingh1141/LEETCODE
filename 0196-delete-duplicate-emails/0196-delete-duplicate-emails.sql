# Write your MySQL query statement below
# can't select the values from the updated values of same table , need a derived table 
# here wew have temp(containing only id's after 1st min id) aas a derived table

Delete from Person where 
id not in (select id from(
    select min(id) as id from Person group by email
) as temp);