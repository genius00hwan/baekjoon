# select animal_id, replace(name,, NULL) as name, sex_upon_intake
select animal_type, ifnull(name,"No name") as name, sex_upon_intake
from animal_ins
