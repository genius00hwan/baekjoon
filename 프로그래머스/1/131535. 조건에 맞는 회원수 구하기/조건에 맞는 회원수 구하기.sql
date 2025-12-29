select count(*) as USERS
from user_info
where 
    20 <= age and age <= 29 
    and '2021-01-01 00:00:00' <= joined
    and joined < '2022-01-01 00:00:00';