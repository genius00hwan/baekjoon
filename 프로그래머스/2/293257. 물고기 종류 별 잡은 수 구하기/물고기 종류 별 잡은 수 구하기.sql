select count(*) as fish_count, n.fish_name as fish_name
from fish_info f
join fish_name_info n on f.fish_type = n.fish_type
group by n.fish_name
order by count(*) desc