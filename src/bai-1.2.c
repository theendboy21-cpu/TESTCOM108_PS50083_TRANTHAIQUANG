#include <stdio.h>

// 1. Hàm kiểm định sản lượng (đơn vị: Wh)
// Sử dụng vòng lặp do...while: chỉ chấp nhận giá trị Wh > 0.
double nhapSanLuongWh() {
    double wh;
    do {
        printf("Nhap san luong da nap (Wh): ");
        scanf("%lf", &wh);

        if (wh <= 0) {
            printf("Loi: Gia tri phai lon hon 0. Vui long nhap lai.\n");
        }
    } while (wh <= 0); // Tiếp tục lặp nếu giá trị <= 0

    return wh;
}

// 2. Hàm quy đổi điện năng từ Wh sang kWh
// 1 kWh = 1000 Wh
double quyDoiWhToKwh(double wh) {
    return wh / 1000.0;
}

// 3. Hàm tính cước phí
// Tham số: dienNangKwh (số kWh đã nạp), donGia (đơn giá trên mỗi kWh)
double tinhCuocPhi(double dienNangKwh, double donGia) {
    return dienNangKwh * donGia;
}

// Hàm main
int main() {
    // Biến lưu trữ dữ liệu
    double whDaNap;
    double kwh;
    double donGia = 2500.0; // Ví dụ: Đơn giá là 2500 VND/kWh
    double tongCuocPhi;

    // Gọi hàm kiểm định sản lượng
    whDaNap = nhapSanLuongWh();

    // Gọi hàm quy đổi điện năng
    kwh = quyDoiWhToKwh(whDaNap);

    // Gọi hàm tính cước phí
    tongCuocPhi = tinhCuocPhi(kwh, donGia);

    // In ra màn hình
    // Wh đã sạc (số nguyên hoặc số thực tùy ý, ở đây in số thực gốc)
    printf("San luong da nap: %.2f Wh\n", whDaNap);
    
    // kWh (2 chữ số thập phân)
    printf("Dien nang quy doi: %.2f kWh\n", kwh);
    
    // Tổng cước phí
    printf("Tong cuoc phi: %.2f VND\n", tongCuocPhi);

    return 0;
}