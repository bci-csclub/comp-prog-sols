import java.io.IOException;
import java.io.InputStream;

public class Main {
    static final int INF = 1 << 30;
    int dist, numClubs;
    int[] clubs;
    int[] strokesToPos;

    Main() throws IOException {
        FastReader fastReader = new FastReader();
        dist = fastReader.nextInt();

        numClubs = fastReader.nextInt();
        clubs = new int[numClubs];
        for (int i = 0; i < numClubs; i++) clubs[i] = fastReader.nextInt();

        strokesToPos = new int[dist+1];
        for (int pos = 1; pos <= dist; pos++) {
            int minStrokes = INF;
            for(int club : clubs){
                if(club <= pos){
                    minStrokes = Math.min(minStrokes, strokesToPos[pos-club] + 1);
                }
            }
            strokesToPos[pos] = minStrokes;
        }

        if(strokesToPos[dist] == INF) System.out.println("Roberta acknowledges defeat.");
        else System.out.println("Roberta wins in " + strokesToPos[dist] + " strokes.");
    }

    static class FastReader {
        final InputStream in = System.in;
        final int bufSize = 1 << 16;
        byte[] buf = new byte[bufSize];
        int pos = 0;
        int byteCount = bufSize;

        boolean isNeg;
        byte ch;

        int nextInt() throws IOException {
            while(ch < '-') ch = readByte();
            if(isNeg = (ch == '-')) ch = readByte();
            int res = ch-'0';
            while((ch = readByte()) >= '0' && ch <= '9') res = res*10 + ch-'0';
            return isNeg ? -res : res;
        }

        long nextLong() throws IOException {
            while(ch < '-') ch = readByte();
            if(isNeg = (ch == '-')) ch = readByte();
            long res = ch-'0';
            while((ch = readByte()) >= '0' && ch <= '9') res = res*10 + ch-'0';
            return isNeg ? -res : res;
        }

        double nextDouble() throws IOException {
            long whole = nextLong();
            if(ch != '.') return whole;
            long div = 10;
            long decimal = readByte()-'0';
            for(; (ch = readByte()) >= '0' && ch <= '9'; div *= 10) decimal = decimal*10 + ch-'0';
            return isNeg ? (whole - (double) decimal / div) : (whole + (double) decimal / div);
        }

        byte[] nextString(int maxLength) throws IOException {
            byte[] strArr = new byte[maxLength + 1];
            for (int i = 0; i < maxLength; i++) {
                strArr[i] = readByte();
                if(strArr[i] <= ' '){
                    byte[] res = new byte[i];
                    System.arraycopy(strArr, 0, res, 0, i);
                    return res;
                }
            }

            throw new AssertionError();
        }

        FastReader() throws IOException {
            fill();
        }

        void fill() throws IOException {
            byteCount = in.read(buf, 0, bufSize);
        }

        byte readByte() throws IOException {
            if (pos == byteCount) {
                fill();
                pos = 0;
            }
            return buf[pos++];
        }
    }

    public static void main(String[] args) throws IOException {
        new Main();
    }
}
