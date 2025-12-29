select p.id, count(c.id) as child_count
# select p.id as parent, c.id as child
from ecoli_data p
left join ecoli_data c on c.parent_id = p.id
group by p.id
order by p.id;