select distinct d.id, d.email, d.first_name, d.last_name
from developers d
inner join skillcodes s on s.code & d.skill_code
where s.name = "C#" or s.name = "Python"
order by d.id