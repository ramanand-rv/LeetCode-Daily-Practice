function missingInteger(nums: number[]): number {
    let seqSum = nums[0];

    for(let i=1;i<nums.length;i++){
        if(nums[i] === nums[i -1] +1)
            seqSum += nums[i];
        else
            break;
    }

    const present = new Array(1276).fill(false);

    for(const num of nums) present[num] = true;

    while(present[seqSum])
        seqSum++;

    return seqSum;

};