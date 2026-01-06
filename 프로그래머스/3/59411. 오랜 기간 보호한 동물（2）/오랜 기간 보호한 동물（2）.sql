select o.animal_id, o.name
# , (o.datetime-i.datetime), i.datetime, o.datetime
from animal_outs o
join animal_ins i on o.animal_id = i.animal_id
order by (o.datetime-i.datetime) desc limit 2
