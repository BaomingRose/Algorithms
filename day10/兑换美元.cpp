/*��Ŀ����
����һ�μ�����Ԫ��������Ԫ��������������Ķ�������Ȼ��������ÿһ����Ԫ������
Ȼ��ÿһ��������ȥ��ȡ���Լ�����ٵ���Ԫ������ ����ȼ۽�����
�ٸ����ӣ���������5��Ԫ������������޶�Ϊ3��Ԫ�������Ի��� 
1.  1��3��Ԫ �� 1��2��Ԫ
2.  1��3��Ԫ �� 2��1��Ԫ
3.  1��2��Ԫ �� 3��1��Ԫ
4.  2��2��Ԫ �� 1��1��Ԫ
5.  5��1��Ԫ
����дһ�����򣬼���������N��Ԫ����ȡ����ΪK��Ԫ������
1 <= n <= 1000 
1 <= k <= 100
����
ֻ��һ������
ÿһ�а����������� n �� k 
���
ÿһ�а���һ����������������ܻ�ȡ��������
��������
5 3
�������
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
