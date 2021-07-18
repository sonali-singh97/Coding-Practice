
    int inSequence(int A, int B, int C){
        if(C == 0 && A == B)
            return 1;
           
       else if((C == 0 ) || (C < 0 && B > A) || (C > 0 && B < A))
            return 0;
         
         int rem = (B-A)%C ;
         if(rem == 0)
            return 1;
            
          return 0;
    } 