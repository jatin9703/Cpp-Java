package sorting;
import java.util.*;
//o(n^2)
//less swaps than bubble sort
//stable
//used for smaller values of n
//works good when array is partially sorted
class InsertionSort{
    public static void main(String[] args) {
        int[] arr={9,7,6,5,4,3,2,1,0};
        insertionSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    static void insertionSort(int[] arr){
        for(int i=0;i<arr.length-1;i++){
            for(int j=i+1;j>0;j--){
                if(arr[j]<arr[j-1]){
                    swap(arr,j-1,j);
                }
                else{
                    break;
                }
            }
        }

    }

    static void swap(int[] arr,int a ,int b){
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }

}


