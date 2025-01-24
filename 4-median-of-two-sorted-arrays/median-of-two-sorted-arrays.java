class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        double median;
        int[] sum = new int[m+n];
        for(int i=0;i<m;i++)
        {
            sum[i]=nums1[i];
        }
        for(int i=0;i<n;i++)
        {
            sum[m+i]=nums2[i];
        }
        Arrays.sort(sum);
        if(sum.length % 2 != 0)
        {
            median = sum[(sum.length -1)/2];
        }
        else
        {
            median = (sum[(sum.length / 2) - 1] + sum[sum.length / 2]) / 2.0;
        }
        return median;
    }
}