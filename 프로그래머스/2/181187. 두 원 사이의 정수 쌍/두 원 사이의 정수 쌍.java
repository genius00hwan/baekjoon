class Solution {
     public long solution(int r1, int r2) {
         long sum = 0;
         for(int i=0;i<r2;i++){       
            if(i<r1){
                  sum+= Math.floor(Math.sqrt(Math.pow(r2,2)-Math.pow(i,2))) - Math.ceil(Math.sqrt(Math.pow(r1,2)-Math.pow(i,2)))+1;
            }
            else{
                sum+= Math.floor(Math.sqrt(Math.pow(r2,2)-Math.pow(i,2)));
            }
        }
        return sum*4;
    }
}