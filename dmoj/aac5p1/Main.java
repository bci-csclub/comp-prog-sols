import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public Main() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int numEven = 0;
        int numOdd = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            int a = Integer.parseInt(st.nextToken());
            if(a % 2 == 1) numOdd++;
            else numEven++;
        }

        System.out.println(numEven/2 + numOdd/2);
    }

    public static void main(String[] args) throws IOException {
        new Main();
    }
}
