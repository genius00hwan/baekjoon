select count(*) as FISH_COUNT
from fish_info f
join fish_name_info n on n.fish_type = f.fish_type
where fish_name = 'BASS' or fish_name = 'SNAPPER'