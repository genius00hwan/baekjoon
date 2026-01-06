select i.animal_id as ANIMAL_ID, i.name as NAME
    # ,i.datetime as IN_DATETIME, o.datetime as OUT_DATETIME
from animal_ins i
join animal_outs o 
    on i.animal_id = o.animal_id
where i.datetime > o.datetime
order by i.datetime