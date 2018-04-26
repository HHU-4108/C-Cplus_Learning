/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

示例 1:

nums1 = [1, 3]
nums2 = [2]

中位数是 2.0

示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5


*/

class Solution {
public:
    int *getMedian(int startPoint,int endPoint,vector<int> num)
{
    
    int length=endPoint-startPoint+1;
    int flag=length%2; //0 is even. 1 is odd
    int median=0;
    int position=startPoint;
    int *result = (int*)malloc(sizeof(int)*3);
    //int result[2];
    if(flag==1)
    {
        position=startPoint+length/2;
        median=num[position];
    }
    else
    {
        position=startPoint+length/2-1;
        median=num[position]+num[position+1];
    }
    result[0]=flag;
    result[1]=median;
    result[2]=position;
    return result;
}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        
        if(nums1.empty())
        {
            if(nums2.size()%2==1)
            {
                return nums2[nums2.size()/2];

            }
            else
            {
                return (nums2[nums2.size()/2-1]+nums2[nums2.size()/2])/2.0;
            }
            
        }
        if(nums2.empty())
        {
            if(nums1.size()%2==1)
            {
                return nums1[nums1.size()/2];

            }
            else
            {
                return (nums1[nums1.size()/2-1]+nums1[nums1.size()/2])/2.0;
            }
            
        }
        vector<int> shortNum;
    vector<int> longNum;
    int i=0;
    int currLength1=nums1.size();
    int currLength2=nums2.size();
    int startPointShort=0;
    int endPointShort=0;
    int startPointLong=0;
    int endPointLong=0;
    float medianShort=0.0;
    float medianLong=0.0;

    if(currLength1>currLength2)
    {
        endPointShort=currLength2-1;
        endPointLong=currLength1-1;
        for(;i<currLength2;i++)
        {
            shortNum.push_back(nums2[i]);
            longNum.push_back(nums1[i]);
        }
        for(;i<currLength1;i++)
        {
            longNum.push_back(nums1[i]);
        }
    }
    else
    {
        endPointShort=currLength1-1;
        endPointLong=currLength2-1;
        for(;i<currLength1;i++)
        {
            shortNum.push_back(nums1[i]);
            longNum.push_back(nums2[i]);
        }
        for(;i<currLength2;i++)
        {
            longNum.push_back(nums2[i]);
        }
    }
    while(1)
    {
        currLength1=endPointShort-startPointShort+1;
        currLength2=endPointLong-startPointLong+1;


        i=0;

        if(currLength1<=2)
        {
            i=startPointShort;
            int j=startPointLong;
            vector<int> temp;
            int tempLength=currLength1+currLength2;
            while(j<=endPointLong)
            {
                if(i<=endPointShort&&shortNum[i]<longNum[j])
                {
                    temp.push_back(shortNum[i++]);
                    //if(i==currLength1) break;

                }
                else
                {
                    temp.push_back(longNum[j++]);
                }

            }
            if(temp.size()==(currLength1+currLength2-2))
            {
                temp.push_back(shortNum[i++]);
                temp.push_back(shortNum[i]);
            }
            if(temp.size()==(currLength1+currLength2-1))
            {
                temp.push_back(shortNum[i++]);
            }
            if(temp.size()%2==1)
            {
                return temp[temp.size()/2];

            }
            else
            {
                return (temp[temp.size()/2-1]+temp[temp.size()/2])/2.0;
            }
        }


        int *resShort=getMedian(startPointShort,endPointShort,shortNum);
        medianShort=resShort[1];
        if(resShort[0]==0) medianShort=medianShort/2.0;
        int *resLong=getMedian(startPointLong,endPointLong,longNum);
        medianLong=resLong[1];
        if(resLong[0]==0) medianLong=medianLong/2.0;

        if(fabs(medianShort-medianLong)<0.00001)
        {
            //cout<<"equal"<<endl;
            return medianShort;
        }
        int cutLength=0;
        if(medianShort<medianLong)
        {

            if(resShort[0]==0)
            {
                cutLength=(endPointShort-startPointShort+1)/2-1;
            }
            else
            {
                cutLength=(endPointShort-startPointShort+1)/2;
            }
            //cout<<"cutLength:"<<cutLength<<endl;
            startPointShort=startPointShort+cutLength;
            endPointLong=endPointLong-cutLength;
            //cout<<"win for long:"<<startPointShort<<","<<shortNum[startPointShort]<<endl;

        }
        else
        {
            if(resShort[0]==0)
            {
                cutLength=(endPointShort-startPointShort+1)/2-1;
            }
            else
            {
                cutLength=(endPointShort-startPointShort+1)/2;
            }
            startPointLong=startPointLong+cutLength;
            endPointShort=endPointShort-cutLength;
        }

        delete(resShort);
        delete(resLong);
    }
    return 1;
       
        
    }
};