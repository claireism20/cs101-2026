#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int n;
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩 : ");
    scanf("%d", &n);

    // 限制 n 在 1 ~ 5 之間
    if (n < 1 || n > 5) {
        return 1;
    }

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        return 1;
    }

    // 取得當前時間並移除 ctime() 自帶的換行符號
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strcspn(time_str, "\n")] = '\0';

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s =\n", time_str);

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 5; i++) {
        fprintf(fp, "[%d]: ", i + 1);
        if (i < n) {
            int nums[7];
            int used[70] = {0}; // 標記 1~69 是否已抽出

            // 抽出 7 個不重複數字 (01 ~ 69)
            for (int j = 0; j < 7; j++) {
                int r;
                do {
                    r = rand() % 69 + 1;
                } while (used[r]);
                used[r] = 1;
                nums[j] = r;
            }

            // 前 6 個號碼由小到大排序 (符合投影片範例格式)
            for (int j = 0; j < 5; j++) {
                for (int k = j + 1; k < 6; k++) {
                    if (nums[j] > nums[k]) {
                        int temp = nums[j];
                        nums[j] = nums[k];
                        nums[k] = temp;
                    }
                }
            }

            // 輸出 7 個號碼，不足兩位數補 0
            for (int j = 0; j < 7; j++) {
                fprintf(fp, "%02d%s", nums[j], (j == 6) ? "" : " ");
            }
            fprintf(fp, "\n");
        } else {
            fprintf(fp, "-- -- -- -- -- -- --\n");
        }
    }

    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}
