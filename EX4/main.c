#include <stdio.h>
#include <stdlib.h>

int main() {
FILE *fp;

// 原始的 3 個陣列
int a[] = {0, 1, 2};
char b[] = {'A', 'B', 'C'};
float c[] = {1.1f, 1.2f, 1.3f};

// 1. 以二進位寫入模式 ("wb") 開啟檔案 a.bin
fp = fopen("a.bin", "wb");
if (fp == NULL) {
printf("檔案開啟失敗！\n");
return 1;
}

// 將 3 個陣列透過二進位形式寫入檔案
fwrite(a, sizeof(int), 3, fp);
fwrite(b, sizeof(char), 3, fp);
fwrite(c, sizeof(float), 3, fp);

// 關閉檔案
fclose(fp);

// 用來接收讀取資料的陣列
int ra[3];
char rb[3];
float rc[3];

// 2. 以二進位讀取模式 ("rb") 開啟檔案 a.bin
fp = fopen("a.bin", "rb");
if (fp == NULL) {
printf("檔案開啟失敗！\n");
return 1;
}

// 從檔案中讀取資料到陣列中
fread(ra, sizeof(int), 3, fp);
fread(rb, sizeof(char), 3, fp);
fread(rc, sizeof(float), 3, fp);

// 關閉檔案
fclose(fp);

// 3. 輸出 3 個陣列的內容
for (int i = 0; i < 3; i++) {
printf("%d ", ra[i]);
}
printf("\n");

for (int i = 0; i < 3; i++) {
printf("%c ", rb[i]);
}
printf("\n");

for (int i = 0; i < 3; i++) {
printf("%f ", rc[i]);
}
printf("\n");

return 0;
}
