operating system

Hệ điều hành Windows, Ubuntu, hay các Linux distros của Raspberry hoặc là Beaglebone.
Tải file .iso của hệ điều hành. Format lại bộ nhớ cần cài đặt. Load vào và bắt đầu tiến hành cài đặt.
…


bài hướng dẫn tạo 1 file hệ điều hành của anh Lý icviet:
1. phân vùng lại … cho thẻ SD: dev/sda,.. dev/sdb…
2. biên dịch … ( chayj với option -j4 ). bằng cross-compiler cho board đích ( arm-gnu for ex )
3. root-file system.
4. bootloader ( u-boot )
5. git to clone the Linux repository from  Linus Tovalds
