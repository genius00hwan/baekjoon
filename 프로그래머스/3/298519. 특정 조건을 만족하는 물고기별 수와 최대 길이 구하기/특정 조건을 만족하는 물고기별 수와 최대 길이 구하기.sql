select count(*) as FISH_COUNT, max(length) as MAX_LENGTH, fish_type as FISH_TYPE
from fish_info 
group by fish_type
having avg(
    case 
        when length <= 10 then 10
        when length is null then 10
        else length
    end
)>=33
order by fish_type asc
