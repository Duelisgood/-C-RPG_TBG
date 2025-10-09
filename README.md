# 🚀 Petualangan RPG Berbasis Teks dengan Bahasa C 🚀

Selamat datang di laporan (tidak begitu) formal dari proyek pembelajaran pribadiku! Proyek ini adalah sebuah game **RPG berbasis teks** sederhana yang dibangun sepenuhnya menggunakan bahasa C. Tujuannya bukan untuk menciptakan game terhebat di dunia, melainkan untuk belajar, bereksperimen, dan yang paling penting, bersenang-senang dengan bahasa C. 🎮

---

## 📖 Latar Belakang Proyek

Semuanya berawal dari kecintaanku pada game RPG klasik dan keinginanku untuk mendalami bahasa C lebih jauh. Aku ingin menciptakan sesuatu yang interaktif dan menantang, dan sebuah game RPG berbasis teks sepertinya adalah pilihan yang sempurna. Proyek ini menjadi ajang bagiku untuk mempraktikkan konsep-konsep C yang telah kupelajari dalam sebuah proyek yang nyata dan menyenangkan.

---

## 🎮 Cara Kerja Game

Game ini berjalan sepenuhnya di dalam konsol atau terminal. Kamu akan berinteraksi dengan dunia game melalui perintah teks. Berikut adalah alur dasar permainannya:

1.  **Memulai Petualangan:**
    * *Compile* dan *jalankan* file `.c` utama dari proyek ini. Kamu bisa menggunakan *compiler* seperti GCC:
        ```bash
        # Compile program
        gcc main.c -o game

        # Jalankan game
        ./game
        ```

2.  **Pembuatan Karakter:**
    * Di awal permainan, kamu akan diminta untuk membuat karaktermu sendiri. Kamu bisa memasukkan nama dan mungkin memilih *class* atau status awal.

3.  **Menjelajahi Dunia:**
    * Kamu akan disajikan dengan deskripsi lokasi dan pilihan tindakan. Kamu bisa bergerak, berinteraksi dengan objek, atau berbicara dengan NPC (jika ada) dengan mengetikkan perintah sederhana.

4.  **Sistem Pertarungan (⚔️ *Combat*):**
    * Ketika bertemu musuh, permainan akan beralih ke mode pertarungan. Pertarungan berjalan secara *turn-based* atau berbasis giliran. Kamu bisa memilih untuk menyerang, bertahan, atau menggunakan *item*.

5.  **Tujuan Akhir:**
    * Ikuti alur cerita, kalahkan musuh, dan selesaikan misi yang ada untuk menamatkan game.

---

## 🧠 Konsep Bahasa C yang Dipelajari dan Diterapkan

Proyek ini menjadi tempatku untuk mengaplikasikan berbagai konsep fundamental dalam bahasa C. Berikut adalah beberapa di antaranya:

* **`struct`:** Konsep ini sangat penting untuk mendefinisikan objek-objek dalam game, seperti:
    * `struct Player`: Untuk menyimpan semua data tentang pemain (nama, HP, *attack*, *defense*, *inventory*).
    * `struct Enemy`: Untuk menyimpan data musuh.
    * `struct Item`: Untuk mendefinisikan *item-item* yang ada di dalam game.

* **Pointers (`*`):** *Pointers* banyak digunakan untuk mengelola memori dan data secara efisien, terutama saat menangani struktur data yang kompleks atau saat melewatkan data ke fungsi tanpa harus menyalin seluruh isinya.

* **Arrays & Strings:** Tentu saja, sebagai game berbasis teks, *arrays* dan *string* adalah tulang punggung dari game ini. Semua deskripsi, dialog, dan input dari pemain dikelola menggunakan *array of characters*.

* **Functions:** Aku memecah logika game ke dalam fungsi-fungsi yang lebih kecil agar kode lebih terstruktur dan mudah dibaca. Contohnya, ada fungsi terpisah untuk `startGame()`, `createCharacter()`, `displayStats()`, `battle()`, dan sebagainya.

* **File I/O (Input/Output):** Aku mengimplementasikan fitur *save* dan *load* game. Ini adalah bagian yang menantang di mana aku belajar cara:
    * Menggunakan `fopen()`, `fprintf()`, dan `fclose()` untuk menulis data permainan (seperti status pemain) ke dalam sebuah file.
    * Menggunakan `fscanf()` atau `fgets()` untuk membaca data dari file tersebut dan mengembalikannya ke dalam game.

* **Logika Kondisional (`if-else`, `switch-case`):** Logika game sangat bergantung pada ini. Misalnya, untuk menentukan hasil dari pertarungan, percabangan cerita, atau validasi input dari pemain.

* **Loops (`while`, `for`):** *Game loop* utama yang membuat permainan terus berjalan dibuat menggunakan `while loop`. *Loops* juga digunakan dalam sistem pertarungan dan untuk mengelola *inventory*.

---

## 📂 Desain dan Struktur Kode

Aku mencoba untuk menjaga agar struktur kode tetap rapi dan terorganisir. Berikut adalah gambaran kasar dari struktur direktori dan file:

*(Catatan: Kamu bisa menyesuaikan struktur ini sesuai dengan proyekmu)*

/C-RPG_TBG
|
|-- main.c         // File utama yang berisi game loop dan fungsi-fungsi inti
|-- player.h       // Header untuk deklarasi struct dan fungsi terkait pemain
|-- combat.c       // Logika untuk sistem pertarungan
|-- savegame.dat   // Contoh file save (dihasilkan oleh game)
|-- README.md      // Kamu sedang membacanya :)

Tentu, ini kode Markdown-nya. Kamu bisa langsung salin-tempel kode di bawah ini ke dalam file `README.md` di repositori GitHub-mu.

