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

// 2. Hàm quy đổi điện năng từ Wh sang kWh (Đã đổi tên theo đúng test case)
double doiWhSangKwh(double wh) {
    return(double) wh / 1000; // Sử dụng 1000.0 để ép kiểu số thực
}

// 3. Hàm tính cước phí
double tinhCuocPhi(double dienNangKwh, double donGia) {
    return dienNangKwh * donGia;
}

int main() {
    double whDaNap;
    double kwh;
    double donGia = 2500.0; 
    double tongCuocPhi;

    whDaNap = nhapSanLuongWh();

    // Gọi đúng tên hàm mới
    kwh = doiWhSangKwh(whDaNap);

    tongCuocPhi = tinhCuocPhi(kwh, donGia);

    printf("San luong da nap: %.2f Wh\n", whDaNap);
    printf("Dien nang quy doi: %.2f kWh\n", kwh);
    printf("Tong cuoc phi: %.2f VND\n", tongCuocPhi);

    return 0;
}
