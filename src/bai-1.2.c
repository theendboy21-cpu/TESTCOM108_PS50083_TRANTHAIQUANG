#include <stdio.h>

double nhapSanLuongWh() {
    double wh;
    do {
        printf("Nhap san luong da nap (Wh): ");
        scanf("%lf", &wh);

        if (wh <= 0) {
            printf("Loi: Gia tri phai lon hon 0. Vui long nhap lai.\n");
        }
    } while (wh <= 0); 

    return wh;
}


double doiWhSangKwh(double wh) {
    return wh / 1000.0; 
}

double tinhCuocPhi(double dienNangKwh, double donGia) {
    return dienNangKwh * donGia;
}

int main() {

    double whDaNap;
    double kwh;
    double donGia = 2500.0;
    double tongCuocPhi;

    whDaNap = nhapSanLuongWh();

    kwh = doiWhSangKwh(whDaNap);

    tongCuocPhi = tinhCuocPhi(kwh, donGia);

    // In ra màn hình kết quả
    printf("San luong da nap: %.2f Wh\n", whDaNap);
    printf("Dien nang quy doi: %.2f kWh\n", kwh);
    printf("Tong cuoc phi: %.2f VND\n", tongCuocPhi);

    return 0;
}
