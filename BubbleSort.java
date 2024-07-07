package sorting;

public class BubbleSort {

    public static void main(String[] args) {
        int[] arr={3,4,5,6,1};
        bubbleSort(arr);
        for(int a:arr){
            System.out.print(a+" ");
        }
    }
    static void bubbleSort(int[] arr){
        boolean sorted;
        for(int i=0;i<arr.length;i++){
            sorted=false;
            for(int j=1;j<arr.length-i;j++) {
                if (arr[j] < arr[j - 1]) {
                    swap(arr, j - 1, j);
                }
            }
                sorted=true;


            if(!sorted){

                //System.out.println("already sorted");
                break;
            }
        }
    }
    static void swap(int[]arr,int i, int j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }


}
