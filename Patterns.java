package patterns;
public class Patterns {


    /*
     *
     * *
     * * *
     * * * *
     * * * * *
     * * * *
     * * *
     * *
     *
     */
    public static void main(String[] args) {
        int n=5;
        for(int row=0;row<2*n;row++ ){
            int col= row>n-1?(2*n-row-1):row+1;
            for(int j=0;j<col;j++){
                System.out.print("* ");
            }
            System.out.println("");
        }
    }

    /*
         *
        * *
       * * *
      * * * *
     * * * * *
      * * * *
       * * *
        * *
         *
     */

//    public static void main(String[] args) {
//        int n=5;
//
//        for(int row=0;row<2*n;row++){
//            int col=row>n-1?(2*n-row-1):row+1;
//            int spaces=n-col;
//            for(int i=0;i<spaces;i++){
//                System.out.print(" ");
//            }
//            for(int j=0;j<col;j++){
//                System.out.print("* ");
//            }
//            System.out.println("");
//        }
//
//
//    }

//            4 4 4 4 4 4 4
//            4 3 3 3 3 3 4
//            4 3 2 2 2 3 4
//            4 3 2 1 2 3 4
//            4 3 2 2 2 3 4
//            4 3 3 3 3 3 4
//            4 4 4 4 4 4 4
//
//    public static void main(String[] args) {
//        int n=4;
//        int degree=2*n-1;
//        for(int row=0;row<degree;row++){
//            for(int col=0;col<degree;col++){
//                int value=n-(Math.min(Math.min(row,col),Math.min(degree-row-1,degree-col-1)));
//                System.out.print(value+" ");
//            }
//            System.out.println("");
//        }
//
//    }

}
