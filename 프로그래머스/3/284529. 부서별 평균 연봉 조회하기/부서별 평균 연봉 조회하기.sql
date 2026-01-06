select e.dept_id as DEPT_ID, d.dept_name_en as DEPT_NAME_EN, round(avg(e.sal),0) as AVG_SAL
from hr_employees e
join hr_department d on d.dept_id = e.dept_id
group by e.dept_id
order by avg(e.sal) desc
