# Write your MySQL query statement below

update Salary
set sex = Case
    when sex='m' then 'f'
    when sex='f' then 'm'
end;