````markdown
# 🚀 Laporan Proyek: Petualangan RPG Berbasis Teks dengan Bahasa C 🚀

Selamat datang di laporan (tidak begitu) formal dari proyek pembelajaran pribadiku! Proyek ini adalah sebuah game **RPG berbasis teks** sederhana yang dibangun sepenuhnya menggunakan bahasa C. Tujuannya bukan untuk menciptakan game terhebat di dunia, melainkan untuk belajar, bereksperimen, dan yang paling penting, bersenang-senang dengan bahasa C. 🎮

---

## 📖 Latar Belakang Proyek

Semuanya berawal dari kecintaanku pada game RPG klasik dan keinginanku untuk mendalami bahasa C lebih jauh. Aku ingin menciptakan sesuatu yang interaktif dan menantang, dan sebuah game RPG berbasis teks sepertinya adalah pilihan yang sempurna. Proyek ini menjadi ajang bagiku untuk mempraktikkan konsep-konsep C yang telah kupelajari dalam sebuah proyek yang nyata dan menyenangkan.

---

## 🎮 Cara Kerja Game

Game ini berjalan sepenuhnya di dalam konsol atau terminal. Kamu akan berinteraksi dengan dunia game melalui perintah teks. Berikut adalah alur dasar permainannya:

1.  **Memulai Petualangan:**
    * *Compile* dan *jalankan* file `.c` utama dari proyek ini. Kamu bisa menggunakan *compiler* seperti GCC:
        ```bash
        # Compile program
        gcc main.c -o game

        # Jalankan game
        ./game
        ```

2.  **Pembuatan Karakter:**
    * Di awal permainan, kamu akan diminta untuk membuat karaktermu sendiri. Kamu bisa memasukkan nama dan mungkin memilih *class* atau status awal.

3.  **Menjelajahi Dunia:**
    * Kamu akan disajikan dengan deskripsi lokasi dan pilihan tindakan. Kamu bisa bergerak, berinteraksi dengan objek, atau berbicara dengan NPC (jika ada) dengan mengetikkan perintah sederhana.

4.  **Sistem Pertarungan (⚔️ *Combat*):**
    * Ketika bertemu musuh, permainan akan beralih ke mode pertarungan. Pertarungan berjalan secara *turn-based* atau berbasis giliran. Kamu bisa memilih untuk menyerang, bertahan, atau menggunakan *item*.

5.  **Tujuan Akhir:**
    * Ikuti alur cerita, kalahkan musuh, dan selesaikan misi yang ada untuk menamatkan game.

---

## 🧠 Konsep Bahasa C yang Dipelajari dan Diterapkan

Proyek ini menjadi tempatku untuk mengaplikasikan berbagai konsep fundamental dalam bahasa C. Berikut adalah beberapa di antaranya:

* **`struct`:** Konsep ini sangat penting untuk mendefinisikan objek-objek dalam game, seperti:
    * `struct Player`: Untuk menyimpan semua data tentang pemain (nama, HP, *attack*, *defense*, *inventory*).
    * `struct Enemy`: Untuk menyimpan data musuh.
    * `struct Item`: Untuk mendefinisikan *item-item* yang ada di dalam game.

* **Pointers (`*`):** *Pointers* banyak digunakan untuk mengelola memori dan data secara efisien, terutama saat menangani struktur data yang kompleks atau saat melewatkan data ke fungsi tanpa harus menyalin seluruh isinya.

* **Arrays & Strings:** Tentu saja, sebagai game berbasis teks, *arrays* dan *string* adalah tulang punggung dari game ini. Semua deskripsi, dialog, dan input dari pemain dikelola menggunakan *array of characters*.

* **Functions:** Aku memecah logika game ke dalam fungsi-fungsi yang lebih kecil agar kode lebih terstruktur dan mudah dibaca. Contohnya, ada fungsi terpisah untuk `startGame()`, `createCharacter()`, `displayStats()`, `battle()`, dan sebagainya.

* **File I/O (Input/Output):** Aku mengimplementasikan fitur *save* dan *load* game. Ini adalah bagian yang menantang di mana aku belajar cara:
    * Menggunakan `fopen()`, `fprintf()`, dan `fclose()` untuk menulis data permainan (seperti status pemain) ke dalam sebuah file.
    * Menggunakan `fscanf()` atau `fgets()` untuk membaca data dari file tersebut dan mengembalikannya ke dalam game.

* **Logika Kondisional (`if-else`, `switch-case`):** Logika game sangat bergantung pada ini. Misalnya, untuk menentukan hasil dari pertarungan, percabangan cerita, atau validasi input dari pemain.

* **Loops (`while`, `for`):** *Game loop* utama yang membuat permainan terus berjalan dibuat menggunakan `while loop`. *Loops* juga digunakan dalam sistem pertarungan dan untuk mengelola *inventory*.

---

## 📂 Desain dan Struktur Kode

Aku mencoba untuk menjaga agar struktur kode tetap rapi dan terorganisir. Berikut adalah gambaran kasar dari struktur direktori dan file:

*(Catatan: Kamu bisa menyesuaikan struktur ini sesuai dengan proyekmu)*

---

## ✨ Penutup

Proyek ini adalah sebuah perjalanan belajar yang sangat berharga. Meskipun hasilnya mungkin jauh dari sempurna, aku sangat bangga dengan apa yang telah berhasil aku capai. Ada banyak sekali tantangan dan *bug* di sepanjang jalan, tetapi setiap masalah yang berhasil dipecahkan memberikanku pemahaman yang lebih dalam tentang bahasa C.

Terima kasih telah melihat proyekku!

**- Duelisgood**
```
