select user_id, product_id 
from ONLINE_SALE 
group by user_id, product_id
HAVING COUNT(*) >= 2
ORDER BY USER_ID ASC, PRODUCT_ID DESC;