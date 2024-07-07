package sorting;

import java.util.*;
//not stable
//prefer for small arrays/lists
//o(n^2)
class SelectionSort{
    public static void main(String[] args) {
        int[] arr={9,8,7,6,5,4,3,2,1,0};
        selectionSort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void selectionSort(int[] arr){
        int max;
        int last=arr.length-1;
        for(int i=0;i<arr.length;i++){
            max=giveMaxIndex(arr,0,last-i);
            swap(arr,max,last-i);
        }
    }
    static int giveMaxIndex(int[] arr,int start,int end){
        int max=0;
        for(int i=1;i<=end;i++){
            if(arr[i]>arr[max]){
                max=i;
            }
        }
        return max ;
    }
    static void swap(int[] arr,int a ,int b){
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
}
