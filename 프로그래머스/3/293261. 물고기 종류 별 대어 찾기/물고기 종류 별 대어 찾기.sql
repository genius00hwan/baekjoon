select f.id, t.fish_name, t.length
from fish_info f
join (
    select n.fish_type, n.fish_name, sub.length
    from fish_name_info n
    join (
        select fish_type, max(length) as length
        from fish_info
        group by fish_type
    ) sub on sub.fish_type = n.fish_type
) t on t.fish_type = f.fish_type
where f.length = t.length
order by f.id asc

#     select n.fish_type, n.fish_name, sub.length
#     from fish_name_info n
#     join (
#         select fish_type, max(length) as length
#         from fish_info
#         group by fish_type
#     ) sub on sub.fish_type = n.fish_type;








