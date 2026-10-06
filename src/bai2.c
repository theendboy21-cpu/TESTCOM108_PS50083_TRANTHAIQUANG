#include <stdio.h>

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
int thanhToanHoaDon(float *soDuVi, float tongTien, float tyLeHoan, float *tienHoan);

#ifndef UNIT_TEST
int main() {
    float soDu = 500000.0;
    float hoaDon, tyLe;
    float tienDuocHoan = 0.0;

    printf("So du vi hien tai: %.2f VND\n", soDu);
    printf("Nhap so tien hoa don: ");
    scanf("%f", &hoaDon);
    printf("Nhap ty le cashback (%%): ");
    scanf("%f", &tyLe);

    int trangThai = thanhToanHoaDon(&soDu, hoaDon, tyLe, &tienDuocHoan);

    if (trangThai == 1) {
        printf("\n>> Giao dich THANH CONG!");
        printf("\nTien cashback nhan ve: %.2f VND", tienDuocHoan);
        printf("\nSo du vi sau cung: %.2f VND\n", soDu);
    } else {
        printf("\n>> Giao dich THAT BAI (So du khong du)!");
        printf("\nSo du giu nguyen: %.2f VND\n", soDu);
    }

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
int thanhToanHoaDon(float *soDuVi, float tongTien, float tyLeHoan, float *tienHoan) {
    // TODO: Viết code thanh toán và cập nhật số dư, tiền hoàn (dùng con trỏ)
    // Trả về 1 nếu thành công, 0 nếu thất bại (không đủ tiền)
    
    // Bước 1: Kiểm tra xem số dư tài khoản có đủ để trả tiền hóa đơn không
    if (*soDuVi < tongTien) {
        return 0; // Thất bại
    }

    // Bước 2: Thực hiện trừ tiền hóa đơn khỏi số dư ví
    *soDuVi = *soDuVi - tongTien;

    // Bước 3: Tính toán số tiền được hoàn lại dựa vào tỷ lệ % cashback
    *tienHoan = tongTien * (tyLeHoan / 100.0f);

    // Bước 4: Cộng số tiền được hoàn ngược lại vào số dư ví
    *soDuVi = *soDuVi + *tienHoan;

    return 1; // Thành công
}
