/*题目描述
红红第一次见到美元，觉得美元是世界上最神奇的东西，，然后他发现每一个美元都有面额，
然后每一个面额都可以去换取比自己面额少的美元，但是 必须等价交换。
举个例子，如果红红有5美元，且限制最大限额为3美元，他可以换成 
1.  1个3美元 和 1个2美元
2.  1个3美元 和 2个1美元
3.  1个2美元 和 3个1美元
4.  2个2美元 和 1个1美元
5.  5个1美元
现在写一个程序，计算红红能用N美元，换取限制为K美元的种数
1 <= n <= 1000 
1 <= k <= 100
输入
只有一组输入
每一行包含两个整数 n 和 k 
输出
每一行包含一个整数，包括最后能换取的种数。
样例输入
5 3
样例输出
5
*/

/*java
import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    
    public static void main(String[] args) {
        
        int n,k;
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            BigInteger[] dp = new BigInteger[1005];
            n = in.nextInt();
            k = in.nextInt();
            dp[0] = new BigInteger("1");
            for (int i = 1; i <= n; i++) {
                dp[i] = new BigInteger("0");
            }
            for (int i = 1; i <= k; i++) {
                for (int j = i; j <= n; j++) {
                    dp[j] = dp[j].add(dp[j - i]);
                }
            }
           System.out.println(dp[n]); 
        }
    }
}
*/
