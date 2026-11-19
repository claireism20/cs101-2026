#include <stdio.h>
#include <string.h>

typedef struct Books {
    int id;
    int price;
    char title[100];
} book_t;

void total_price(book_t books[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += books[i].price;
    }
    printf("Total Price: %d\n", sum);
}

void list_books(book_t books[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d %s\n", books[i].id, books[i].price, books[i].title);
    }
}

int main() {
    book_t books[6] = {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300,  "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550,  "Killers of the Flower Moon"},
        {5, 870,  "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    // 建立結構儲存書籍資料到二進位檔案 Book.bin
    FILE *fp = fopen("Book.bin", "wb");
    if (fp == NULL) {
        return 1;
    }
    fwrite(books, sizeof(book_t), 6, fp);
    fclose(fp);

    // 計算總價與輸出書籍資料至螢幕
    total_price(books, 6);
    list_books(books, 6);

    return 0;
}
