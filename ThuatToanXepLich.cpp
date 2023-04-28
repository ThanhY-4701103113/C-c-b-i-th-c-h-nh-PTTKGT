#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job {
    int start, end, profit;
};

bool cmp(Job a, Job b) {
    return a.end < b.end;
}

int jobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), cmp);

    int n = jobs.size();
    int dp[n];
    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; i++) {
        int currProfit = jobs[i].profit;
        int latestJobIdx = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (jobs[j].end <= jobs[i].start) {
                latestJobIdx = j;
                break;
            }
        }
        if (latestJobIdx != -1) {
            currProfit += dp[latestJobIdx];
        }
        dp[i] = max(currProfit, dp[i - 1]);
    }

    return dp[n - 1];
}

int main() {
    vector<Job> jobs = {{1, 3, 5}, {2, 5, 6}, {4, 6, 5}, {6, 7, 4}, {5, 8, 11}, {7, 9, 2}};
    int maxProfit = jobScheduling(jobs);
    cout << "Max profit: " << maxProfit << endl;

    return 0;
}
/* 
Trong cài đặt này, chúng ta sử dụng vector để lưu trữ danh sách các công việc, mỗi công việc 
được biểu diễn bằng một struct gồm ba trường id, deadline và profit lần lượt là mã công việc, thời hạn và lợi nhuận. 
Ta định nghĩa một hàm so sánh cmp để sắp xếp danh sách công việc theo lợi nhuận giảm dần. Trong hàm jobSequencing, 
ta sắp xếp danh sách công việc theo lợi nhuận giảm dần, khởi tạo một mảng slot để lưu trữ công việc được lựa chọn 
tại mỗi thời điểm (ban đầu, tất cả các slot đều là trống). Để chọn ra các công việc thích hợp, ta duyệt qua từng 
công việc trong danh sách công việc đã được sắp xếp. Với mỗi công việc, ta duyệt ngược lại từ thời hạn của công việc
 đến thời điểm 0 để tìm một slot trống và gán công việc này vào slot đó (nếu tìm được slot phù hợp, ta dừng việc duyệt ngược lại).
Cuối cùng, ta tính tổng lợi nhuận của các công việc đã được chọn và trả về giá trị này.
*/