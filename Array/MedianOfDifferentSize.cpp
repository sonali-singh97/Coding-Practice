 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        if(len1 > len2) return findMedianSortedArrays(nums2 , nums1);
        
        int start = 0;
        int end = len1 ;
        
        int mid = (len1 + len2 + 1)/ 2;
        
        while (start <= end){
            int cut1 = (start + end)/2;
            int cut2 = mid - cut1;
            
            int firstLeft, secondLeft, firstRight, secondRight;
            
            firstLeft = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
            secondLeft = (cut2 == 0) ? INT_MIN : nums2[cut2-1];
            
            firstRight = (cut1 == len1) ? INT_MAX : nums1[cut1];
            secondRight = (cut2 == len2) ? INT_MAX : nums2[cut2];
            
            if(firstLeft > secondRight){
                end = cut1-1;
            }
            
            else if (secondLeft > firstRight){
                start = cut1+1;
            }
            
            else{
                if((len1+ len2)%2 == 0){
                    return (max(firstLeft, secondLeft) + min(firstRight, secondRight))/2.0;
                }
                
                else return max(firstLeft, secondLeft);
            }
            
        }
        
        return 0.0 ;
    }