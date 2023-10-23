"C:\Keil_v5\ARM\ARMCLANG\bin\armclang.exe" --target=arm-arm-none-eabi -mcpu=cortex-m4 -c -I./ ./main.c -o ./main.o
"C:\Keil_v5\ARM\ARMCLANG\bin\armclang.exe" --target=arm-arm-none-eabi -mcpu=cortex-m4 -c -I./ ./lib.c -o ./lib.o

"C:\Keil_v5\ARM\ARMCLANG\bin\armlink.exe" --cpu=cortex-m4 --verbose --map --info=sizes,unused,unusedsymbols --symbols --load_addr_map_info --entry=main --list=Infor.map ./main.o ./lib.o -o product.axf

"C:\Keil_v5\ARM\ARMCLANG\bin\fromelf.exe" --text -c product.axf -o disAssembly.txt
"C:\Keil_v5\ARM\ARMCLANG\bin\fromelf.exe" --text -d product.axf -o dataSection.txt
"C:\Keil_v5\ARM\ARMCLANG\bin\fromelf.exe" --text -s product.axf -o symbleTable.txt
"C:\Keil_v5\ARM\ARMCLANG\bin\fromelf.exe" --i32 product.axf -o product.hex