# Double_Linked_List_library
 
111上資料結構HW1

[作業說明網頁](https://hackmd.io/@chtsai/DSHW1)

---

建構一個 Double Linked List 的 library.

函式庫使用說明書.pdf的執行結果指令未分類檔案，在CMD打開根目錄打以下指令執行即可：

```
gcc -c -I./include ./src/dllSpec2022.c -o ./obj/dllSpec2022.o

ar -cr ./lib/libLinkedList.a ./obj/dllSpec2022.o

gcc -I./include ./src/main.c ./lib/libLinkedList.a -o ./bin/test.exe

cd bin
test.exe
```
