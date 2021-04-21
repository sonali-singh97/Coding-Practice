FindDuplicateElement.cpp


//find duplicate in an array of N+1 Integers


//Cycle detection algorithm
//Complexity O(n)
//will work only when numbers are from 1 to n (i.e not include zero)
//Repeating element will always have an outgoing edge to cycle intersection point bcoz they point to same index

    int findDuplicate(vector<int>& nums) {


	if(nums.empty())
		return 0;

	int slow = nums[0];
	int fast = nums[0];

    do{
		slow = nums[slow];
		fast = nums[nums[fast]];
	}	while(slow!= fast);

	slow=nums[0];

	while(slow!=fast){
		slow=nums[slow];
		fast = nums[fast];
	}

	return slow;

    }


    //Indexing Method
    //1. Run a loop over array
    //2. For every element, take mod and modify the number present at that index(make it negative)
    //3 . If a number is already modified, it means that the index pointing to that number is repetitive.

    //Sum method
    //find sum from 1 to n and sum of array , difference is the ans.
