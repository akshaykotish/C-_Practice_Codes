// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.Arrays;

class HelloWorld {
    
    static int BinarySearch(int[] arr, int search){
        //System.out.println(Arrays.toString(arr));
        if(arr.length == 0)
        {
            return -1;
        }
        int half = arr.length/2;
        //System.out.println("Half " + half);
        int mid = arr[half];
        if(mid == search)
        {
            System.out.println("Found " + mid);
            return arr.length/2;
        }
        
        int v = -1;
        if(arr.length >= 1){
            if(search < mid)
            {
                v = BinarySearch(Arrays.copyOfRange(arr, 0, half), search);
            }
            else{
                v =  BinarySearch(Arrays.copyOfRange(arr, half+1, arr.length), search);
            }
        }
        return v;
    }
    
    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        if(BinarySearch(arr, 1) == -1)
        {
            System.out.println("Not Found");
        }
    }
}
