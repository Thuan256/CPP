#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,kq = 0,sll,a = 0, c= 0, t;
const ll nmax = 3e6+5;
bool b[nmax+5];
void sg()
{
    memset(b,true,sizeof(b));
    b[0] = b[1] = false;
    for(int i = 2; i <= sqrt(nmax); i++)
    if(b[i])
    for(int j = i * i; j <= nmax; j+=i)
    b[j] = false;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("BIEUTHUCNT.inp", "r", stdin);
    freopen("BIEUTHUCNT.out", "w", stdout);
    sg();
    cin >> n;
    sll = (n + 1)/2;
    for(int i = 3; i <= 3*n; i++)
    {
        if(b[i])
        {
            a = (i-1)/2;
            a = min(a,sll);
            if(i <= 2*n)
                kq += a;
            else
            {
                ll l = 1, h = a, m = 0;
                t = a;
                while(l <= h)
                {
                    m = (l + h)>>1;
                    if((i - m*2 + 1)/2 <= n)
                    {
                        h = m - 1;
                        t = m;
                    }
                    else l = m + 1;
                }
                kq += (a - t + 1);
            }
        }
    }
    cout << kq;
}
//Solution đề tỉnh
//Bài 1: BIEUTHUCNT
//Duyệt tất cả số nguyên tố <= 3*n;
//Gọi số lượng số lẻ < n là a;
//Gọi p là số nguyên tố
//Với p  <= 2* n:
//-	Gọi b = số lượng số lẻ < p;
//-	kq += min(b,a);
//Với p > 2*n;
//-	Gọi b = min(số lượng số lẻ < p,a);
//-	Gọi x = số thứ tự của số lẻ bé nhất mà (p – 2*x + 1)/2 <= n;
//-	kq += b – x + 1;
//Bài 2: TANGQUA
//Gọi đáp án cho mỗi I từ 1 -> n là x;
//Ban đầu x = 1;
//Thiết lập 1 mảng đánh dâu b[];
//Với mỗi giá trị ai nhập vào -> b[ai] = 1;
//Kiểm tra b[x] có = 0 ko;
//-	Có -> x là kq;
//-	Ko -> tìm x tiếp theo chx đc chọn : while(b[x]) x++; cout << x;
//Bài 3: DODANK
//Phương pháp : dp + prefix sum;
//Ý tưởng:
//-. Ta sẽ làm 2 mảng dp1 vs dp2 vs ý nghĩa:
//+ dp1[i] : số cách chọn dãy với ai là phần tử cuối của dãy.
//+ dp2[i] : tổng trọng số của dãy với việc chọn ai là phần tử cuối của dãy.
//-. Ta tiếp tục tạo 2 mảng prefix sum sum1 và sum2
//+ sum1[i] : tổng số cách tạo dãy từ 1 -> i.
//+ sum2[i] : tổng trọng số từ 1 -> i.
//Kết quả : sum2[n];
//Công thức dp:
//-. Với i >= k
//+ dp1[i] = sum1[i-k] + 1;
//+ dp2[i] = sum2[i-k] + dp1[i] * a[i];
//-, Với i < k;
//+ dp1[i] = 1;
//+ dp2[i] = a[i];
//-, sum1[i] = sum1[i-1] + dp1[i];
//-, sum2[i] = sum2[i-1] + dp2[i];
