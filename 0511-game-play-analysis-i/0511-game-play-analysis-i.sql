# Write your MySQL query statement below


/*
    First ques of compound primary id
*/

select player_id , min(event_date) as first_login 
from Activity 
group by player_id;
