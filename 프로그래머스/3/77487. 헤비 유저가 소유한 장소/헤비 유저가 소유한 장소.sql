select p.id, p.name, p.host_id
from places p
join (
    select host_id
    from places 
    group by host_id
    having count(*)>=2
) t on p.host_id=t.host_id


