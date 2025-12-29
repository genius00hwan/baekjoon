# select c.id, c.genotype, p.id, p.genotype, c.genotype & p.
select c.id, c.genotype, p.genotype as parent_genotype
from ecoli_data c
inner join ecoli_data p on c.parent_id = p.id
where (c.genotype & p.genotype) = p.genotype
order by c.id