import java.util.*;

public class Main{
    public static void main(String[]args){
        int question[][] = new int[1000][1000];
        int count1, count2, len;
        String input_string;
        
        Scanner cin = new Scanner(System.in);
	
        len = 1000;
        
        for(count1 = 0; count1 < len; count1++){
            input_string = cin.nextLine();
            len = input_string.length();
            for(count2 = 0; count2 < len; count2++){
                question[count1][count2] = input_string.charAt(count2) - '0';
            }
        }
        
        int work[][] = new int[len][len];
        int route_x[] = new int[len * 2 - 1];
        int route_y[] = new int[len * 2 - 1];
        int x, y, i;
        
        work[0][0] = question[0][0];
        
        for(x = 1; x < len; x++){
            work[0][x] = work[0][x - 1] + question[0][x];
        }
        
        for(y = 1; y < len; y++){
            work[y][0] = work[y - 1][0] + question[y][0];
        }
        
        for(x = 1; x < len; x++){
            for(y = 1; y < len; y++){
                if(work[y][x - 1] < work[y - 1][x]){
                    work[y][x] = work[y][x - 1] + question[y][x];
                }else{
                    work[y][x] = work[y - 1][x] + question[y][x];
                }
            }
        }
        
        for(i = len * 2 - 2, x = len - 1, y = len - 1; ; i--){
            route_x[i] = x;
            route_y[i] = y;
            if(x == 0 && y == 0){
                break;
            }
            
            if(y == 0){
                x--;
            }else if(x == 0){
                y--;
            }else if(work[y][x - 1] > work[y - 1][x]){
                x--;
            }else{
                y--;
            }
        }
        System.out.println(work[len - 1][len - 1]);
    }
}
