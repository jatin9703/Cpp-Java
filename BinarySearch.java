package searching;

import java.util.*;

public class BinarySearch {
public static void main(String args[]){
        Scanner in=new Scanner(System.in);
        int[] arr={1,2,3,4,5,6,7};
        int target=in.nextInt();
        System.out.println(arr[binarySearch(arr,target)]) ;
}
    static int binarySearch(int[] arr,int target){
    int start =0;
    int end=arr.length-1;
    int mid;
    while(start<end){
        mid=start+(end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
return -1;
    }
}
